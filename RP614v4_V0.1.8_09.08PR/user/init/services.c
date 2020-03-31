/*
 * Miscellaneous services
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <errno.h>

#include <re865x.h>
#include <board.h>

#include <sys/ioctl.h>

#include <rtl8651_tblDrv.h>

extern int shmid;
extern int geted;
extern romeCfgParam_t * pRomeCfgParam;

int do_kill(char *filename)
{
	int pid=0;
	FILE *f;
	f=fopen(filename,"r");
	if(f!=NULL)
	{
		fscanf(f,"%d",&pid);

		kill(pid,SIGTERM);
		kill(pid,SIGQUIT);
		sleep(1);
		kill(pid,SIGKILL);
		fclose(f);
		remove(filename);
		return 0;
	}
	return -1;	
}

void AddDemandRoute(int pppObjId,int defaultSession)
{
	rtl8651_tblDrvDemandRoute_t tmpRt;
	int32  i;
	uint32 ip_start,ip_end;
	uint16 port_start,port_end;
	
	rtl8651_flushDemandRoute(pppObjId);
	
	if (defaultSession){
		tmpRt.type=TRIGGER_DSTIP;
		tmpRt.ip_start=0;
		tmpRt.ip_end=0xffffffff;
		rtl8651_addDemandRoute(&tmpRt,pppObjId,0);
		return;
	}

}

void 
system_restart(void)
{

	dprintf("%s\n", __FUNCTION__);	
	send_signal("/var/run/boa.pid",72);		/* sysReinit */	
	dprintf("done\n");	
}	


void
start_wan(void)
{
	dprintf("%s\n", __FUNCTION__);
	send_signal("/var/run/boa.pid",71);		/* start wan */	
	dprintf("done\n");	

}

void
stop_wan(void)
{
	dprintf("%s\n", __FUNCTION__);
	send_signal("/var/run/boa.pid",70);		/* stop wan */
	dprintf("done\n");
}

void
wan_up(char *wan_ifname)
{
}

