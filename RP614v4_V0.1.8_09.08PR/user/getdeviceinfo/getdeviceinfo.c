#include <sys/param.h>
#include <sys/socket.h>
#include <sys/file.h>
#include <sys/time.h>
#include <sys/times.h>
#include <sys/signal.h>

#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
static const int MAXIPLEN = 60;
static const int MAXICMPLEN = 76;




char link_status[48],tmp[48];
unsigned long dsl_rate_downstream,dsl_rate_upstream;
char Channel[48];
int find_device_flag=0;

static int getxdigit(char c);
static int getbyte(char *line);
static void reply_restore();

void get_mac_address(unsigned char *mac, int ifno);
void get_software_version(char *buf);
void get_hardware_version(char *buf);
void get_bootloader_version(char *buf);
void get_product_name(char *buf);
void get_release_time(char *buf);
void get_adsl_status();


static void icmp_process();
int create_icmp_socket_a(void);


/* common routines */
static int in_cksum(unsigned short *buf, int sz)
{
	int nleft = sz;
	int sum = 0;
	unsigned short *w = buf;
	unsigned short ans = 0;

	while (nleft > 1) {
		sum += *w++;
		nleft -= 2;
	}

	if (nleft == 1) {
		*(unsigned char *) (&ans) = *(unsigned char *) w;
		sum += ans;
	}

	sum = (sum >> 16) + (sum & 0xFFFF);
	sum += (sum >> 16);
	ans = ~sum;
	return (ans);
}

/* simple version */
/* full(er) version */
static struct sockaddr_in remoteaddr;
static int icmpsock = -1;
static int datalen; /* intentionally uninitialized to work around gcc bug */


static long ntransmitted = 0;
static int myid = 0;

static void reply_dnigetinfo();
static void reply_find_device();

static int unpack(char *, int, struct sockaddr_in *);


