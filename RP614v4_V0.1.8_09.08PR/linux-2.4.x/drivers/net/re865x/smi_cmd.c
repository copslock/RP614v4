

#include "rtl865x/rtl_types.h"
#include "cle/rtl_cle.h" 
#include "voip/spi/gpio.h"
#include "smi_cmd.h"
#include "smi.h"
#include "rtl865x/assert.h"
#include <linux/string.h>






static int32 _smiCmd(uint32 userId,  int32 argc, int8 **saved)
{
	int32 size;
	int8 *nextToken;
	uint32 start_addr, rData=0;

	cle_getNextCmdToken(&nextToken,&size,saved); 
	if (!strcmp(nextToken, "read")) {
		cle_getNextCmdToken(&nextToken,&size,saved); 
		start_addr = U32_value(nextToken);

		smi_init(GPIO_PORT_C, 1, 0);
		smi_read(start_addr, &rData);
		


		

	}
	else if (!strcmp(nextToken, "write")) {
		printk("smi write command......\n");

	}
	else return FAILED;
	return SUCCESS;
}








cle_exec_t smi_cmds[] = {

	{	"memory",
		"read/write memory through SMI Interface",
		"{ read'read memory from specified address through SMI' %d'base address' %d'Length' | write'write memory to the specified address through SMI' %d'base address' %d'2-byte value' }",
		_smiCmd,
		CLE_USECISCOCMDPARSER,	
		0,
		NULL
	},
};











