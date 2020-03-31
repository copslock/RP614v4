#include "asp_page.h"

#ifdef SUPPORT_ASP
#include <linux/config.h>
#include <stdio.h>
#include "boa.h"
#include "rtl865x/rome_asp.c"

asp_name_t *root_asp=NULL;
form_name_t *root_form=NULL;
temp_mem_t root_temp;
char *query_temp_var=NULL;

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

		else if (STREAM_SAME(argv[1],"-c"))	/* system start */
		{
			/*
			  *
			  * demo system configuration inialization entry point
			  * defined in board.c
			  *
			  */
			re865xIoctl("eth0",ADD_SIGNAL_RECEIVE_PROCESS,getpid(),0,0);			  
			log_pid();			
			sleep(1);
			sysInit();
			goto conti;
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

conti:
	root_temp.next=NULL;
	root_temp.str=NULL;	
	
#if defined(DNI)	
	websFormDefine(T("apply.cgi"), apply_cgi);		
	websFormDefine(T("TraceWanDet.cgi"), TraceWanDet_cgi);  //KEVIN:ADD:BlankState
	websFormDefine(T("CA.cgi"), CA_cgi);  //KEVIN:ADD:BlankState
	websFormDefine(T("confretrieve.cgi"), confretrieve_cgi);
	websFormDefine(T("upgrade.cgi"), upgrade_cgi);	
	websFormDefine(T("doupgrade.cgi"), doupgrade_cgi);		
#else	
		
	websFormDefine(T("asp_setLan"), asp_setLan);
	websFormDefine(T("asp_setDmz"), asp_setDmz);
	websFormDefine(T("asp_dhcpServerAdvance"), asp_dhcpServerAdvance);
	websFormDefine(T("asp_setDhcpClient"), asp_setDhcpClient);
	websFormDefine(T("asp_setPppoeWizard"), asp_setPppoeWizard);
	websFormDefine(T("asp_setPppoe"), asp_setPppoe);
	websFormDefine(T("asp_setUnnumberedWizard"), asp_setUnnumberedWizard);
	websFormDefine(T("asp_setNat"), asp_setNat);
	websFormDefine(T("asp_setPing"), asp_setPing);
	websFormDefine(T("asp_setRouting"), asp_setRouting);
	websFormDefine(T("asp_setPort"), asp_setPort);
	websFormDefine(T("asp_setStaticWizard"), asp_setStaticWizard);
#if defined(CONFIG_RTL865X_PPTPL2TP)||defined(CONFIG_RTL865XB_PPTPL2TP)
	websFormDefine(T("asp_setPptpWizard"), asp_setPptpWizard);	
	websFormDefine(T("asp_setL2tpWizard"), asp_setL2tpWizard);	
	websFormDefine(T("asp_setDhcpL2tpWizard"), asp_setDhcpL2tpWizard);	
#endif	
	websFormDefine(T("asp_upload"), asp_upload);
	websFormDefine(T("asp_setUrlFilter"), asp_setUrlFilter);
	websFormDefine(T("asp_restart"), asp_restart);
	websFormDefine(T("asp_systemDefault"), asp_systemDefault);
	websFormDefine(T("asp_wanIp"), asp_wanIp);
	websFormDefine(T("asp_setAcl"), asp_setAcl);
	websFormDefine(T("asp_setTZ"), asp_setTZ);
	websFormDefine(T("asp_setDdns"), asp_setDdns);
	websFormDefine(T("asp_setSpecialApplication"), asp_setSpecialApplication);
	websFormDefine(T("asp_setGaming"), asp_setGaming);	
	websFormDefine(T("asp_setServerPort"), asp_setServerPort);
	websFormDefine(T("asp_setEventLog"), asp_setEventLog);
	websFormDefine(T("asp_setUpnp"), asp_setUpnp);
	websFormDefine(T("asp_setSnmp"), asp_setSnmp);	
	websFormDefine(T("asp_setDos"), asp_setDos);	
	websFormDefine(T("asp_setDosProc"), asp_setDosProc);	
	websFormDefine(T("asp_setAlg"), asp_setAlg);		
	websFormDefine(T("asp_setBt"), asp_setBt);			
	websFormDefine(T("asp_setUser"), asp_setUser);
	websFormDefine(T("asp_setMailAlert"), asp_setMailAlert);
	websFormDefine(T("asp_setRemoteLog"), asp_setRemoteLog);	
	websFormDefine(T("asp_setRemoteMgmt"), asp_setRemoteMgmt);
	websFormDefine(T("asp_setWlanBasic"), asp_setWlanBasic);	
	websFormDefine(T("asp_setWlanAdvance"), asp_setWlanAdvance);	
	websFormDefine(T("asp_setWlanSecurity"), asp_setWlanSecurity);	
	websFormDefine(T("asp_setWlanAccessCtrl"), asp_setWlanAccessCtrl);		
	websFormDefine(T("asp_selectWlanNeighborAp"), asp_selectWlanNeighborAp);
	websFormDefine(T("asp_setUdpBlocking"), asp_setUdpBlocking);	
	websFormDefine(T("asp_setQos"), asp_setQos);
	websFormDefine(T("asp_setQos1"), asp_setQos1);
	websFormDefine(T("asp_setpseudovlan"), asp_setpseudovlan);
	websFormDefine(T("asp_setPbnat"), asp_setPbnat);
	websFormDefine(T("asp_setFlash"), asp_setFlash);
	websFormDefine(T("asp_setRateLimit"), asp_setRateLimit);
	websFormDefine(T("asp_setRatio_qos"), asp_setRatio_qos);
	websFormDefine(T("asp_setModeConfig"), asp_setModeConfig);
	websFormDefine(T("asp_setRipConfig"), asp_setRipConfig);
	websFormDefine(T("asp_setPassthru"), asp_setPassthru);
	websFormDefine(T("asp_setMcast"), asp_setMcast);
	websFormDefine(T("asp_setNaptOpt"), asp_setNaptOpt);
	websFormDefine(T("asp_updateFW"), asp_updateFW);
	websAspDefine(T("asp_rateLimit"), asp_rateLimit);
	websAspDefine(T("asp_acl"), asp_acl);
	websAspDefine(T("asp_dmz"), asp_dmz);
	websAspDefine(T("asp_ddns"), asp_ddns);
	websAspDefine(T("asp_upnp"), asp_upnp);
	websAspDefine(T("asp_snmp"), asp_snmp);
	websAspDefine(T("asp_dos"), asp_dos);
	websAspDefine(T("asp_dosProc"), asp_dosProc);
	websAspDefine(T("asp_alg"), asp_alg);
	websAspDefine(T("asp_bt"), asp_bt);	
	websAspDefine(T("asp_user"), asp_user);
	websAspDefine(T("asp_mailAlert"), asp_mailAlert);	
	websAspDefine(T("asp_remoteLog"), asp_remoteLog);		
	websAspDefine(T("asp_remoteMgmt"), asp_remoteMgmt);	
	websAspDefine(T("asp_urlFilter"), asp_urlFilter);
	websAspDefine(T("asp_pppoe"), asp_pppoe);	
	websAspDefine(T("asp_ping"), asp_ping);	
	websAspDefine(T("asp_routing"), asp_routing);		
	websAspDefine(T("asp_port"), asp_port);		
	websAspDefine(T("asp_TZ"), asp_TZ);	
	websAspDefine(T("asp_TZ2"), asp_TZ2);	
	websAspDefine(T("asp_eventLog"), asp_eventLog);	
	websAspDefine(T("asp_serverPort"), asp_serverPort);	
	websAspDefine(T("asp_specialApplication"), asp_specialApplication);
	websAspDefine(T("asp_gaming"), asp_gaming);	
	websAspDefine(T("asp_statusExtended"), asp_statusExtended);
	websAspDefine(T("asp_configChanged"), asp_configChanged);
	websAspDefine(T("asp_flashGetCfgParam"), asp_flashGetCfgParam);
	websAspDefine(T("asp_dhcpServerLeaseList"), asp_dhcpServerLeaseList);
	websAspDefine(T("asp_flashGetPppoeParam"), asp_flashGetPppoeParam);
	websAspDefine(T("asp_getWanAddress"), asp_getWanAddress);
	websAspDefine(T("asp_flashGetCloneMac"), asp_flashGetCloneMac);	
	websAspDefine(T("asp_flashGetString"), asp_flashGetString);
	websAspDefine(T("asp_flashGetIpElement"), asp_flashGetIpElement);
	websAspDefine(T("asp_wlanBasic"), asp_wlanBasic);	
	websAspDefine(T("asp_wlanAdvance"), asp_wlanAdvance);	
	websAspDefine(T("asp_wlanSecurity"), asp_wlanSecurity);	
	websAspDefine(T("asp_wlanAccessCtrl"), asp_wlanAccessCtrl);	
	websAspDefine(T("asp_wlanClientList"), asp_wlanClientList);
	websAspDefine(T("asp_wlanNeighborApList"), asp_wlanNeighborApList);
	websAspDefine(T("asp_getGwInfo"), asp_getGwInfo);
	websAspDefine(T("asp_reboot"), asp_reboot);
	websAspDefine(T("asp_udpBlocking"), asp_udpBlocking);			
#if defined(CONFIG_RTL865X_PPTPL2TP)||defined(CONFIG_RTL865XB_PPTPL2TP)
	websAspDefine(T("asp_pptpWizard"), asp_pptpWizard);		
	websAspDefine(T("asp_l2tpWizard"), asp_l2tpWizard);			
	websAspDefine(T("asp_dhcpL2tpWizard"), asp_dhcpL2tpWizard);
#endif
	websAspDefine(T("asp_qos"), asp_qos);
	websAspDefine(T("asp_pseudovlan"), asp_pseudovlan);
	websAspDefine(T("asp_getLanPortStatus"), asp_getLanPortStatus);
	websAspDefine(T("asp_getWanPortStatus"), asp_getWanPortStatus);
	websAspDefine(T("asp_pbnat"), asp_pbnat);
	websAspDefine(T("asp_flash"), asp_flash);
	websAspDefine(T("asp_ratio_qos"), asp_ratio_qos);
	websAspDefine(T("asp_webcam"), asp_webcam);
	websAspDefine(T("asp_naptOpt"), asp_naptOpt);
	websAspDefine(T("asp_modeConfig"), asp_modeConfig);
	websAspDefine(T("asp_RipConfig"), asp_RipConfig);	
//	websAspDefine(T("asp_aclPage"), asp_aclPage);
	websAspDefine(T("asp_serverpPage"), asp_serverpPage);
	websAspDefine(T("asp_urlfilterPage"), asp_urlfilterPage);
	websAspDefine(T("asp_qosPage"), asp_qosPage);
	websAspDefine(T("asp_ratelimitPage"), asp_ratelimitPage);
	websAspDefine(T("asp_ratio_qosPage"), asp_ratio_qosPage);
	websAspDefine(T("asp_routingPage"), asp_routingPage);
	websAspDefine(T("asp_ripPage"), asp_ripPage);
	websAspDefine(T("asp_ddnsPage"), asp_ddnsPage);
	websAspDefine(T("asp_specialapPage"), asp_specialapPage);
	websAspDefine(T("asp_gamingPage"), asp_gamingPage);	
	websAspDefine(T("asp_algPage"), asp_algPage);
	websAspDefine(T("asp_dmzPage"), asp_dmzPage);
	websAspDefine(T("asp_dosPage"), asp_dosPage);
	websAspDefine(T("asp_udpblockingPage"), asp_udpblockingPage);
	websAspDefine(T("asp_pbnatPage"), asp_pbnatPage);
	websAspDefine(T("asp_pingPage"), asp_pingPage);
	websAspDefine(T("asp_naptoptPage"), asp_naptoptPage);
	websAspDefine(T("asp_pseudovlanPage"), asp_pseudovlanPage);
	websAspDefine(T("asp_passthruPage"), asp_passthruPage);
	websAspDefine(T("asp_mcastPage"), asp_mcastPage);
	websAspDefine(T("asp_bittorrentPage"), asp_bittorrentPage);
	websAspDefine(T("asp_passthru"), asp_passthru);
	websAspDefine(T("asp_mcast"), asp_mcast);
	websAspDefine(T("asp_IpsecExist"), asp_IpsecExist);
	websAspDefine(T("asp_PptpExist"), asp_PptpExist);	
#ifdef CONFIG_KLIPS
	websAspDefine(T("asp_flashGetIpsec"), asp_flashGetIpsec);	
	websAspDefine(T("asp_GetIpsecStatus"), asp_GetIpsecStatus);	
	websFormDefine(T("asp_setIpsecBasic"), asp_setIpsecBasic);
	websFormDefine(T("asp_IpsecConnect"), asp_IpsecConnect);
#endif
	websAspDefine(T("asp_domainBlock"), asp_domainBlock);
	websAspDefine(T("asp_domainBlocktPage"), asp_domainBlocktPage);
	websFormDefine(T("asp_setDomainBlock"), asp_setDomainBlock);
#ifdef CONFIG_RTL865XB_PPTPSERVER
	websAspDefine(T("asp_pptpServer"), asp_pptpServer);
	websFormDefine(T("asp_setPptpServer"), asp_setPptpServer);	
#endif
	websAspDefine(T("asp_pptpdPage"), asp_pptpdPage);

#ifdef CONFIG_SYSTEM_VERIFICATION
	websFormDefine(T("asp_romeDrvCtrl"), asp_romeDrvCtrl);
#endif

#endif		/* #if defined(DNI) */

	query_temp_var=(char *)malloc(MAX_QUERY_TEMP_VAL_SIZE);
	if(query_temp_var==NULL) exit(0);

	return;
	
main_end:
	shmdt(pRomeCfgParam);
	exit(0);
}

