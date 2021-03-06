/*
 * common.h
 *
 * This file contains definitions useful in all sorts of places.
 *
 * Copyright (C) 1998 Brad M. Garcia <garsh@home.com>
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

#ifndef _DNRD_COMMON_H_
#define _DNRD_COMMON_H_

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <syslog.h>
#include <semaphore.h>
#include "domnode.h"

/* default chroot path. this might be redefined in compile time */ 
#ifndef DNRD_ROOT
#define DNRD_ROOT "/usr/local/etc/dnrd"
#endif 

#ifndef CONFIG_FILE
#define CONFIG_FILE "dnrd.conf"
#endif

/* Set the default timeout value for select in seconds */
#ifndef SELECT_TIMEOUT
#define SELECT_TIMEOUT 1
#endif

/* Set the default timeout value for forward DNS. If we get no
 * response from a DNS server within forward_timeout, deactivate the
 * server.  note that if select_timeout is greater than this, the
 * forward timeout *might* increase to select_timeout. This value
 * should be >= SELECT_TIMEOUT
 */
/* 12 seems to be a good value under heavy load... */
#ifndef FORWARD_TIMEOUT
#define FORWARD_TIMEOUT 12
#endif

/*
	current dnrd version
*/
#define PACKAGE_VERSION	"2.17.2"


/* not used yet */
#ifndef FORWARD_RETRIES
#define FORWARD_RETRIES 5
#endif

/* only check if any server are to be reactivated every
 * REACTIVATE_INTERVAL seconds
 */
#define REACTIVATE_INTERVAL 10

struct dnssrv_t {
  int                    sock;      /* for communication with server */
  struct sockaddr_in     addr;      /* IP address of server */
  char*                  domain;    /* optional domain to match.  Set to
					 zero for a default server */
  
};


extern const char*         version;   /* the version number for this program */
extern const char*         progname;  /* the name of this program */
extern int                 opt_debug; /* debugging option */
extern const char*         pid_file; /* File containing current daemon's PID */
extern const char*         serv_file; /* File containing current daemon's server list */
extern int                 isock;     /* for communication with clients */
extern int                 tcpsock;   /* same as isock, but for tcp requests */
extern int                 select_timeout; /* select timeout in seconds */
extern int                 forward_timeout; /* timeout for forward DNS */
extern struct sockaddr_in  recv_addr; /* address on which we receive queries */
extern uid_t               daemonuid; /* to switch to once daemonised */
extern gid_t               daemongid; /* to switch to once daemonised */
extern int                 gotterminal;
extern char		   master_param[200];
extern sem_t               dnrd_sem;  /* Used for all thread synchronization */

extern char                dnrd_root[512];
extern char                config_file[];
extern domnode_t           *domain_list;

extern int                 reactivate_interval;
extern int                 ignore_inactive_cache_hits; 
extern int			load_balance;

extern int max_sockets;
extern int maxsock;
extern fd_set fdmaster;

#ifdef DNS_HIJACK
extern int		raw_lan_sd;
extern int		raw_wan_sd;
#endif

/* kill any currently running copies of dnrd */
int kill_current();

#ifndef EMBED
/* print messages to stderr or syslog */
void log_msg(int type, const char *fmt, ...);
/* same, but only if debugging is turned on */
void log_debug(int level, const char *fmt, ...);
#else
#define log_msg(type,fmt,...)   do{}while(0)

#define log_debug(level,fmt,...)   do{}while(0)
#endif

#ifdef USERAPP_NOMMU
/* cleanup eveything */
void cleanall();

/* remove pid/servlist file */
void rmFile();
#endif

/* cleanup everything and exit */
void cleanexit(int status);

/* Reads in the domain name as a string, allocates space for the CNAME
   version of it */
char* make_cname(const char *text, const int maxlen);
void sprintf_cname(const char *cname, int namesize, char *buf, int bufsize);

char *cname2asc(const char *cname);


/* Dumping DNS packets */
int dump_dnspacket(char *type, unsigned char *packet, int len);

/* parse server file and reset server list */
void parse_serfile(void);

#ifdef DNS_HIJACK
int open_fd(char *intf);

int getdevindex(int sock, char *name);		

unsigned short udp_checksum( void *hdt_ptr, void *ptr, int len);

unsigned short checksum( void *ptr, int len);
/*
 *  Ethernet structure defined here
 */
//Moved from <linux/if_ether.h>
/*
 *	IEEE 802.3 Ethernet magic constants.  The frame sizes omit the preamble
 *	and FCS/CRC (frame check sequence). 
 */

#define ETH_ALEN	6		/* Octets in one ethernet addr	 */
#define ETH_HLEN	14		/* Total octets in header.	 */
#define ETH_ZLEN	60		/* Min. octets in frame sans FCS */
#define ETH_DATA_LEN	1500		/* Max. octets in payload	 */
#define ETH_FRAME_LEN	1514		/* Max. octets in frame sans FCS */

/*
 *	These are the defined Ethernet Protocol ID's.
 */

