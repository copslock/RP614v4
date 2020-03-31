#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>

#include "rc.h"
#include <dni_nvram.h>
#include <dni_shutils.h>

static void restore_default(void);
static void rc_signal(int sig);

extern struct nvram_tuple router_defaults[];

#define dprintf		printf
#define cprintf		printf

static void
restore_default(void)
{

}

static void
sysinit(void)
{
	time_t tm = 0;
	dprintf("done\n");
}

/* States */
enum {
	RESTART,
	STOP,
	START,
	TIMER,
	IDLE,
};
static int state = START;
static int signalled = -1;

/* Signal handling */
static void
rc_signal(int sig)
{
	if (state == IDLE) {	
		if (sig == SIGHUP) {
			dprintf("signalling RESTART\n");			
			sleep(3);			
			signalled = RESTART;
		}
		else if (sig == SIGUSR2) {
			dprintf("signalling START\n");
			signalled = START;
		}
		else if (sig == SIGINT) {
			dprintf("signalling STOP\n");
			signalled = STOP;
		}
		else if (sig == SIGALRM) {
			dprintf("signalling TIMER\n");
			signalled = TIMER;
		}
	}
}

/* Timer procedure */
int
do_timer(void)
{
	int interval = atoi(nvram_safe_get("timer_interval"));
	
//	time_t now;
//	struct tm gm, local;
//	struct timezone tz;
	static int do_timer_times=0;

	dprintf("%d\n", interval);

	if (interval == 0)
		interval = 60*60;

	cprintf("%s::do_timer_times:%d\n", __FUNCTION__, do_timer_times);
	/* Sync time */
	//modified by dvd.chen to, sync ntp time every 12 hours
	if( ((do_timer_times % (12*60*60))==0) )  //every 12 hours
		//start_ntpc();

	do_timer_times += interval;
	
	alarm(interval);
	return 0;
}

void run_CheckWan()
{
	char *argv[] = {
		"CheckWan",
		NULL
	};
	int pid;

	cprintf("%s\n", __FUNCTION__);
	_eval(argv, NULL, 0, &pid);
}

/* Main loop */
void
main_loop(void)
{
	sigset_t sigset;
	pid_t pid;

	/* Basic initialization */
	sysinit();

	/* Setup signal handlers */
	signal_init();
	signal(SIGHUP, rc_signal);
	signal(SIGUSR2, rc_signal);
	signal(SIGINT, rc_signal);
	signal(SIGALRM, rc_signal);
	sigemptyset(&sigset);

	/* Restore defaults if necessary */
	//restore_default();
	setenv("hostname","localhost",1);
	//run_CheckWan();		/* pooling  to set wan_link led */

	/* Loop forever */
	for (;;) {
		switch (state) {
		case RESTART:
			dprintf("RESTART\n");
			setLedLight(TEST_LED, LED_ON);			
			/* Fall through */
		case STOP:
			dprintf("STOP\n");			

			//stop_services();

			stop_wan();
			setLedLight(WAN_LED, LED_AMBER);

			if (state == STOP) {
				state = IDLE;
				break;
			}
			/* Fall through */
		case START:
			dprintf("START\n");
			//start_lan();		
			//start_services();
			setLedLight(WAN_LED, LED_AMBER);
			//setLedLight(TEST_LED, LED_ON);
			//setLedLight(TEST_LED, LED_OFF);	
			system_restart();					
			/* Fall through */
		case TIMER:
			dprintf("TIMER\n");
			do_timer();
			/* Fall through */
		case IDLE:
			dprintf("IDLE\n");
			signalled = state = IDLE;
			/* Wait for user input or state change */
			sigsuspend(&sigset);
			state = signalled;

			signalled = -1;
			break;
		default:
			dprintf("state[%d]::UNKNOWN\n", state);
			return;
		}
	}
}

