/*
 * define path names
 *
 * $Id: pathnames.h,v 1.1 2005/10/21 13:14:16 tony Exp $
 */

#ifdef HAVE_PATHS_H
#include <paths.h>

#else /* HAVE_PATHS_H */
#ifndef _PATH_VARRUN
#define _PATH_VARRUN 	"/var/run/"
#endif
#define _PATH_DEVNULL	"/dev/null"
#endif /* HAVE_PATHS_H */

#ifndef _ROOT_PATH
#define _ROOT_PATH
#endif


#define RTL865X 1
#if RTL865X
#define _PATH_TEMP      "/etc/config/resolv.XXXXXX"
#endif

#define _PATH_UPAPFILE 	 _ROOT_PATH "/etc/config/pap-secrets"
#define _PATH_CHAPFILE 	 _ROOT_PATH "/etc/config/chap-secrets"
#define _PATH_SRPFILE 	 _ROOT_PATH "/etc/config/srp-secrets"
#define _PATH_SYSOPTIONS _ROOT_PATH "/var/ppp/options"
#define _PATH_IPUP	 _ROOT_PATH "/bin/ip-up"
#define _PATH_IPDOWN	 _ROOT_PATH "/bin/ip-down"
#define _PATH_AUTHUP	 _ROOT_PATH "/bin/auth-up"
#define _PATH_AUTHDOWN	 _ROOT_PATH "/bin/auth-down"
#define _PATH_TTYOPT	 _ROOT_PATH "/var/ppp/options."
#define _PATH_CONNERRS	 _ROOT_PATH "/var/ppp/connect-errors"
#define _PATH_PEERFILES	 _ROOT_PATH "/var/ppp/peers/"
#define _PATH_RESOLV	 _ROOT_PATH "/var/resolv.conf"

#define _PATH_USEROPT	 ".ppprc"
#define	_PATH_PSEUDONYM	 ".ppp_pseudonym"

#ifdef INET6
#define _PATH_IPV6UP     _ROOT_PATH "/bin/ipv6-up"
#define _PATH_IPV6DOWN   _ROOT_PATH "/bin/ipv6-down"
#endif

#ifdef IPX_CHANGE
#define _PATH_IPXUP	 _ROOT_PATH "/bin/ipx-up"
#define _PATH_IPXDOWN	 _ROOT_PATH "/bin/ipx-down"
#endif /* IPX_CHANGE */

#ifdef __STDC__
#define _PATH_PPPDB	_ROOT_PATH _PATH_VARRUN "pppd2.tdb"
#else /* __STDC__ */
#ifdef HAVE_PATHS_H
#define _PATH_PPPDB	"/var/run/pppd2.tdb"
#else
#define _PATH_PPPDB	"/etc/config/pppd2.tdb"
#endif
#endif /* __STDC__ */

#ifdef PLUGIN
#define _PATH_PLUGIN	"/usr/lib/pppd/" VERSION
#endif /* PLUGIN */
