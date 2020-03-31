/*
*
*/

#include <stdio.h>
#include <errno.h>
#include <syslog.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

#include <dni_shutils.h>
#include <dni_nvram.h>
#include "rc.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


static void AddHASPort( char *hasIP, char *heartbeatPort);
static void DelHASPort( char *hasIP, char *heartbeatPort);

int
start_heartbeat()
{
	FILE *fp;
	int ret;
	char authserver[80];
	char authdomain[80];
	int iHB_state;

	if(nvram_invmatch("wan_proto", "telstra"))	return 0;

	//openlog("bpalogin", LOG_PID | LOG_NDELAY, LOG_DAEMON);
	authdomain[0] = 0;
	authserver[0] = 0;

//note by dvd.chen,
//Netgear's GUI has 1 field only for bpalog server,
//user can input 1. IP_address, 2. URL
// 3. NOTHING (system will show the default host name:sm-server, and we must attach 
//		the domain name from dhcpc message)

	if(nvram_invmatch("wan_tel_service", "") && nvram_invmatch("wan_tel_service", "0.0.0.0"))
	{
		snprintf(authserver, sizeof(authserver), "%s", nvram_safe_get("wan_tel_service"));
	}
	
	//get authdomain from dhcpc wan domain
	snprintf(authdomain, sizeof(authdomain), "%s", nvram_safe_get("wan_domain"));  
	
	//syslog(LOG_DEBUG, "heartbeat: authserver[%s] authdomain[%s]\n", authserver, authdomain);
	if (!(fp = fopen("/tmp/bpalogin.conf", "w"))) {
		perror("/tmp/bpalogin.conf");
		return errno;
	}
	fprintf(fp, "username %s\n", nvram_safe_get("wan_tel_username"));
	fprintf(fp, "password %s\n", nvram_safe_get("wan_tel_password"));

//added by dvd.chen on 01/11/2006 for bpa idle timeout
	fprintf(fp, "idle_interval %s\n", nvram_safe_get("wan_tel_idle_interval"));
//end of dvd.chen
	if( strlen(authserver)>0 )
		fprintf(fp, "authserver %s\n", authserver);
	//fprintf(fp, "%cauthdomain %s\n", strcmp(authdomain,"") ? '\0' : '#', authdomain);
	if( strlen(authdomain)>0 )
		fprintf(fp, "authdomain %s\n", authdomain);
	fprintf(fp, "localport %d\n", HEARBEAT_LOCAL_PORT);
#ifdef REMOTE_SYSLOG_DEBUG
	fprintf(fp, "logging syslog\n");
#else
	fprintf(fp, "logging stdout\n");
#endif
	fprintf(fp, "debuglevel 0\n");  //no debug
	//fprintf(fp, "debuglevel 2\n");  //no debug
	fprintf(fp, "minheartbeatinterval 60\n");
	fprintf(fp, "maxheartbeatinterval 420\n");
	fprintf(fp, "connectedprog hb_connect\n"); 
	fprintf(fp, "disconnectedprog hb_disconnect\n");
	//fprintf(fp, "pingGatewayIP %s\n", nvram_safe_get("wan0_gateway"));  //dvd.chen
	
	fclose(fp);
	
	//mkdir("/etc/ppp", 0777);
	
	eval("killall", "-9", "bpalogin");
	sleep(1);
	ret = eval("bpalogin", "-c", "/tmp/bpalogin.conf");

#if 0
	if (nvram_invmatch("wan_ppp_demand", "1")) {
		if(status != REDIAL)
			start_redial();	
	}
#endif

	return ret;
}

/*
 *  Called when link comes up
 *  argv[1] : listenport
 *  argv[2] : pid
 */
int
hb_connect_main(int argc, char **argv)
{
	FILE *fp;
	
	cprintf("Enter hb_connect_main\n");
	
	//openlog("bpalogin" ,LOG_PID, LOG_DAEMON);
	
	mkdir(PID_PATH, 0777);

	/* Touch connection file */
	if (!(fp = fopen(PPP_LINK_PATH"bpa", "a"))) {
                perror(PPP_LINK_PATH"bpa");
                return errno;
        }
        fclose(fp);
	
	AddHASPort(argv[1], argv[2]);
	/*
	//add udp:5050 to iptable
	snprintf(buf, sizeof(buf), "iptables -I INPUT -d %s -i %s -p udp --dport %d -j %s", 
		   nvram_safe_get("wan0_ipaddr"), 
		   nvram_safe_get("wan0_ifname"),   //vlan1
		   5050, 
		   "ACCEPT");
	cprintf("\nExecuting external command: \n%s\n",buf);
	system(buf);
	*/


	rtl8651_flushDemandRoute(5);		
	//log bpalogin wan_up here
	log_WAN_connect("WAN Telstra BigPond Connected");
	setLedLight(WAN_LED, LED_GREEN);	
	
	
	return TRUE;	
}

