/*
 * libc/stdlib/malloc/realloc.c -- realloc function
 *
 *  Copyright (C) 2002  NEC Corporation
 *  Copyright (C) 2002  Miles Bader <miles@gnu.org>
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License.  See the file COPYING.LIB in the main
 * directory of this archive for more details.
 * 
 * Written by Miles Bader <miles@gnu.org>
 */

#include <stdlib.h>
#include <string.h>

#include "malloc.h"
#include "heap.h"


void *
realloc (void *mem, size_t new_size)
{
  size_t size;
  char *base_mem;

  /* Check for special cases.  */
  if (! new_size)
    {
      free (mem);
      return 0;
    }
  else if (! mem)
    return malloc (new_size);

  /* Normal realloc.  */

  base_mem = MALLOC_BASE (mem);
  size = MALLOC_SIZE (mem);

  /* Include extra space to record the size of the allocated block.
     Also make sure that we're dealing in a multiple of the heap
     allocation unit (SIZE is already guaranteed to be so).*/
  new_size = HEAP_ADJUST_SIZE (new_size + MALLOC_HEADER_SIZE);

  MALLOC_DEBUG ("realloc: 0x%lx, %d (base = 0x%lx, total_size = %d)\n",
		(long)mem, new_size, (long)base_mem, size);

  if (new_size > size)
    /* Grow the block.  */
    {
      size_t extra = new_size - size;

      __malloc_lock ();
      extra = __heap_alloc_at (&__malloc_heap, base_mem + size, extra);
      __malloc_unlock ();

      if (extra)
	/* Record the changed size.  */
	MALLOC_SET_SIZE (base_mem, new_size);
      else
	/* Our attempts to extend MEM in place failed, just
	   allocate-and-copy.  */
	{
	  void *new_mem = malloc (new_size - MALLOC_HEADER_SIZE);
	  if (new_mem)
	    {
	      memcpy (new_mem, mem, size - MALLOC_HEADER_SIZE);
	      free (mem);
	    }
	  mem = new_mem;
	}
    }
  else if (new_size + MALLOC_REALLOC_MIN_FREE_SIZE <= size)
    /* Shrink the block.  */
    {
      __malloc_lock ();
      __heap_free (&__malloc_heap, base_mem + new_size, size - new_size);
      __malloc_unlock ();
      MALLOC_SET_SIZE (base_mem, new_size);
    }

  if (mem)
    MALLOC_DEBUG ("  realloc: returning 0x%lx"
		  " (base:0x%lx, total_size:%d)\n",
		  (long)mem, (long)MALLOC_BASE(mem), (long)MALLOC_SIZE(mem));

  return mem;
}