static void reply_dnigetinfo()
{
	struct icmp *pkt;
	//unsigned short i;
	unsigned char len,tmp_a[4],tmp_b[4];
	unsigned long dsl_rate;
	char packet[datalen + 8],str_buf[128];
    unsigned char *icmpdata,*icmpdata_start,mac_address[12];
	int packet_len;

	pkt = (struct icmp *) packet;
    
	pkt->icmp_type = ICMP_INFO_REPLY;
	pkt->icmp_code = 0;
	pkt->icmp_cksum = 0;
	pkt->icmp_seq = ntransmitted;
	pkt->icmp_id = myid;

    icmpdata = (unsigned char *) pkt->icmp_data;
    icmpdata_start=icmpdata;
////////////////////////////////////////////////////////////////////////
              
            
			*icmpdata=1 ; icmpdata++;//op_code -> mac address
			//len = 18;
            len = 12/*6*/;
			
			memcpy(icmpdata,&len,1);icmpdata++; 
            //mac_address[0]=0x00;mac_address[1]=0x01;mac_address[2]=0x02;
            //mac_address[3]=0x03;mac_address[4]=0x04;mac_address[5]=0x05;
            get_mac_address(mac_address, 0/* LAN */);
            memcpy(icmpdata,mac_address,6);icmpdata=icmpdata+6;
            get_mac_address(mac_address, 1/* WAN */); 
            memcpy(icmpdata,mac_address,6);icmpdata=icmpdata+6;
                       

			/*
            mac_address[0]=0x10;mac_address[1]=0x11;mac_address[2]=0x12;
            mac_address[3]=0x13;mac_address[4]=0x14;mac_address[5]=0x15;

            memcpy(icmpdata,mac_address,6);icmpdata=icmpdata+6;
            mac_address[0]=0x20;mac_address[1]=0x21;mac_address[2]=0x22;
            mac_address[3]=0x23;mac_address[4]=0x24;mac_address[5]=0x25;

            memcpy(icmpdata,mac_address,6);icmpdata=icmpdata+6;
            */

            *icmpdata=2 ; icmpdata++;//op_code -> software version
	        get_software_version(str_buf);
            //strcpy(str_buf,"software version");
			len=strlen(str_buf);
			memcpy(icmpdata,&len,1);icmpdata++;
            memcpy(icmpdata,str_buf,len);icmpdata=icmpdata+len; 
			
            *icmpdata=3 ; icmpdata++;//op_code -> hardware version
            //strcpy(str_buf,"02");
			get_hardware_version(str_buf);
			len=strlen(str_buf);
			memcpy(icmpdata,&len,1);icmpdata++;
            memcpy(icmpdata,str_buf,len);icmpdata=icmpdata+len; 

			*icmpdata=4 ; icmpdata++;//op_code -> product name
            //strcpy(str_buf,"RP614");
			get_product_name(str_buf);
			len=strlen(str_buf);
			memcpy(icmpdata,&len,1);icmpdata++;
            memcpy(icmpdata,str_buf,len);icmpdata=icmpdata+len; 

			*icmpdata=5 ; icmpdata++;//op_code -> bootloader version
			//1.0.37-0.8
            //strcpy(str_buf,"1.0.37-0.8");
			get_bootloader_version(str_buf);
			len=strlen(str_buf);
			memcpy(icmpdata,&len,1);icmpdata++;
            memcpy(icmpdata,str_buf,len);icmpdata=icmpdata+len; 

			*icmpdata=6 ; icmpdata++;//op_code -> build date
            //get_release_time(str_buf);
            sprintf(str_buf, "%s %s", __DATE__ __TIME__);
            //strcpy(str_buf,"build date");
			len=strlen(str_buf);
			memcpy(icmpdata,&len,1);icmpdata++;
            memcpy(icmpdata,str_buf,len);icmpdata=icmpdata+len; 

			*icmpdata=7 ; icmpdata++;//op_code -> Device Type
            strcpy(str_buf,"ROUTER");
			len=strlen(str_buf);
			memcpy(icmpdata,&len,1);icmpdata++;
            memcpy(icmpdata,str_buf,len);icmpdata=icmpdata+len; 

/*
            get_adsl_status();
			*icmpdata=8 ; icmpdata++;//op_code -> ADSL Link status
            strcpy(str_buf,link_status);
			len=strlen(str_buf);
			memcpy(icmpdata,&len,1);icmpdata++;
            memcpy(icmpdata,str_buf,len);icmpdata=icmpdata+len; 

			*icmpdata=9 ; icmpdata++;//op_code -> ADSL Line Rate(Up Stream) 
			len = 4;
			memcpy(icmpdata,&len,1);icmpdata++;
			//dsl_rate=1234;
			
            memcpy(tmp_a,&dsl_rate_upstream,4);
			tmp_b[3]=tmp_a[0];tmp_b[2]=tmp_a[1];tmp_b[1]=tmp_a[2];tmp_b[0]=tmp_a[3];
			memcpy(icmpdata,tmp_b,4);icmpdata=icmpdata+4;

			*icmpdata=10 ; icmpdata++;//op_code -> ADSL Line Rate(Down Stream)
			len = 4;
			memcpy(icmpdata,&len,1);icmpdata++;
			//dsl_rate=5678;
            memcpy(tmp_a,&dsl_rate_downstream,4);
			tmp_b[3]=tmp_a[0];tmp_b[2]=tmp_a[1];tmp_b[1]=tmp_a[2];tmp_b[0]=tmp_a[3];
			memcpy(icmpdata,tmp_b,4);icmpdata=icmpdata+4;
*/
			/*
			*icmpdata=11 ; icmpdata++;//op_code -> Wireless ESSID
            strcpy(str_buf,"Wireless ESSID");
			len=strlen(str_buf);
			memcpy(icmpdata,&len,1);icmpdata++;
            memcpy(icmpdata,str_buf,len);icmpdata=icmpdata+len; 
            */

            *icmpdata=255 ; icmpdata++;//op_code -> end of data
            packet_len=(int)(icmpdata-icmpdata_start);
			
////////////////////////////////////////////////////////////////////////

	pkt->icmp_cksum = in_cksum((unsigned short *) pkt, 8+packet_len);

	sendto(icmpsock, packet, 8+packet_len, 0,(struct sockaddr *) &remoteaddr, sizeof(struct sockaddr_in));
			   
}

