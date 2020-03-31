/*
 *	@(#)pathnames.h	5.3 (Berkeley) 5/9/89
 *
 * Heavily modified by poe@daimi.aau.dk for Linux
 */

#include <paths.h>

#ifndef __STDC__
 # error "we need an ANSI compiler"
#endif

#define _PATH_BSHELL    "/bin/sh"
#define _PATH_CSHELL    "/bin/csh"
#define _PATH_TTY       "/dev/tty"
#define TTYTYPES        "/etc/ttytype"
#define SECURETTY       "/etc/securetty"

#define	_PATH_HUSHLOGIN	".hushlogin"
#define	_PATH_MOTDFILE	"/etc/motd"
#define	_PATH_NOLOGIN	"/etc/nologin"

#define _PATH_LOGIN	"/bin/login"
#define _PATH_INITTAB	"/etc/inittab"
#define _PATH_RC	"/etc/rc"
#define _PATH_REBOOT	"/sbin/reboot"
#define _PATH_SINGLE	"/etc/singleboot"
#define _PATH_SECURE	"/etc/securesingle"
#define _PATH_USERTTY   "/etc/usertty"

#define PPP_LINK_PATH "/var/run/link."
#define PID_PATH "/var/run/"
#define FW_UPDATE_URL_125G ""
#define FW_UPDATE_URL_54G ""