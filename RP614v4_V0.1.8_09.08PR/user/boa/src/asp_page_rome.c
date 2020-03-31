#include "asp_page.h"

#ifdef SUPPORT_ASP
#include <linux/config.h>
#include <stdio.h>
#include "boa.h"
//#include "rtl865x/rome_asp.c"
#include "rtl_types.h"
#include "rtl865x/rtl_flashdrv.h"
#include "rtl865x/flashdrv.h"

#include <sys/types.h>
#include <sys/stat.h>

#include <stdio.h>
//#include <wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <net/if.h>
#include <net/if_arp.h>
#include <time.h>
#include <linux/if_ether.h>
#include <linux/config.h>
#include <net/route.h>
#include <re865x.h>
#include <version.h>
//#include "../wsIntrn.h"
#include "rtl865x/rtl_image.h"
//#include <signal.h>
#include "rtl865x/rtl_cfgmgr.h"
#include "rtl865x/rtl_board.h"
#include <rtl8651_tblDrv.h>
#include <rtl8651_tblDrvFwd.h>
#include <rtl8651_alg_init.h>
#include <rtl8651_dos.h>
#include <sys/shm.h>
#include <dirent.h> //for file search
//#include "../../../bittorrent/bt.h"
#include <config/autoconf.h>
#include <assert.h>



asp_name_t *root_asp=NULL;
form_name_t *root_form=NULL;
temp_mem_t root_temp;
char *query_temp_var=NULL;

extern romeCfgParam_t * pRomeCfgParam;

int websAspDefine(char* name, int (*fn)(request * req,  int argc, char **argv))
{
	asp_name_t *asp;
	asp=(asp_name_t*)malloc(sizeof(asp_name_t));
	if(asp==NULL) return ERROR;
	asp->pagename=(char *)malloc(strlen(name)+1);
	strcpy(asp->pagename,name);
	asp->next=NULL;
	asp->function=fn;

	
	if(root_asp==NULL) 
		root_asp=asp;
	else
	{
		//modify the previous's next pointer
		asp_name_t *now_asp;
		now_asp=root_asp;
		while(now_asp->next!=NULL) now_asp=now_asp->next;
		now_asp->next=asp;
	}		
	return SUCCESS;	
}

int websFormDefine(char* name, void (*fn)(request * req,  char* path, char* query))
{

	form_name_t *form;
	form=(form_name_t *)malloc(sizeof(form_name_t));
	if(form==NULL) return ERROR;
	form->pagename=(char *)malloc(strlen(name)+1);
	strcpy(form->pagename,name);
	form->next=NULL;
	form->function=fn;
	
	if(root_form==NULL) 
		root_form=form;
	else
	{
		//modify the previous's next pointer
		form_name_t *now_form;
		now_form=root_form;
		while(now_form->next!=NULL) now_form=now_form->next;
		now_form->next=form;
	}		
	return SUCCESS;	

}

int addTempStr(char *str)
{
	temp_mem_t *temp,*newtemp;
	temp=&root_temp;
	while(temp->next)
	{
		temp=temp->next;
	}
	newtemp=(temp_mem_t *)malloc(sizeof(temp_mem_t));
	if(newtemp==NULL) return FAILED;
	newtemp->str=str;
	newtemp->next=NULL;
	temp->next=newtemp;	
	return SUCCESS;
}

void freeAllTempStr(void)
{
	temp_mem_t *temp,*ntemp;
	temp=root_temp.next;
	root_temp.next=NULL;
	while(1)
	{
		if(temp==NULL) break;
		ntemp=temp->next;
		free(temp->str);
		free(temp);
		temp=ntemp;
	}
}	