static void reply_find_device()
{
	struct icmp *pkt;
	//unsigned short i;
	unsigned char len,tmp_a[4],tmp_b[4];
	unsigned long dsl_rate;
	char packet[datalen + 8],str_buf[128];
    unsigned char *icmpdata,*icmpdata_start,mac_address[6];
	int packet_len;

	pkt = (struct icmp *) packet;
    
	pkt->icmp_type = ICMP_INFO_REPLY;
	pkt->icmp_code = 0;
	pkt->icmp_cksum = 0;
	pkt->icmp_seq = ntransmitted;
	pkt->icmp_id = myid;

    icmpdata = (unsigned char *) pkt->icmp_data;
    icmpdata_start=icmpdata;
////////////////////////////////////////////////////////////////////////
              
            //sleep(3);
			*icmpdata=0x01 ; icmpdata++;
            packet_len=(int)(icmpdata-icmpdata_start);
			
////////////////////////////////////////////////////////////////////////

	pkt->icmp_cksum = in_cksum((unsigned short *) pkt, 8+packet_len);

	sendto(icmpsock, packet, 8+packet_len, 0,(struct sockaddr *) &remoteaddr, sizeof(struct sockaddr_in));
			   
}



static void reply_restore()
{
	struct icmp *pkt;
	//unsigned short i;
	unsigned char len,tmp_a[4],tmp_b[4];
	unsigned long dsl_rate;
	char packet[datalen + 8],str_buf[128];
    unsigned char *icmpdata,*icmpdata_start,mac_address[6];
	int packet_len;

	pkt = (struct icmp *) packet;
    
	pkt->icmp_type = ICMP_INFO_REPLY;
	pkt->icmp_code = 0;
	pkt->icmp_cksum = 0;
	pkt->icmp_seq = ntransmitted;
	pkt->icmp_id = myid;

    icmpdata = (unsigned char *) pkt->icmp_data;
    icmpdata_start=icmpdata;
////////////////////////////////////////////////////////////////////////
              
			*icmpdata=0x01 ; icmpdata++;
            packet_len=(int)(icmpdata-icmpdata_start);
			
////////////////////////////////////////////////////////////////////////

	pkt->icmp_cksum = in_cksum((unsigned short *) pkt, 8+packet_len);

	sendto(icmpsock, packet, 8+packet_len, 0,(struct sockaddr *) &remoteaddr, sizeof(struct sockaddr_in));
			   
}


static int unpack(char *buf, int sz, struct sockaddr_in *from)
{
	struct icmp *icmppkt;
	struct iphdr *iphdr;
	int hlen;
	unsigned char *icmpdata;
	int ret=0;

	/* check IP header */
	iphdr = (struct iphdr *) buf;
	hlen = iphdr->ihl << 2;
	sz -= hlen;
	icmppkt = (struct icmp *) (buf + hlen);
    myid = icmppkt->icmp_id ;
    ntransmitted = icmppkt->icmp_seq ;

    icmpdata = (unsigned char *) icmppkt->icmp_data;
    if(strstr(icmpdata,"DNIGETINFO")!=NULL)
		ret=1;
	else if(strstr(icmpdata,"FIND_DEVICE")!=NULL)
        ret=2;
	else if(strstr(icmpdata,"RESTOREDEFAULT")!=NULL)
        ret=3;



	return ret;
}


