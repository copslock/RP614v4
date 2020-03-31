/*
 * Router rc control script
 *
 */

#ifndef _rc_h_
#define _rc_h_

#include <netinet/in.h>
#include <pathnames.h>

#define IFUP (IFF_UP | IFF_RUNNING | IFF_BROADCAST | IFF_MULTICAST)

#define	HEARBEAT_LOCAL_PORT		(5050)

#define sin_addr(s) (((struct sockaddr_in *)(s))->sin_addr)

/* init */
extern int console_init(void);
extern pid_t run_shell(int timeout, int nowait);
extern void signal_init(void);
extern void fatal_signal(int sig);

extern void start_wan(void);
extern void stop_wan(void);
extern void main_loop(void);

#endif /* _rc_h_ */