int getcgiparam(char *dst,char *query_string,char *param,int maxlen)
{
	int len,plen;
	int y;

	plen=strlen(param);
	while (*query_string)
	{
		len=strlen(query_string);

		if ((len=strlen(query_string))>plen)
			if (!strncmp(query_string,param,plen))
				if (query_string[plen]=='=')
				{//copy parameter
					query_string+=plen+1;
					y=0;
					while ((*query_string)&&(*query_string!='&'))
					{	
						if ((*query_string=='%')&&(strlen(query_string)>2))
							if ((isxdigit(query_string[1]))&&(isxdigit(query_string[2])))
							{
								if (y<maxlen)
									dst[y++]=((toupper(query_string[1])>='A'?toupper(query_string[1])-'A'+0xa:toupper(query_string[1])-'0') << 4)
									+ (toupper(query_string[2])>='A'?toupper(query_string[2])-'A'+0xa:toupper(query_string[2])-'0');
								query_string+=3;
								continue;
							}
						if (*query_string=='+')
						{
							if (y<maxlen)
								dst[y++]=' ';
							query_string++;
							continue;
						}
						if (y<maxlen)
							dst[y++]=*query_string;
						query_string++;
					}
					if (y<maxlen) dst[y]=0;
					return y;
				}
		while ((*query_string)&&(*query_string!='&')) query_string++;
		query_string++;
	}
	if (maxlen) dst[0]=0;
	return -1;
}


char *websGetVar(request *req, char *var, char *defaultGetValue)
{
	char *buf;
	struct stat statbuf;
	int ret=-1;
	
	if (req->method == M_POST)
	{
		int i;
		fstat(req->post_data_fd, &statbuf);
		buf=(char *)malloc(statbuf.st_size+1);
		if(buf==NULL) return defaultGetValue;
		lseek(req->post_data_fd, SEEK_SET, 0);
		read(req->post_data_fd,buf,statbuf.st_size);
		buf[statbuf.st_size]=0;
		i=statbuf.st_size - 1;
		while(i > 0)
		{
			if((buf[i]==0x0a)||(buf[i]==0x0d)) buf[i]=0;
			else break;
			i--;
		}
	}
	else
	{	
		buf=req->query_string;
	}

	if(buf!=NULL)
	{
		ret=getcgiparam(query_temp_var,buf,var,MAX_QUERY_TEMP_VAL_SIZE);	
	}
	
	if(req->method == M_POST) free(buf);
	//printf("query str=%s ret=%d var=%s query_temp_var=%s\n",buf,ret,var,query_temp_var);
	if(ret<0) return defaultGetValue;
	buf=(char *)malloc(ret+1);
	memcpy(buf,query_temp_var,ret);
	buf[ret]=0;
	addTempStr(buf);
	return (char *)buf;	//this buffer will be free by freeAllTempStr().

}


unsigned int __flash_base;
unsigned int __crmr_addr;
unsigned int __wdtcnr_addr;
unsigned int __gimr_addr;

int32 board_cfgmgr_init(uint8 syncAll);

#if defined(DNI)
void apply_cgi(request *wp, char *path, char **query);
void TraceWanDet_cgi(request *wp, char *path, char **query); //KEVIN:06DEC05:BlankState
void CA_cgi(request *wp, char *path, char **query); //KEVIN:06DEC05:BlankState
void confretrieve_cgi(request *wp, char *path, char **query); 
void upgrade_cgi(request *wp, char *path, char **query); 
void doupgrade_cgi(request *wp, char *path, char **query); 
#endif