#define ETH_P_LOOP	0x0060		/* Ethernet Loopback packet	*/
#define ETH_P_PUP	0x0200		/* Xerox PUP packet		*/
#define ETH_P_PUPAT	0x0201		/* Xerox PUP Addr Trans packet	*/
#define ETH_P_IP	0x0800		/* Internet Protocol packet	*/
#define ETH_P_X25	0x0805		/* CCITT X.25			*/
#define ETH_P_ARP	0x0806		/* Address Resolution packet	*/
#define	ETH_P_BPQ	0x08FF		/* G8BPQ AX.25 Ethernet Packet	[ NOT AN OFFICIALLY REGISTERED ID ] */
#define ETH_P_IEEEPUP	0x0a00		/* Xerox IEEE802.3 PUP packet */
#define ETH_P_IEEEPUPAT	0x0a01		/* Xerox IEEE802.3 PUP Addr Trans packet */
#define ETH_P_DEC       0x6000          /* DEC Assigned proto           */
#define ETH_P_DNA_DL    0x6001          /* DEC DNA Dump/Load            */
#define ETH_P_DNA_RC    0x6002          /* DEC DNA Remote Console       */
#define ETH_P_DNA_RT    0x6003          /* DEC DNA Routing              */
#define ETH_P_LAT       0x6004          /* DEC LAT                      */
#define ETH_P_DIAG      0x6005          /* DEC Diagnostics              */
#define ETH_P_CUST      0x6006          /* DEC Customer use             */
#define ETH_P_SCA       0x6007          /* DEC Systems Comms Arch       */
#define ETH_P_RARP      0x8035		/* Reverse Addr Res packet	*/
#define ETH_P_ATALK	0x809B		/* Appletalk DDP		*/
#define ETH_P_AARP	0x80F3		/* Appletalk AARP		*/
#define ETH_P_8021Q	0x8100          /* 802.1Q VLAN Extended Header  */
#define ETH_P_IPX	0x8137		/* IPX over DIX			*/
#define ETH_P_IPV6	0x86DD		/* IPv6 over bluebook		*/
#define ETH_P_PPP_DISC	0x8863		/* PPPoE discovery messages     */
#define ETH_P_PPP_SES	0x8864		/* PPPoE session messages	*/
#define ETH_P_ATMMPOA	0x884c		/* MultiProtocol Over ATM	*/
#define ETH_P_ATMFATE	0x8884		/* Frame-based ATM Transport
					 * over Ethernet
					 */
#define ETH_P_EDP2	0x88A2		/* Coraid EDP2			*/

/*
 *	Non DIX types. Won't clash for 1500 types.
 */
 
#define ETH_P_802_3	0x0001		/* Dummy type for 802.3 frames  */
#define ETH_P_AX25	0x0002		/* Dummy protocol id for AX.25  */
#define ETH_P_ALL	0x0003		/* Every packet (be careful!!!) */
#define ETH_P_802_2	0x0004		/* 802.2 frames 		*/
#define ETH_P_SNAP	0x0005		/* Internal only		*/
#define ETH_P_DDCMP     0x0006          /* DEC DDCMP: Internal only     */
#define ETH_P_WAN_PPP   0x0007          /* Dummy type for WAN PPP frames*/
#define ETH_P_PPP_MP    0x0008          /* Dummy type for PPP MP frames */
#define ETH_P_LOCALTALK 0x0009		/* Localtalk pseudo type 	*/
#define ETH_P_PPPTALK	0x0010		/* Dummy type for Atalk over PPP*/
#define ETH_P_TR_802_2	0x0011		/* 802.2 frames 		*/
#define ETH_P_MOBITEX	0x0015		/* Mobitex (kaz@cafe.net)	*/
#define ETH_P_CONTROL	0x0016		/* Card specific control frames */
#define ETH_P_IRDA	0x0017		/* Linux-IrDA			*/
#define ETH_P_ECONET	0x0018		/* Acorn Econet			*/
#define ETH_P_HDLC	0x0019		/* HDLC frames			*/

/* definition file for Ethernet structures and values */

#define ET_MINLEN 60                    /* minimum message length */
#define ET_MAXLEN 1500                  /* maximum message length */
#define ET_TOUT 1000                    /* basic timeout value */

/*
 *	This is an Ethernet frame header.
 */
 
typedef struct _ethhdr_ 
{
	unsigned char	h_dest[ETH_ALEN];	/* destination eth addr	*/
	unsigned char	h_source[ETH_ALEN];	/* source ether addr	*/
	unsigned short	h_proto;		/* packet type ID field	*/
} __attribute__ (( __packed__)) ETHERHDR, *PETHERHDR;

/*
 *  IP structure defined here
 */
// Moved from <linux/ip.h>

#define UDP_PROTOCOL	0x11
#define TCP_PROTOCOL	0x06

#define UDP_LENGTH	8

#define IP_VER4		4
#define IP_FRAG_FLAG	0x01

typedef struct _iphdr_ {

	unsigned char	version:4,
  			ihl:4;
	unsigned char	tos;
	unsigned short	tot_len;
	unsigned short	id;
	unsigned short	frag_off;
	unsigned char	ttl;
	unsigned char	protocol;
	unsigned short	check;
	unsigned long	saddr;
	unsigned long	daddr;
	/*The options start here. */
}  __attribute__ (( __packed__)) IPHDR, *PIPHDR;

//Moved from <linux/udp.h>
#define DNS_PORT	0x35

#define UDP_MAX_SIZE	512

typedef struct _udphdr_ {
	unsigned short	source_port;
	unsigned short	dest_port;
	unsigned short	len;
	unsigned short	check;
}  __attribute__ (( __packed__)) UDPHDR, *PUDPHDR;

typedef struct _udp_pseudo_header_{
	unsigned int source_addr;
	unsigned int dest_addr;
	unsigned char mbz;
	unsigned char protocol;
	unsigned short length;
	unsigned short checksum;
}   __attribute__ (( __packed__)) UDP_PSEUDO, *PUDP_PSEUDO;

typedef struct _packet_info_ {
	ETHERHDR	ether_hdr;
	IPHDR		ip_hdr;
	UDPHDR		udp_hdr 
}   __attribute__ (( __packed__)) PACKET_INFO, *PPACKET_INFO;
 
#endif // end of DNS_HIJACK

#endif  /* _DNRD_COMMON_H_ */
