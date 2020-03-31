/*
 * udp.c - handle upd connections
 *
 * Copyright (C) 1999 Brad M. Garcia <garsh@home.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <syslog.h>
#include <string.h>
#include <time.h>
#include <assert.h>
#include "common.h"
#include "relay.h"
#include "cache.h"
#include "query.h"
#include "domnode.h"
#include "check.h"

#ifndef EXCLUDE_MASTER
#include "master.h"
#endif

#ifdef DNS_HIJACK
#include <linux/if_packet.h>
#include <linux/if.h>
#include <sys/ioctl.h>
#include <re865x.h>
#include <rtl8651_tblDrv.h>
#include <board.h> /* exported function prototypes */
extern romeCfgParam_t * pRomeCfgParam;

#endif

/*
 * dnssend()						22OCT99wzk
 *
 * Abstract: A small wrapper for send()/sendto().  If an error occurs a
 *           message is written to syslog.
 *
 * Returns:  The return code from sendto().
 */
static int udp_send(int sock, srvnode_t *srv, void *msg, int len)
{
    int	rc;
    time_t now = time(NULL);
          
    //printf("udp_send srv->addr = %s\n",	inet_ntoa(srv->addr.sin_addr));
    //printf("udp_send srv->real_addr = %s\n",	inet_ntoa(srv->realaddr.sin_addr));    
    rc = sendto(sock, msg, len, 0,
#ifndef DNS_HIJACK    
		(const struct sockaddr *) &srv->addr,    
#else		
		(const struct sockaddr *) &srv->realaddr,
#endif		
		sizeof(struct sockaddr_in));

    if (rc != len) {
#ifndef DNS_HIJACK     	
	log_msg(LOG_ERR, "sendto error: %s: ",
		inet_ntoa(srv->addr.sin_addr), strerror(errno));
#else
	log_msg(LOG_ERR, "sendto error: %s: ",
		inet_ntoa(srv->realaddr.sin_addr), strerror(errno));
#endif		
	
	return (rc);
    }
    if ((srv->send_time == 0)) srv->send_time = now;
    srv->send_count++;
    return (rc);
}

int send2current(query_t *q, void *msg, const int len) {
    /* If we have domains associated with our servers, send it to the
       appropriate server as determined by srvr */
  domnode_t *d;
  assert(q != NULL);
  assert(q->domain != NULL);

  d = q->domain;

  /*
  	patched by chenyl(2005/0202):

  	Dr. Edward found a DNRD's bug:

  		/bin/dnrd: udp.c: 75: send2current: Assertion `q->domain != ((void *)0)' failed.

  		DNRD crashed due to this bug.
  */
  
  if (d == NULL)
  {
  	return 0;
  }
  
  while ((d->current != NULL) && (udp_send(q->sock, d->current, msg, len) != len)) {
#ifndef DNS_HIJACK  	
    	if (reactivate_interval) deactivate_current(d);
#else    	
    	return -1;
#endif    	
  }
  if (d->current != NULL) {
    return len;
  } else return 0;
}


/*
 * handle_udprequest()
 *
 * This function handles udp DNS requests by either replying to them (if we
 * know the correct reply via master, caching, etc.), or forwarding them to
 * an appropriate DNS server.
 */
 #ifdef DNS_HIJACK //set to global to store

 static  unsigned long	lan_side_ip;
  static  unsigned long	lan_side_mask;

 #endif
