/*
 * $Id: md5.c,v 1.1 2005/10/21 13:14:16 tony Exp $
 */
#include "md5.h"

void rc_md5_calc (unsigned char *output, unsigned char *input, unsigned int inlen)
{
	MD5_CTX         context;

	MD5_Init (&context);
	MD5_Update (&context, input, inlen);
	MD5_Final (output, &context);
}