void websAspInit(int argc,char **argv)
{

	int shmid=0;
#ifndef __uClinux__
	/* 865xB 0xbe000000~0xbeffffff
	   865xC 0xbd000000~0xbdffffff */
	printf("FLASH_BASE_REAL=0x%08x\n",FLASH_BASE_REAL);
	__flash_base=rtl865x_mmap(FLASH_BASE_REAL&0x1FFFFFFF,0x1000000); 
	__crmr_addr=rtl865x_mmap(0x1c805000,0x1000)+0x0104; /* 0xbc805104 */
	__wdtcnr_addr=rtl865x_mmap(0x1d012000,0x1000)+0x003c; /* 0xbd01203c */
	__gimr_addr=rtl865x_mmap(0x1d012000,0x1000)+0x0000; /* 0xbd012000 */
	printf("__flash_base=0x%08x\n",__flash_base);
	printf("__crmr_addr=0x%08x\n",__crmr_addr);
	printf("__wdtcnr_addr=0x%08x\n",__wdtcnr_addr);
#endif
	shmid=shmget(SHM_PROMECFGPARAM,sizeof(romeCfgParam_t),0666|IPC_CREAT);
	pRomeCfgParam=shmat(shmid,(void*)0,0);

/*
 *	Initialize the memory allocator. Allow use of malloc and start 
 *	with a 60K heap.  For each page request approx 8KB is allocated.
 *	60KB allows for several concurrent page requests.  If more space
 *	is required, malloc will be used for the overflow.
 */
	
	if (strstr(argv[0],"ip-up") || strstr(argv[0],"ip-down"))
	{
		ipupdown(argc,argv);
		goto main_end;
	}

	/* =============================================
		We always init cfgmgr module before all procedures
	============================================= */
	{
		uint8 syncAll;

		if ((argc > 1) && (!strcmp(argv[1], "default")))
		{
			syncAll = FALSE;
		} else
		{
			syncAll = TRUE;
		}

		#if defined(CONFIG_RTL865X_DIAG_LED)
		if (board_cfgmgr_init(syncAll) != SUCCESS)
		{
			/* trigger diagnostic LED */
 			re865xIoctl("eth0", RTL8651_IOCTL_DIAG_LED,2,0,0);
		}
		#else
		board_cfgmgr_init(syncAll); /* before any flash read/write */
		#endif /* CONFIG_RTL865X_DIAG_LED */
	}

	if (argc > 1)
	{

		/* =============================================
						Process argument
		    ============================================= */
		#define STREAM_SAME(s1, s2) \
			((strlen(s1) == strlen(s2)) && (strcmp(s1, s2) == 0))

		printf("argv[1] = %s\n", argv[1]);
		if (STREAM_SAME(argv[1],"default"))
		{
			/*
				user call "boa default"
				--> We must do factory default after init cfgmgr system.
			*/
			flashdrv_init();
			cfgmgr_factoryDefault(0);
			printf("cfgmgr_factoryDefault() done!\n");
		}

		else if (STREAM_SAME(argv[1],"save"))
		{
			flashdrv_init();
			cfgmgr_task();
			printf("call cfgmgr_task() to save romeCfgParam to flash done!\n");
		}
		else if (STREAM_SAME(argv[1],"bound"))
		{
			dhcpcIPBound();
		}

		else if (STREAM_SAME(argv[1], "renew"))
		{
			dhcpcIPRenew();
		}

		else if (STREAM_SAME(argv[1],"deconfig"))
		{
			dhcpcDeconfig();
		}

		else if (STREAM_SAME(argv[1],"addacl"))
		{			
			acl_tableDriverSingleHandle(ACL_SINGLE_HANDLE_ADD,atoi(argv[2]),atoi(argv[3]));
		}

		else if (STREAM_SAME(argv[1],"delacl"))
		{			
			acl_tableDriverSingleHandle(ACL_SINGLE_HANDLE_DEL,atoi(argv[2]),atoi(argv[3]));
		}
#if defined(DNI) //Add by Timo Wu
		else if (STREAM_SAME(argv[1],"addurlfilter"))
		{
			printf("boa addurlfilter\n");
			urlfilter_tableDriverSingleHandle(URLFILTER_SINGLE_HANDLE_ADD,atoi(argv[2]),atoi(argv[3]));
			
		}
		
		else if (STREAM_SAME(argv[1],"delurlfilter"))
		{
			printf("boa delurlfilter\n");
			urlfilter_tableDriverSingleHandle(URLFILTER_SINGLE_HANDLE_DEL,atoi(argv[2]),atoi(argv[3]));

		}
		
		else if (STREAM_SAME(argv[1],"checklogfull"))
		{
			printf("boa checklogfull\n");
			email_checkLogFull();

		}
#endif

#ifdef CONFIG_RTL865XB_EXP_WLAN
		/*
			Reinit WLAN interfaces via console / command line.
		*/
		else if (STREAM_SAME(argv[1], "wlan_reinit"))
		{			
			printf ("@ Reinit WLAN interface.\n");
			wlan_reinit();
			printf ("@ Done.\n");
		}
#endif /* CONFIG_RTL865XB_EXP_WLAN */

		goto main_end;
		
	}
	
main_end:
	shmdt(pRomeCfgParam);
	exit(0);
}

int  websRedirect(request *req,char *url)
{
	req->buffer_end=0;
	//send_redirect_perm(req,url);
	return SUCCESS;
}

int allocNewBuffer(request *req)
{
	char *newBuffer;
	newBuffer=(char *)malloc(req->max_buffer_size*2+1);
	if(newBuffer==NULL) return FAILED;
	memcpy(newBuffer,req->buffer,req->max_buffer_size);
	req->max_buffer_size<<=1;	
	free(req->buffer);	
	req->buffer=newBuffer;
	return SUCCESS;
}