query_t *udp_handle_request()
{
    unsigned           addr_len;
    int                len;

    struct sockaddr_in from_addr;
    int                fwd;
    domnode_t          *dptr;
    query_t *q, *prev;
    
    #ifdef DNS_HIJACK
    const int          maxsize = RAW_IP_MAXSIZE;
    static char        msg_raw_ip[RAW_IP_MAXSIZE+4]; // padd 00 01 00 01 4bytes 		
    static char        msg[UDP_MAXSIZE+4]; // padd 00 01 00 01 4bytes
	
    PETHERHDR	       pEther_hdr, pout_ether_hdr;
    PIPHDR	       pIp_hdr, pout_ip_hdr;
    PUDPHDR	       pUdp_hdr, pout_udp_hdr;
    PUDP_PSEUDO	       pudp_pseudo_header;
    UDPHDR		out_udp_hdr;
    UDP_PSEUDO		udp_pseudo_hdr;
    IPHDR		ip_hdr;
    ETHERHDR		ether_hdr;
    PPACKET_INFO	ppacket_info;
    PACKET_INFO		packet_info;
    char	       *udp_data;
    int		       i;
    int			send_len;
        
    unsigned long	lan_side_ip_masked;
    unsigned long     	source_masked;
    unsigned long	temp_source;
    unsigned long	temp_dest;
    

    
    int 		fd; 
    struct 		sockaddr_ll dest_ll;
    /*
     *  for packing ip header use
     */
    	int frag_flag=0;
	int old_len=0; 
	int left_len=0;
	int ret;
	 
    //assigned address to pointer      
    pout_udp_hdr = &out_udp_hdr;
    pudp_pseudo_header = &udp_pseudo_hdr;
    pout_ip_hdr = &ip_hdr;
    pout_ether_hdr = &ether_hdr;
    
    #else
    int 		i;
    const int          maxsize = UDP_MAXSIZE;
    static char        msg[UDP_MAXSIZE+4]; // padd 00 01 00 01 4bytes
    #endif
    
    /* Read in the message */
    addr_len = sizeof(struct sockaddr_in);
    
    #ifndef DNS_HIJACK
    len = recvfrom(isock, msg, maxsize, 0,
		   (struct sockaddr *)&from_addr, &addr_len);
    #else
    len = recvfrom(raw_lan_sd, msg_raw_ip, maxsize, 0,
		   (struct sockaddr *)&from_addr, &addr_len);
    #endif
    if (len < 0) {
	log_debug(1, "recvfrom error %s", strerror(errno));
	
	return NULL;
    }
     
     
#ifdef DNS_HIJACK    
    //printf("recv raw ip packet from lan side\n");
    /*
     *  What we recv here is raw socket from lan side
     */
          //3. strip ethernet header
     pEther_hdr = (PETHERHDR) (msg_raw_ip);
     
     if (pEther_hdr->h_proto != 0x0800)
     {

	return NULL;       
     }

     //1. catch destination port for UDP       
     pUdp_hdr = (PUDPHDR) (msg_raw_ip + 14 + 20); //shift 14 ether , 20 ip
          
     if (pUdp_hdr->dest_port != DNS_PORT) //we only
     {

	return NULL;     
     }
     
     //2. tear down raw packet to ip
     pIp_hdr = (PIPHDR) (msg_raw_ip + 14); //shift 14 bytes ether header     
     temp_source = pIp_hdr->saddr;
     temp_dest = pIp_hdr->daddr;
    
     
     //2.1 compare protocol
     if( pIp_hdr->protocol != UDP_PROTOCOL)
     {

	return NULL;
     }  
     
#if 0     
     //2.2. compare dest ip and source ip
     //lan side source must be network mask matched
     if (!getRomeCfgParamPtr(&pRomeCfgParam)) {
         //source_masked = temp_source >>8;
	 memcpy((char *)&lan_side_ip, (char *)pRomeCfgParam->ifCfgParam[1].ipAddr, sizeof(lan_side_ip));
	 memcpy((char *)&lan_side_mask, (char *)pRomeCfgParam->ifCfgParam[1].ipMask, sizeof(lan_side_mask));
	 
     	 releaseRomeCfgParamPtr(&pRomeCfgParam);
     	 
	 source_masked = temp_source & lan_side_mask;
	 lan_side_ip_masked = lan_side_ip & lan_side_mask;     	 
     	 	 
	 if( source_masked != lan_side_ip_masked)
	 {	 	
		return NULL;
	 }
     } 
#endif     
     
     //now confirm, copy temp to static one

     len = pUdp_hdr->len - sizeof(UDPHDR);
     if ((len < 0) || (len >= (RAW_IP_MAXSIZE - 28)))
     	return NULL;
                                
     udp_data = (char *) (msg_raw_ip + sizeof(ETHERHDR) + sizeof(IPHDR) + sizeof(UDPHDR)); //54 = 14 + 20 + 20
     
     //4. copy recv header contents to packet_info
     
     //4.1 Ethernet header;
         
     memcpy( &packet_info.ether_hdr.h_source, &pEther_hdr->h_source, ETH_ALEN);               
     memcpy( &packet_info.ether_hdr.h_dest, &pEther_hdr->h_dest, ETH_ALEN);     
     memcpy( &packet_info.ip_hdr.saddr, &pIp_hdr->saddr, 4);     
     memcpy( &packet_info.ip_hdr.daddr, &pIp_hdr->daddr, 4);          
     memcpy( &packet_info.udp_hdr.source_port, &pUdp_hdr->source_port, 2);     
     memcpy( &packet_info.udp_hdr.dest_port, &pUdp_hdr->dest_port, 2);       		   
     memcpy(&from_addr.sin_addr,  &packet_info.ip_hdr.saddr, 4);
     
     memcpy(msg , udp_data, len);
     
        	
#endif   //end of DNS_HIJACK   
    
    /* do some basic checking */
    if (check_query(msg, len) < 0) return NULL;
    
    
    /* Determine how query should be handled */
    if ((fwd = handle_query(&from_addr, msg, &len, &dptr)) < 0)
    {
      
      return NULL; /* if its bogus, just ignore it */
    }
    //printf("address of &qlist = %x qlist.next =%x\n", &qlist, qlist.next);
   
   
     
    /* If we already know the answer, send it and we're done */
    if (fwd == 0) {
        
    #ifndef DNS_HIJACK
	if (sendto(isock, msg, len, 0, (const struct sockaddr *)&from_addr,
		   addr_len) != len) {
	    log_debug(1, "sendto error %s", strerror(errno));
	}
    #else
        
	
	pout_udp_hdr->source_port = packet_info.udp_hdr.source_port;
	pout_udp_hdr->dest_port = packet_info.udp_hdr.dest_port;
	pout_udp_hdr->len = htons(len +  sizeof(UDPHDR));
	pout_udp_hdr->check = 0;
	
	
	pudp_pseudo_header->source_addr = packet_info.ip_hdr.daddr;	
	pudp_pseudo_header->dest_addr =	packet_info.ip_hdr.saddr;
	pudp_pseudo_header->mbz = 0; //must be zero
	pudp_pseudo_header->protocol = 17; //UDP, 0x11
	pudp_pseudo_header->length = len +  sizeof(UDPHDR);
	pudp_pseudo_header->checksum = ~udp_checksum( pout_udp_hdr, msg,
                                        htons(pout_udp_hdr->len) ); //1.real UDP header 2.real UDP data 3.real UDP length
		
        //refill udp header
	
	pout_udp_hdr->source_port = packet_info.udp_hdr.dest_port;	
	pout_udp_hdr->dest_port = packet_info.udp_hdr.source_port;
	pout_udp_hdr->len = len +  sizeof(UDPHDR);
	pout_udp_hdr->check = checksum(pudp_pseudo_header , sizeof(UDP_PSEUDO)); //1. pseudo header, pseudo header's size
	
#if 0	
	//refill ip header
	//a.compute the fragment
	old_len = left_len = len; //out udp data length	
	
	if (len > (ET_MAXLEN-sizeof(IPHDR))) {
        	len = ET_MAXLEN - sizeof(IPHDR);
        	frag_flag = 1;
    	}
    	left_len -= len;
#endif    	
	
	//c.compute checksum
	pout_ip_hdr->version = IP_VER4;
	pout_ip_hdr->ihl = 5; //always 5
	pout_ip_hdr->tos = 0; //service type, let default
	pout_ip_hdr->tot_len = htons(len + sizeof(UDPHDR) +sizeof(IPHDR)); //length udpdata + udp hdr + ip hdr
	pout_ip_hdr->ttl = 128; //DNS reply ttl
	pout_ip_hdr->id = htons(qid_get()); //reuse qid_get
	
	
	if (frag_flag)
		pout_ip_hdr->frag_off = htons(IP_FRAG_FLAG << 13);
	else
		pout_ip_hdr->frag_off = 0;
		
	pout_ip_hdr->protocol =UDP_PROTOCOL; //UDP 
	pout_ip_hdr->daddr = packet_info.ip_hdr.saddr;
	pout_ip_hdr->saddr = packet_info.ip_hdr.daddr;
	pout_ip_hdr->check = 0;
	pout_ip_hdr->check = checksum( pout_ip_hdr, sizeof(IPHDR));
	
	//refill ethernet header, let kernel do it      
	if ((fd = socket(PF_PACKET, SOCK_DGRAM, htons(ETH_P_IP))) < 0) {
		printf("send socket call failed:\n");
		return NULL;
	}
	
	
	 memset(&dest_ll, 0, sizeof(dest_ll));
	 dest_ll.sll_family = AF_PACKET;
	 dest_ll.sll_protocol = htons(ETH_P_IP);
	 dest_ll.sll_ifindex = getdevindex(raw_lan_sd, "eth1");
	 dest_ll.sll_halen = 6;
	
	 memcpy(dest_ll.sll_addr, packet_info.ether_hdr.h_source, 6);
	 
	 if (bind(fd, (struct sockaddr *)&dest_ll, sizeof(struct sockaddr_ll)) < 0) {
		printf("send bind call failed:\n");
		close(fd);
		return NULL;
	 }
		
	memset((char *)&msg_raw_ip, 0x00, sizeof(msg_raw_ip)); //clear msg_war_ip, and use this as send_buf
	
	//1.fill udp data
	memcpy((char *)&msg_raw_ip[28], msg ,len);
	//2.fill udp header
	memcpy((char *)&msg_raw_ip[20], pout_udp_hdr, sizeof(UDPHDR));
	//3.fill ip header
	memcpy((char *)&msg_raw_ip, pout_ip_hdr, sizeof(IPHDR));
	
	send_len = len +  sizeof(IPHDR) + sizeof(UDPHDR) ;
	
        //if (sendto(raw_lan_sd, msg_raw_ip, send_len, 0, (const struct sockaddr *)&from_addr,
	if (sendto(fd, msg_raw_ip, send_len, 0,(struct sockaddr *) &dest_ll,
		   sizeof(dest_ll)) < 0) {
	    log_debug(1, "sendto error %s", strerror(errno));
	   
	}
        
	
	close(fd);
		
    #endif //DNS_HIJACK
	return NULL;
    }
    

    /* dptr->current should never be NULL it is checked in handle_query */
    if ((dptr == NULL) || ((dptr->current) == NULL))    
   	return NULL;
    
    //    dnsquery_add(&from_addr, msg, len);
    // if (!send2current(dptr, msg, len)) {

    /* rewrite msg, get id and add to list*/
    
    #ifdef DNS_HIJACK
    if ((prev=query_add(dptr, dptr->current, &from_addr, msg, len, &packet_info)) == NULL){
    #else
    if ((prev=query_add(dptr, dptr->current, &from_addr, msg, len)) == NULL){
    #endif  
      /* of some reason we could not get any new queries. we have to
	 drop this packet */
      
      return NULL;
    }
    
  
    q = prev->next;

#ifndef DNS_HIJACK
    if (send2current(q, msg, len) > 0) {    
#else    	
    ret = send2current(q, msg, len);
    if (ret > 0) {
#endif    	
      /* add to query list etc etc */
      
      return q;
    } else {
#ifdef DNS_HIJACK    	
    	if (ret < 0) {
    		query_delete_next(prev);
    		return NULL;
    	}			 
#endif      
      /* we couldn't send the query */
#ifndef EXCLUDE_MASTER
      int	packetlen;
      char	packet[maxsize+4];

      /*
       * If we couldn't send the packet to our DNS servers,
       * perhaps the `network is unreachable', we tell the
       * client that we are unable to process his request
       * now.  This will show a `No address (etc.) records
       * available for host' in nslookup.  With this the
       * client won't wait hang around till he gets his
       * timeout.
       * For this feature dnrd has to run on the gateway
       * machine.
       */
      
      if ((packetlen = master_dontknow(msg, len, packet)) > 0) {
	query_delete_next(prev);
	return NULL;
	#ifndef DNS_HIJACK
	if (sendto(isock, msg, len, 0, (const struct sockaddr *)&from_addr,
		   addr_len) != len) {
	  log_debug(1, "sendto error %s", strerror(errno));
	#else
	if (sendto(fd, msg, send_len, 0, (struct sockaddr *) &dest_ll,
		   sizeof(dest_ll)) < 0) {
	  log_debug(1, "sendto error %s", strerror(errno));
	  
	  close(fd);
	#endif  
	  return NULL;
	}
      }
      #ifdef DNS_HIJACK
      close(fd);
      #endif
#endif
    }
    return q;
}

/*
 * dnsrecv()							22OCT99wzk
 *
 * Abstract: A small wrapper for recv()/recvfrom() with output of an
 *           error message if needed.
 *
 * Returns:  A positove number indicating of the bytes received, -1 on a
 *           recvfrom error and 0 if the received message is too large.
 */
static int reply_recv(query_t *q, void *msg, int len)
{
    int	rc, fromlen;
    struct sockaddr_in from;

    //printf("recv reply from %s\n", inet_ntoa(q->srv->addr.sin_addr));
    fromlen = sizeof(struct sockaddr_in);
    rc = recvfrom(q->sock, msg, len, 0,
		  (struct sockaddr *) &from, &fromlen);

    if (rc == -1) {
	log_msg(LOG_ERR, "recvfrom error: %s",
		inet_ntoa(q->srv->addr.sin_addr));
	
	return (-1);
    }
    else if (rc > len) {
	log_msg(LOG_NOTICE, "packet too large: %s",
		inet_ntoa(q->srv->addr.sin_addr));
	
	return (0);
    }
#ifndef DNS_HIJACK  
 
    else if (memcmp(&from.sin_addr, &q->srv->addr.sin_addr,
		    sizeof(from.sin_addr)) != 0) {
	log_msg(LOG_WARNING, "unexpected server: %s",
		inet_ntoa(from.sin_addr));
	
	return (0);
    }
#else
#if 0	
    else if (memcmp(&from.sin_addr, &q->srv->realaddr.sin_addr,
		    sizeof(from.sin_addr)) != 0) {
	log_msg(LOG_WARNING, "unexpected server: %s",
		inet_ntoa(from.sin_addr));
	return (0);		
    }
#endif    	
#endif    

    return (rc);
}

/*
 * handle_udpreply()
 *
 * This function handles udp DNS requests by either replying to them (if we
 * know the correct reply via master, caching, etc.), or forwarding them to
 * an appropriate DNS server.
 *
 * Note that the mached query is prev->next and not prev.
 */
void udp_handle_reply(query_t *prev)
{
  //    const int          maxsize = 512; /* According to RFC 1035 */
    static char        msg[UDP_MAXSIZE+4];
    int                len;
    unsigned           addr_len;
    query_t *q = prev->next;
   
    #ifdef DNS_HIJACK
    static char        	msg_raw_ip[RAW_IP_MAXSIZE+4]; // padd 00 01 00 01 4bytes 
    static char		udp_data[UDP_MAXSIZE+4];
    PETHERHDR	       pEther_hdr, pout_ether_hdr;
    PIPHDR	       pIp_hdr, pout_ip_hdr;
    PUDPHDR	       pUdp_hdr, pout_udp_hdr;
    PUDP_PSEUDO	       pudp_pseudo_header;
    UDPHDR		out_udp_hdr;
    UDP_PSEUDO		udp_pseudo_hdr;
    IPHDR		ip_hdr;
    ETHERHDR		ether_hdr;
    
    int			i;
    int			send_len;

    
    int 		fd; 
    struct 		sockaddr_ll dest_ll;
    	    	    
    /*
     *  for packing ip header use
     */
    	int frag_flag=0;
	int old_len=0; 
	int left_len=0;
	
	 
    //assigned address to pointer      
    pout_udp_hdr = &out_udp_hdr;
    pudp_pseudo_header = &udp_pseudo_hdr;
    pout_ip_hdr = &ip_hdr;
    pout_ether_hdr = &ether_hdr;
    
    #endif
    
    log_debug(3, "handling socket %i", q->sock);
    
    if ((len = reply_recv(q, msg, UDP_MAXSIZE)) < 0)
      {
	log_debug(1, "dnsrecv failed: %i", len);
	
	query_delete_next(prev);
	return; /* recv error */
      }
     
     
    /* do basic checking */
    if (check_reply(q->srv, msg, len) < 0) {
      log_debug(1, "check_reply failed");
      
      query_delete_next(prev);
      return;
    }

    if (opt_debug) {
	char buf[256];
	sprintf_cname(&msg[12], len-12, buf, 256);
	log_debug(3, "Received DNS reply for \%s\n", buf);
    	
    }

    dump_dnspacket("reply", msg, len);
    addr_len = sizeof(struct sockaddr_in);

    #ifdef DNS_HIJACK
    if (q->domain != NULL) {
    /*
     *  packing packet with UDP header
     */

        *((unsigned short *)msg) = q->client_qid;    
        
	pout_udp_hdr->source_port = q->udp_hdr.dest_port;	
	pout_udp_hdr->dest_port = q->udp_hdr.source_port;
	pout_udp_hdr->len = htons(len +  sizeof(UDPHDR));
	pout_udp_hdr->check = 0;
	
	//caculate udp checksum
	
	pudp_pseudo_header->source_addr = q->ip_hdr.daddr;
	pudp_pseudo_header->dest_addr = q->ip_hdr.saddr;
	pudp_pseudo_header->mbz = 0; //must be zero
	pudp_pseudo_header->protocol = 0x11; //UDP
	pudp_pseudo_header->length = len +  sizeof(UDPHDR);
	pudp_pseudo_header->checksum = ~udp_checksum( pout_udp_hdr, msg,
                                        htons(pout_udp_hdr->len) ); //1.real UDP header 2.real UDP data 3.real UDP length

	//refill udp	
	pout_udp_hdr->source_port = q->udp_hdr.dest_port;	
	pout_udp_hdr->dest_port = q->udp_hdr.source_port;
	pout_udp_hdr->len = len +  sizeof(UDPHDR);
	pout_udp_hdr->check = checksum(pudp_pseudo_header , sizeof(UDP_PSEUDO)); //1. pseudo header, pseudo header's size

#if 0						
	//refill ip header
	//a.compute the fragment
	old_len = left_len = len; //out udp data length
	
	if (len > (ET_MAXLEN-sizeof(IPHDR))) {
        	len = ET_MAXLEN - sizeof(IPHDR);
        	frag_flag = 1;
    	}
    	left_len -= len;
#endif
	
	//c.compute checksum
	pout_ip_hdr->version = IP_VER4;
	pout_ip_hdr->ihl = 5; //always 5
	pout_ip_hdr->tos = 0; //service type, let default
	pout_ip_hdr->tot_len = htons(len + sizeof(UDPHDR) + sizeof(IPHDR)); //length udpdata + udp hdr + ip hdr
	pout_ip_hdr->ttl = 128; //DNS reply ttl
	pout_ip_hdr->id = htons(qid_get());
	
	
	if (frag_flag)
		pout_ip_hdr->frag_off = htons(IP_FRAG_FLAG << 13);
	else
		pout_ip_hdr->frag_off = 0;
		
	pout_ip_hdr->protocol =UDP_PROTOCOL; //UDP 

	pout_ip_hdr->daddr =  q->ip_hdr.saddr;
	pout_ip_hdr->saddr =  q->ip_hdr.daddr;	
	pout_ip_hdr->check = 0;
	pout_ip_hdr->check = checksum( pout_ip_hdr, sizeof(IPHDR));
	
	//refill ethernet header, let kernel do it
	if ((fd = socket(PF_PACKET, SOCK_DGRAM, htons(ETH_P_IP))) < 0) {		
		goto exit_reply_send;		
	}
	
	
	 memset(&dest_ll, 0, sizeof(dest_ll));
	 dest_ll.sll_family = AF_PACKET;
	 dest_ll.sll_protocol = htons(ETH_P_IP);
	 dest_ll.sll_ifindex = getdevindex(raw_lan_sd, "eth1");
	 dest_ll.sll_halen = 6;
	 memcpy(dest_ll.sll_addr, q->ether_hdr.h_source, 6);
	
	 if (bind(fd, (struct sockaddr *)&dest_ll, sizeof(struct sockaddr_ll)) < 0) {
		//printf("send bind call failed:\n");
		close(fd);
		goto exit_reply_send;
	 }
	
						
	memset((char *)&msg_raw_ip, 0x00, sizeof(msg_raw_ip)); //clear msg_war_ip, and use this as send_buf
	//1.fill udp data
	memcpy((char *)&msg_raw_ip[28], msg ,len);
	//2.fill udp header
	memcpy((char *)&msg_raw_ip[20], pout_udp_hdr, sizeof(UDPHDR));
	//3.fill ip header
	memcpy((char *)&msg_raw_ip, pout_ip_hdr, sizeof(IPHDR));

	send_len = len +  sizeof(IPHDR) + sizeof(UDPHDR) ;
    }
     
    #endif
    /* was this a dummy reactivate query? */
    if (q->domain != NULL) {
      /* no, lets cache the reply and send to client */
      cache_dnspacket(msg, len, q->srv);

      /* set the client qid */
      *((unsigned short *)msg) = q->client_qid;
      log_debug(3, "Forwarding the reply to the host %s",
		inet_ntoa(q->client.sin_addr));

      #ifndef DNS_HIJACK		
      if (sendto(isock, msg, len, 0,
		 (const struct sockaddr *)&q->client,
		 addr_len) != len) {
      
      #else
      
      if (sendto(fd, msg_raw_ip, send_len, 0,
		 (struct sockaddr *) &dest_ll,
		 sizeof(dest_ll)) < 0 ) {
      #endif
     
	log_debug(1, "sendto error %s", strerror(errno));
        
	//#ifdef DNS_HIJACK
	//close(fd);
	//#endif
      }
      	#ifdef DNS_HIJACK
	close(fd);
	#endif
	
    } else {
      log_debug(2, "We got a reactivation dummy reply. Cool!");
      
    }
exit_reply_send:    
      
    /* this server is obviously alive, we reset the counters */
    q->srv->send_time = 0;
    if (q->srv->inactive) log_debug(1, "Reactivating server %s",
				 inet_ntoa(q->srv->addr.sin_addr));
    q->srv->inactive = 0;
    /* remove query from list and destroy it */
    query_delete_next(prev);
    
}


/* send a dummy packet to a deactivated server to check if its back*/
int udp_send_dummy(srvnode_t *s) {
  static unsigned char dnsbuf[] = {
  /* HEADER */
    /* will this work on a big endian system? */
    0x00, 0x00, /* ID */
    0x00, 0x00, /* QR|OC|AA|TC|RD -  RA|Z|RCODE  */
    0x00, 0x01, /* QDCOUNT */
    0x00, 0x00, /* ANCOUNT */
    0x00, 0x00, /* NSCOUNT */
    0x00, 0x00, /* ARCOUNT */
    
    /* QNAME */
    9, 'l','o','c','a','l','h','o','s','t',0,
    /* QTYPE */
    0x00,0x01,   /* A record */
    
    /* QCLASS */
    0x00,0x01   /* IN */
  };
  query_t *q;
  struct sockaddr_in srcaddr;
#ifdef DNS_HIJACK  
  query_t *prev;
#endif  

  /* should not happen */
  assert(s != NULL);
  //printf("udp_send_dummy\n");
  if ((q=query_add(NULL, s, &srcaddr, dnsbuf, sizeof(dnsbuf), NULL)) != NULL) {
    int rc;

#ifdef DNS_HIJACK
    prev = q;
#endif    	    
    q = q->next; /* query add returned the query 1 before in list */
    /* don't let those queries live too long */
    q->ttl = reactivate_interval;
    memset(&srcaddr, 0, sizeof(srcaddr));
    log_debug(2, "Sending dummy id=%i to %s", ((unsigned short *)dnsbuf)[0], 
	      inet_ntoa(s->addr.sin_addr));
    /*  return dnssend(s, &dnsbuf, sizeof(dnsbuf)); */
    rc=udp_send(q->sock, s, dnsbuf, sizeof(dnsbuf));
    ((unsigned short *)dnsbuf)[0]++;
#ifdef DNS_HIJACK    
    if (rc != sizeof(dnsbuf)) {
    	query_delete_next(prev);    	
    }		
#endif    
    return rc;
  }
  return -1;
}