static void icmp_process()
{
	char packet[datalen + MAXIPLEN + MAXICMPLEN];
	int sockopt;

	icmpsock = create_icmp_socket_a();

	memset(&remoteaddr, 0, sizeof(struct sockaddr_in));

	remoteaddr.sin_family = AF_INET;

	/* enable broadcast pings */
	sockopt = 1;
	setsockopt(icmpsock, SOL_SOCKET, SO_BROADCAST, (char *) &sockopt,
			   sizeof(sockopt));

	/* set recv buf for broadcast pings */
	sockopt = 48 * 1024;
	setsockopt(icmpsock, SOL_SOCKET, SO_RCVBUF, (char *) &sockopt,
			   sizeof(sockopt));

	/* listen for replies */
	while (1) {
		//printf("wait !\r\n");
		struct sockaddr_in from;
		socklen_t fromlen = (socklen_t) sizeof(from);
		int c;

		if ((c = recvfrom(icmpsock, packet, sizeof(packet), 0,
						  (struct sockaddr *) &from, &fromlen)) < 0) {
			if (errno == EINTR)
				continue;
			//perror_msg("recvfrom");
			continue;
		}
		remoteaddr.sin_addr=from.sin_addr;
		switch(unpack(packet, c, &from))
		{
		case 1:
			printf("reply_dnigetinfo\r\n");
			reply_dnigetinfo();
			break;
		case 2:
			//if(find_device_flag==0)
			{
               find_device_flag=1;
               printf("reply_find_device\r\n"); 
			   system("echo testmode > /var/test_mode");
			   reply_find_device();

			}
            break;
		case 3:
               printf("reply_restore\r\n"); 
			   system("resetbtn");
               sleep(2);
               reply_restore();
			   sleep(2);
               system("reboot");
			

			break;
		}
	}
}



static int getxdigit(char c)
{
    if ((c >= '0') && (c <= '9')) return c - '0';
    if ((c >= 'A') && (c <= 'F')) return c - 'A' + 10;
    if ((c >= 'a') && (c <= 'f')) return c - 'a' + 10;
    return -1;
}

static int getbyte(char *line)
{
    int res;
    int c1,c2;
	c1 = getxdigit(*(line+0));
    if (c1 < 0) return -1;

	c2 = getxdigit(*(line+1));
    if (c2 < 0) return -1;

    res = (c1*16+c2);
    return res;
}

void get_software_version(char *buf)
{
	strcpy(buf, nvram_get("os_version"));
}


void get_hardware_version(char *buf)
{
	char *val;
    val = nvram_get("hw_version");
	
	strcpy(buf,val);
	//printf("### hw_version = %s\r\n",buf);
}


void get_bootloader_version(char *buf)
{
	strcpy(buf, nvram_get("loader_version"));
}

void get_product_name(char *buf)
{
	strcpy(buf,"RP614v4");
}

void get_release_time(char *buf)
{
FILE *fp;

fp=fopen( "/etc/build_time", "r" );

if(fp==NULL)
{
	strcpy(buf,"/etc/build_time not found");
}
else
{
       fgets( buf,48, fp );
       buf[strlen(buf)-1]=0x00;
	   fclose(fp);
}


     
}


void cut_end(char *buf,char c)
{

int i;

    for(i=0;i<48;i++)
	{
		if(*(buf+i)==c)
		{
			*(buf+i)=0x00;
			break;
		}
	}
}