int  websRedirect(request *req,char *url)
{
	req->buffer_end=0;
	send_redirect_perm(req,url);
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

void handleForm(request *req)
{
	char *ptr;
#if defined(DNI)	
	#define SCRIPT_ALIAS "/cgi-bin/"
#else
	#define SCRIPT_ALIAS "/goform/"
#endif	
	ptr=strstr(req->request_uri,SCRIPT_ALIAS);
//	printf("into handleForm %s........\n",req->request_uri);

	if(ptr==NULL)
	{
		send_r_not_found(req);
		return;
	}
	else
	{
		form_name_t *now_form;
		ptr+=strlen(SCRIPT_ALIAS);

		now_form=root_form;
		while(1)
		{
			if (	(strlen(ptr) == strlen(now_form->pagename)) &&
				(memcmp(ptr,now_form->pagename,strlen(now_form->pagename))==0))
			{
				send_r_request_ok(req);		/* All's well */	
				now_form->function(req,NULL,NULL);
				freeAllTempStr();
				//websWrite(req,"okokok\n");			
				return;
			}
			
			if(now_form->next==NULL) break;
			now_form=now_form->next;
		}

		send_r_not_found(req);
		return;
		

	}
	

}

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


#if defined(DNI)
void wan_start(char *name)
{
	printf("wan_start\n");	
	sysReinit(pRomeCfgParam->ifCfgParam[0].connType);		

}

void wan_stop(char *name)
{
	printf("wan_stop\n");
}
#endif

#endif