int websWriteBlock(request *req, char *buf, int nChars)
{

	int bob=nChars;	
#ifndef SUPPORT_ASP		
	if((bob+req->buffer_end)>BUFFER_SIZE) bob=BUFFER_SIZE- req->buffer_end;
#else
	while((bob+req->buffer_end)>req->max_buffer_size) 
	{
		int ret;
		ret=allocNewBuffer(req);
		if(ret==FAILED) {bob=BUFFER_SIZE- req->buffer_end; break;}
	}
#endif

	if(bob>0)
	{
		memcpy(req->buffer + req->buffer_end,	buf, bob);	
		req->buffer_end+=bob;
		return 0;
	}
	return -1;
}

#if 0
void handleScript(request *req,char *left1,char *right1)	
{
	char *left=left1,*right=right1;
	asp_name_t *now_asp;
	uint32 funcNameLength;
	int i;
	left+=2;
	right-=1;
	while(1)
	{
		while(*left==' ') {if(left>=right) break;++left;}
		while(*left==';') {if(left>=right) break;++left;}
		while(*left=='(') {if(left>=right) break;++left;}
		while(*left==')') {if(left>=right) break;++left;}
		while(*left==',') {if(left>=right) break;++left;}
		if(left>=right) break;

		/* count the function name length */
		{
			char *ptr = left;

			funcNameLength = 0;
			while (*ptr!='(' && *ptr!=' '){
				ptr++;
				funcNameLength++;
				if ((uint32)ptr >= (uint32)right) {
					break;
				}
			}
		}

		now_asp=root_asp;
		while(1)
		{
			if(	(strlen(now_asp->pagename) == funcNameLength) &&
				(memcmp(left,now_asp->pagename,strlen(now_asp->pagename))==0))
			{
				char *leftc,*rightc;
				int argc=0;
				char *argv[8]={NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
				left+=strlen(now_asp->pagename);
				
				while(1) 
				{
					int size,exit=0;
					while(1)
					{
						if(*left==')') {exit=1; break;}
						if(*left=='\"') break;
						if((unsigned int)left>(unsigned int)right) {exit=1; break;}
						left++;	
					}
					
					if(exit==1) break;					
					leftc=left;
					leftc++;
					rightc=strstr(leftc,"\"");
					if(rightc==NULL) break;
					size=(unsigned int)rightc-(unsigned int)leftc+1;
					argv[argc]=(char *)malloc(size);
					if(argv[argc]==NULL) break;
					memcpy(argv[argc],leftc,size-1);
					argv[argc][size-1]=0;
					argc++;
					left=rightc+1;
				}

				now_asp->function(req,argc,argv);

				for(i=0;i<argc;i++) free(argv[i]);
				break;
			}

			if(now_asp->next==NULL) break;
			now_asp=now_asp->next;
		}
		++left;
	}

}
#endif


int asp_addRateLimitRule(rateLimitEntry_t *rlrule_t, uint32 entry)
{
	int8 *ifName[] = { "eth1", "eth0" };
	rtl8651_tblDrvAclRule_t rule;
	uint32 ifIndex, rate, maxRate;
	

	/* Add a rule to Rome Driver */
	if (rlrule_t->rateUnit == 0)
		rate = (1000 * rlrule_t->rate) >> 3;
	else rate = (1000 * 1000 * rlrule_t->rate) >> 3;
	if (rlrule_t->maxRateUnit == 0)
		maxRate = (1000 * rlrule_t->maxRate) >> 3;
	else maxRate = (1000 * 1000 *rlrule_t->maxRate) >> 3;
	
	ifIndex = entry >> 3;
	rtl8651_addRateLimitGroup(1000+entry, ifName[ifIndex], rate, maxRate, rlrule_t->isByteCount);
	bzero(&rule, sizeof(rtl8651_tblDrvAclRule_t));

	/* Action Type */
	if (rlrule_t->isDropLog == TRUE)
		rule.actionType_ = RTL8651_ACL_DROP_LOG;
	else rule.actionType_ = RTL8651_ACL_DROP;
	
	/* rule Type */
	switch (rlrule_t->protoType) {

	case 0: /* TCP */
		rule.ruleType_	= RTL8651_ACL_TCP;
		if (rlrule_t->isSrcIp == TRUE) {
			rule.tcpSrcPortUB_	= rlrule_t->e_port;
			rule.tcpSrcPortLB_	= rlrule_t->s_port;
			rule.tcpDstPortUB_	= 65535;
			rule.tcpDstPortLB_	= 0;
		}
		else {
			rule.tcpDstPortUB_	= rlrule_t->e_port;
			rule.tcpDstPortLB_	= rlrule_t->s_port;
			rule.tcpSrcPortUB_	= 65535;
			rule.tcpSrcPortLB_	= 0;
		}
		goto comm_L3;

	case 1: /* UDP */
		rule.ruleType_	= RTL8651_ACL_UDP;
		if (rlrule_t->isSrcIp == TRUE) {
			rule.udpSrcPortUB_		= rlrule_t->e_port;
			rule.udpSrcPortLB_		= rlrule_t->s_port;
			rule.udpDstPortUB_		= 65535;
			rule.udpDstPortLB_		= 0;
		}
		else {
			rule.udpDstPortUB_		= rlrule_t->e_port;
			rule.udpDstPortLB_		= rlrule_t->s_port;
			rule.udpSrcPortUB_		= 65535;
			rule.udpSrcPortLB_		= 0;
		}
		goto comm_L3;

	case 2: /* IP */
		rule.ruleType_ = RTL8651_ACL_IP;
comm_L3:
		if (rlrule_t->isSrcIp == TRUE) {
			rule.srcIpAddr_		= rlrule_t->ip;
			rule.srcIpAddrMask_	= rlrule_t->ipMask;
		}
		else {
			rule.dstIpAddr_		= rlrule_t->ip;
			rule.dstIpAddrMask_	= rlrule_t->ipMask;
		}
		break;
	
	default: return 1;
	}
	rtl8651_addRateLimitRule(&rule, 1000+entry);
	return 0;
}

void rearrange_Ratio_Qos(void)
{
	int i;

	/* Inite ratio QoS */
	//rtl8651_setUpstreamBandwidth("eth0", 0);
	
	/* set upstream bw */
	if (pRomeCfgParam->ratioQosCfgParam.enable == TRUE) {
		rtl8651_setUpstreamBandwidth("eth0",
			(pRomeCfgParam->ratioQosCfgParam.upInfo.maxRateUnit == 0)?
				(pRomeCfgParam->ratioQosCfgParam.upInfo.maxRate * 1000 * 1000):
				(pRomeCfgParam->ratioQosCfgParam.upInfo.maxRate * 1000));
	}
	
	/* set all entries */
	for (i = 0 ; i < MAX_RATIO_QOS ; i ++)
	{
		ratioQosEntry_t* entry;

		entry = &(pRomeCfgParam->ratioQosCfgParam.entry[i]);
		if (entry->enable)
		{
			rtl8651_tblDrvAclRule_t rule;

			memset(&rule, 0, sizeof(rtl8651_tblDrvAclRule_t));
			rule.actionType_ = RTL8651_ACL_DROP;
			switch(entry->protoType) {

			case 0: /* TCP */
				rule.ruleType_	= RTL8651_ACL_TCP;
				if (entry->isSrc == TRUE) {
					rule.tcpSrcPortUB_		= entry->e_port;
					rule.tcpSrcPortLB_		= entry->s_port;
					rule.tcpDstPortUB_		= 65535;
					rule.tcpDstPortLB_		= 0;
				}
				else {
					rule.tcpDstPortUB_		= entry->e_port;
					rule.tcpDstPortLB_		= entry->s_port;
					rule.tcpSrcPortUB_		= 65535;
					rule.tcpSrcPortLB_		= 0;
				}
				goto comm_L3;

			case 1: /* UDP */
				rule.ruleType_	= RTL8651_ACL_UDP;
				if (entry->isSrc == TRUE) {
					rule.udpSrcPortUB_	= entry->e_port;
					rule.udpSrcPortLB_		= entry->s_port;
					rule.udpDstPortUB_	= 65535;
					rule.udpDstPortLB_		= 0;
				}
				else {
					rule.udpDstPortUB_	= entry->e_port;
					rule.udpDstPortLB_		= entry->s_port;
					rule.udpSrcPortUB_	= 65535;
					rule.udpSrcPortLB_		= 0;
				}
				goto comm_L3;

			default: /* IP */
				rule.ruleType_ = RTL8651_ACL_IP;
comm_L3:
				if (entry->isSrc == TRUE) {
					rule.srcIpAddr_		= entry->ip;
					rule.srcIpAddrMask_	= entry->ipMask;
				}
				else {
					rule.dstIpAddr_		= entry->ip;
					rule.dstIpAddrMask_	= entry->ipMask;
				}
			}

			if (entry->isHigh)
			{			
				rtl8651_addFlowToUnlimitedQueue("eth1", &rule, entry->ratio, entry->queueID);

				if (entry->mark == 1)
				{
					rtl8651_setDscpToMNQueue(entry->queueID, (uint32) entry->dscp);
				}
#if 0
				switch(entry->priority)
				{
 				case 0:	/* BE */
					rtl8651_setDscpToMNQueue(entry->queueID, (uint32) 0x00);
					break;
				case 1:	/* AF4 */
					rtl8651_setDscpToMNQueue(entry->queueID, (uint32) 0x28);
					break;
				case 2:	/* AF3 */
					rtl8651_setDscpToMNQueue(entry->queueID, (uint32) 0x48);
					break;
				case 3:	/* AF2 */
					rtl8651_setDscpToMNQueue(entry->queueID, (uint32) 0x68);
					break;
				case 4:	/* AF1 */
					rtl8651_setDscpToMNQueue(entry->queueID, (uint32) 0x88);
					break;
				case 5:	/* EF */
					rtl8651_setDscpToMNQueue(entry->queueID, (uint32) 0xB8);
					break;
				default:
					break;
				}
#endif
			}else
			{
				rtl8651_addFlowToLimitedQueue("eth1", &rule, entry->ratio, entry->queueID);

				if (entry->mark == 1)
				{
					rtl8651_setDscpToMNQueue(entry->queueID, (uint32) entry->dscp);
				}
#if 0
				switch(entry->priority)
				{
				case 0:	/* BE */
					rtl8651_setDscpToMNQueue(entry->queueID, (uint32) 0x00);
					break;
				case 1:	/* AF4 */
					rtl8651_setDscpToMNQueue(entry->queueID, (uint32) 0x28);
					break;
				case 2:	/* AF3 */
					rtl8651_setDscpToMNQueue(entry->queueID, (uint32) 0x48);
					break;
				case 3:	/* AF2 */
					rtl8651_setDscpToMNQueue(entry->queueID, (uint32) 0x68);
					break;
				case 4:	/* AF1 */
					rtl8651_setDscpToMNQueue(entry->queueID, (uint32) 0x88);
					break;
				case 5:	/* EF */
					rtl8651_setDscpToMNQueue(entry->queueID, (uint32) 0xB8);
					break;
				default:
					break;
				}
#endif
			}
		}
	}
}

void parse_portRange(char *temp,uint16 *port_start,uint16 *port_finish)
{
	char temp2[32];
	int j;
	uint16 port_temp;	
	memcpy(temp2,temp,32);
	*port_start=atoi(temp);
	*port_finish=atoi(temp);
	for(j=0;j<strlen(temp2);j++)
	{
		if(temp2[j]=='-') 
		{
			temp2[j]=0;
			*port_start=atoi(temp2);
			*port_finish=atoi(temp2+j+1);
			break;
		}
	}
	if(*port_finish<*port_start) { port_temp=*port_finish; *port_finish=*port_start; *port_start=port_temp; }
}

void parse_ipRange(char *temp, ipaddr_t *ip, ipaddr_t *ip2)
{
	int j,ipflag=0;
	ipaddr_t temp_ip;
	char ip_str[32],ip_str2[32];
	memcpy(ip_str,temp,32);
	*ip=0;
	*ip2=0;

	for(j=0;j<strlen(ip_str)+1;j++)
	{		
		ip_str2[j-ipflag]=ip_str[j];	
		if((ip_str[j]=='.')||(ip_str[j]=='-')||(ip_str[j]==0)) 
		{			
			ip_str2[j-ipflag]=0;
			*ip=(*ip<<8)|(atoi(ip_str2)&0xff);
			ipflag=j+1;				
			if(ip_str[j]=='-') { *ip2=*ip; *ip=0; }
			if(ip_str[j]==0) break;
		}						
	}

	if(*ip2==0) *ip2=*ip;
	if(*ip2<*ip) {temp_ip=*ip; *ip=*ip2; *ip2=temp_ip; }
	
	
}

#endif