/*
 *  * Called when link goes down
 *   */
// arg[1]: heartbeat server IP
// arg[2]: local listen port
// argv[3]: reason
int
hb_disconnect_main(int argc, char **argv)
{	
	cprintf("Enter hb_disconnect_main, reason [%ld]\n", atol(argv[3]));
	
	//openlog("heartbeat" ,LOG_PID, LOG_DAEMON);
	/*
	//delete udp:5050 from iptable
	snprintf(buf, sizeof(buf), "iptables -D INPUT -d %s -i %s -p udp --dport %d -j %s", 
		   nvram_safe_get("wan0_ipaddr"), 
		   nvram_safe_get("wan0_ifname"),   //vlan1
		   5050, 
		   "ACCEPT");
	cprintf("\nExecuting external command: \n%s\n",buf);
	system(buf);
	*/
	
	//stop_wan();
	//stop_heartbeat();
	//logout_heartbeat();  //dvd.chen
	DelHASPort( argv[1], argv[2] );

	
	if ((atoi(nvram_get("auto_connect")) == 1) && (atoi(nvram_get("wan_tel_manualHangup")) == 0)) {
		AddDemandRoute(5, 1);
	}
	//log bpalogin wan_down here
	//log_WAN_connect("WAN Telstra BigPond Disconnected");
	setLedLight(WAN_LED, LED_AMBER);	
		
	return unlink(PPP_LINK_PATH"bpa");	/* /tmp/ppp/link.ppp0 */
}

//note by dvd.chen, these defines are org in rtl8651_tblDrv.h
#define PS_ACTION_CLIENT 1
#define PS_ACTION_DONT_TIMEOUT 3
void AddHASPort( char *hasIP, char *heartbeatPort)
{
#if 0
	//-A input_accept -i eth1 -p udp --dport 5050 -m state --state NEW -j ACCEPT 
	char *argvec[] = { "/sbin/iptables", "-A", IPTC_INPUT_ACCEPT, "-i", NULL, 
					"-p", "udp", "--destination-port", NULL, 
					"-m", "state", "--state",  "NEW", "-j", "ACCEPT", NULL};
	argvec[4] = nvram_safe_get("wan0_ifname");
	argvec[8] = heartbeatPort;
	vEval( argvec );
#else
	int ret;

	//To make udp-5050 NOT update the registered idle_timeer, make idle_timeout work properly  
	ret = rtl8651_addProtoStackActions(0,0xffffffff,PS_ACTION_DONT_TIMEOUT,PS_ACTION_CLIENT,IPPROTO_UDP,5050,5050);
	if(ret)
		cprintf("%s::rtl8651_addProtoStackActions FAILED,ret[%d]\n", __FUNCTION__, ret);
	else
		cprintf("%s::rtl8651_addProtoStackActions SUCCEED\n", __FUNCTION__);
#endif
}

void DelHASPort( char *hasIP, char *heartbeatPort)
{
#if 0
	//-D input_accept -i eth1 -p udp --dport 5050 -m state --state NEW -j ACCEPT
	char *argvec[] = { "/sbin/iptables", "-D", IPTC_INPUT_ACCEPT, "-i", NULL, 
					"-p", "udp", "--destination-port", NULL, 
					"-m", "state", "--state",  "NEW", "-j", "ACCEPT", NULL};
	argvec[4] = nvram_safe_get("wan0_ifname");
	argvec[8] = heartbeatPort;
	vEval( argvec );
#else
	int ret;

	//ret = rtl8651_delProtoStackActions(ipaddr_t lowerIp, ipaddr_t upperIp, uint8 action, uint8 role, uint8 protocol, uint16 orgPort, uint16 fwdPort)
	if(ret)
		cprintf("%s::rtl8651_delProtoStackActions FAILED, ret[%d]\n", __FUNCTION__,ret);
	else
		cprintf("%s::rtl8651_delProtoStackActions SUCCEED\n", __FUNCTION__);
#endif
}