//adsl: ADSL driver and PHY status
//Status: Showtime  Channel: FAST, Upstream rate = 864 Kbps, Downstream rate = 8128 Kbps
//Link Power State: L0
//Mode:			G.DMT
//Channel:		Fast
//Trellis:		ON
//Line Status:		No Defect
//Training Status:	Showtime
//		Down		Up
//SNR (dB):	22.2		12.0
//Attn(dB):	0.0		1.5
//Pwr(dBm):	7.7		11.9
//Max(Kbps):	11264		1136
//Rate (Kbps):	8128		864
//			G.dmt framing
//K:		255(0)		28
//R:		0		0
//S:		1		1
//D:		1		1
//			ADSL2 framing
//MSGc:		1		1
//B:		255		28
//M:		1		1
//T:		1		1
//R:		0		0
//S:		1.0000		1.0000
//L:		2048		232
//D:		1		1
//			Counters
//SF:		5292		5290
//SFErr:		0		0
//RS:		0		0
//RSCorr:		0		0
//RSUnCorr:	0		0
//
//HEC:		0		0
//OCD:		0		0
//LCD:		0		0
//Total Cells:	1734025		0
//Data Cells:	0		0
//Drop Cells:	0
//Bit Errors:	0		0
//
//ES:		0		0
//SES:		0		0
//UAS:		14		0


void get_adsl_status()
{
/*
	FILE *fp;
	char *seek;
	char buf[1024];

	dsl_rate_downstream=0;dsl_rate_upstream=0;
	system("adsl info --show > /var/adsl_status");

	printf("\r\n");
	fp=fopen( "/var/adsl_status", "r" );
	while(1)
	{
	   if(fgets( buf,256, fp )==NULL)break;
       buf[strlen(buf)-1]=0x00;
	   if(strstr(buf,"Idle")!=NULL)strcpy(link_status,"Link Down");

	   if(strstr(buf,"Showtime")!=NULL && strstr(buf,"Training Status")==NULL)
	   {
		   strcpy(link_status,"Link Up");
		   seek=strstr(buf,"Channel");
           memcpy(Channel,(seek+9),48);
		   cut_end(Channel,',');
           
		   
		   seek=strstr(buf,"Upstream");
           memcpy(tmp,(seek+16),48);
		   cut_end(tmp,' ');
		   dsl_rate_upstream=atoi(tmp)*1000;
           

		   seek=strstr(buf,"Downstream");
           memcpy(tmp,(seek+18),48);
		   dsl_rate_downstream=atoi(tmp)*1000;
		   
	   }
    }
	fclose(fp);

	printf("Channel=%s\r\n",Channel);
	printf("dsl_rate_upstream=%d\r\n",dsl_rate_upstream);
    printf("dsl_rate_downstream=%d\r\n",dsl_rate_downstream);

	printf("status=%s\r\n",link_status);
	printf("\r\n*********\r\n");
*/
}

void get_mac_address(unsigned char *mac, int ifno)
{

    char *buf;
    
    if (ifno == 0)
    	buf = nvram_get("lan_hwaddr");
    else
    	buf = nvram_get("wan0_hwaddr");
    		
	
    *(mac+0)=getbyte(&buf[0]);    
    *(mac+1)=getbyte(&buf[0+3*1]);    
    *(mac+2)=getbyte(&buf[0+3*2]);    
    *(mac+3)=getbyte(&buf[0+3*3]);    
    *(mac+4)=getbyte(&buf[0+3*4]);    
    *(mac+5)=getbyte(&buf[0+3*5]);    

}

#ifdef BUILD_STATIC
extern int dslmp_main(int argc, char **argv)
#else
int main(int argc, char **argv)
#endif
{
	//unsigned char md[6];
	//char buf[256];
	//printf("%%%%####\r\n");
    /*
	get_software_version(buf);
    printf(buf);
    get_release_time(buf);
    printf(buf);
    printf("\r\n");

	sleep(20);
	get_adsl_status();

	get_mac_address(md);
	printf("mac address %02x:%02x:%02x:%02x:%02x:%02x",md[0],md[1],md[2],md[3],md[4],md[5]);
    printf("\r\n");
    */
	datalen = 256; /* initialized here rather than in global scope to work around gcc bug */
	icmp_process();
	
	return EXIT_SUCCESS;
}

int create_icmp_socket_a(void)
{
	struct protoent *proto;
	int sock;

	proto = getprotobyname("icmp");
	sock = socket(AF_INET, SOCK_RAW,(proto ? proto->p_proto : 1));
	return sock;
}
