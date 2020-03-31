/* pty.c ....... find a free pty/tty pair.  
 *               Inspired/stolen from the xterm source.
 *               NOTE: This is very likely to be highly non-portable.
 *               C. Scott Ananian <cananian@alumni.princeton.edu>
 *
 * $Id: pty.c,v 1.2 2004/10/28 11:09:31 chenyl Exp $
 */

#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include "pty.h"

int getpseudotty(char *ttydev, char *ptydev) {
  /* define static variables so we can call multiple times and get
   * different tty/pty pairs each time.
   */
  static int devindex=0, letter=0;
  int olddevindex=0, oldletter=0;
  int fd;

  strcpy(ttydev, TTYDEV);
  strcpy(ptydev, PTYDEV);
  
  olddevindex = devindex;
  oldletter = letter;

  do
  {
	  while (PTYCHAR1[letter]) {
	    ttydev[strlen(ttydev)-2] = ptydev[strlen(ptydev)-2] = PTYCHAR1[letter];

	    while (PTYCHAR2[devindex]) {
	      ttydev[strlen(ttydev)-1] = ptydev[strlen(ptydev)-1] = PTYCHAR2[devindex];
	      /* next time, use next index: */
	      devindex++;
	      if ((fd = open(ptydev, O_RDWR)) >= 0)
		return fd;
	    }
	    devindex = 0;
	    letter++;
	  }
	  devindex = 0;
	  letter = 0;
  } while ((devindex != olddevindex) || (letter != oldletter));

  return -1; /* unable to allocate pty!! */
}
