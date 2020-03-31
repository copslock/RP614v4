

#include "rtl865x/rtl_types.h"
#include "voip/spi/gpio.h"
#include "smi.h"


#define DELAY						1000
#define CLK_DURATION(clk)				{ int i; for(i=0; i<clk; i++); }
#define _SMI_ACK_RESPONSE(ok)		{ if (!(ok)) return FAILED; }


gpioID smi_SCK;		/* GPIO used for SMI Clock Generation */
gpioID smi_SDA;		/* GPIO used for SMI Data signal */






#if 0
void _smi_start(void)
{
	/* initial state */
	_rtl865x_setGpioDataBit(smi_SCK, 0);
	_rtl865x_setGpioDataBit(smi_SDA, 1);
	CLK_DURATION(DELAY);

	/* CLK 1: 0 -> 1, 1 -> 0 */
	_rtl865x_setGpioDataBit(smi_SCK, 1);
	CLK_DURATION(DELAY);
	_rtl865x_setGpioDataBit(smi_SCK, 0);
	CLK_DURATION(DELAY);

	/* CLK 2: */
	_rtl865x_setGpioDataBit(smi_SCK, 1);
	CLK_DURATION(DELAY);
	_rtl865x_setGpioDataBit(smi_SDA, 0);
	CLK_DURATION(DELAY);
	_rtl865x_setGpioDataBit(smi_SCK, 0);
	CLK_DURATION(DELAY);
	_rtl865x_setGpioDataBit(smi_SDA, 1);
	CLK_DURATION(DELAY);

	/* CLK 3: */
	_rtl865x_setGpioDataBit(smi_SCK, 1);
	CLK_DURATION(DELAY);
	_rtl865x_setGpioDataBit(smi_SCK, 0);
	CLK_DURATION(DELAY);
	_rtl865x_setGpioDataBit(smi_SDA, 0);
	CLK_DURATION(DELAY);

	/* CLK 4: */
	_rtl865x_setGpioDataBit(smi_SCK, 1);
	CLK_DURATION(DELAY);
	_rtl865x_setGpioDataBit(smi_SCK, 0);
	CLK_DURATION(DELAY);
	_rtl865x_setGpioDataBit(smi_SDA, 1);
	CLK_DURATION(DELAY);
	
	/* CLK 5: */
	_rtl865x_setGpioDataBit(smi_SCK, 1);
	CLK_DURATION(DELAY);
	_rtl865x_setGpioDataBit(smi_SCK, 0);
	CLK_DURATION(DELAY);
	_rtl865x_setGpioDataBit(smi_SDA, 0);
	CLK_DURATION(DELAY);

	/* CLK 6: */
	_rtl865x_setGpioDataBit(smi_SCK, 1);
	CLK_DURATION(DELAY);
	_rtl865x_setGpioDataBit(smi_SCK, 0);
	CLK_DURATION(DELAY);
	_rtl865x_setGpioDataBit(smi_SDA, 1);
	CLK_DURATION(DELAY);
	
	/* CLK 7: */
	_rtl865x_setGpioDataBit(smi_SCK, 1);
	CLK_DURATION(DELAY);
	_rtl865x_setGpioDataBit(smi_SCK, 0);
	CLK_DURATION(DELAY);
	_rtl865x_setGpioDataBit(smi_SDA, 0);
	CLK_DURATION(DELAY);

	/* CLK 8: */
	_rtl865x_setGpioDataBit(smi_SCK, 1);
	CLK_DURATION(DELAY);
	_rtl865x_setGpioDataBit(smi_SCK, 0);
	CLK_DURATION(DELAY);
	
}

#endif


void _smi_start(void)
{
	/* Initial state: SCK: 0, SDA: 1 */
	_rtl865x_setGpioDataBit(smi_SCK, 0);
	_rtl865x_setGpioDataBit(smi_SDA, 1);
	CLK_DURATION(DELAY);

	/* CLK 1: 0 -> 1, 1 -> 0 */
	_rtl865x_setGpioDataBit(smi_SCK, 1);
	CLK_DURATION(DELAY);
	_rtl865x_setGpioDataBit(smi_SCK, 0);
	CLK_DURATION(DELAY);

	/* CLK 2: */
	_rtl865x_setGpioDataBit(smi_SCK, 1);
	CLK_DURATION(DELAY);
	_rtl865x_setGpioDataBit(smi_SDA, 0);
	CLK_DURATION(DELAY);
	_rtl865x_setGpioDataBit(smi_SCK, 0);
	CLK_DURATION(DELAY);
	_rtl865x_setGpioDataBit(smi_SDA, 1);

}



void _smi_writeBit(uint16 signal, uint32 bitLen)
{
	for( ; bitLen > 0; bitLen--) {
		CLK_DURATION(DELAY);
		/* prepare data */
		if ( signal&(1<<(bitLen-1)) ) 
			_rtl865x_setGpioDataBit(smi_SDA, 1);	
		else _rtl865x_setGpioDataBit(smi_SDA, 0);	
		CLK_DURATION(DELAY);

if ( signal&(1<<(bitLen-1)) ) 
	printk("1\n");
else printk("0\n");	

		/* clocking */
		_rtl865x_setGpioDataBit(smi_SCK, 1);
		CLK_DURATION(DELAY);
		_rtl865x_setGpioDataBit(smi_SCK, 0);
	}
}



void _smi_readBit(uint32 bitLen, uint32 *rData) 
{
	uint32 u;

	/* change GPIO pin to Input only */
	_rtl865x_initGpioPin(smi_SDA, GPIO_PERI_GPIO, GPIO_DIR_IN, GPIO_INT_DISABLE);
	for(*rData=0; bitLen>0; bitLen--) {
		CLK_DURATION(DELAY);
		/* clocking */
		_rtl865x_setGpioDataBit(smi_SCK, 1);
		CLK_DURATION(DELAY);
		_rtl865x_getGpioDataBit(smi_SDA, &u);
		_rtl865x_setGpioDataBit(smi_SCK, 0);
printk("========>%d\n", u);		
		*rData |= (u << (bitLen-1));
	}
	/* change GPIO pin to Output only */
	_rtl865x_initGpioPin(smi_SDA, GPIO_PERI_GPIO, GPIO_DIR_OUT, GPIO_INT_DISABLE);
}



void _smi_stop(void)
{
	_rtl865x_setGpioDataBit(smi_SDA, 1);	
	CLK_DURATION(DELAY);
	_rtl865x_setGpioDataBit(smi_SCK, 1);
	CLK_DURATION(DELAY);
	_rtl865x_setGpioDataBit(smi_SCK, 0);
	CLK_DURATION(DELAY);
	_rtl865x_setGpioDataBit(smi_SCK, 1);
}





int32 smi_init(uint32 port, uint32 pinSCK, uint32 pinSDA)
{
	gpioID gpioId;
	int32 res;

	/* Initialize GPIO port C, pin 0 as SMI SDA0 */
	gpioId = GPIO_ID(port, pinSDA);
	res = _rtl865x_initGpioPin(gpioId, GPIO_PERI_GPIO, GPIO_DIR_OUT, GPIO_INT_DISABLE);
	if (res != SUCCESS)
		return res;
	smi_SDA = gpioId;

	/* Initialize GPIO port C, pin 1 as SMI SCK0 */
	gpioId = GPIO_ID(port, pinSCK);
	res = _rtl865x_initGpioPin(gpioId, GPIO_PERI_GPIO, GPIO_DIR_OUT, GPIO_INT_DISABLE);
	if (res != SUCCESS)
		return res;
	smi_SCK = gpioId;
	return SUCCESS;
	
}




int32 smi_read(uint32 mAddrs, uint32 *rData)
{
	uint32 rawData=0, ACK;

printk("111111111111\n");

	_smi_start();								/* Start SMI */
	_smi_writeBit(0x0a, 4); 						/* CTRL code: 4'b1010 */
	_smi_writeBit(0x4, 3);						/* CTRL code: 3'b100 */
	_smi_writeBit(0x1, 1);						/* 1: issue READ command */
	_smi_readBit(1, &ACK);						/* ACK for issuing READ command*/
printk("aaaaaaaaaaaaa: ACK = %d\n", ACK);
	_SMI_ACK_RESPONSE(ACK==0);
printk("bbbbbbbbbbbbbb\n");
	_smi_writeBit((mAddrs&0xff), 8); 				/* Set reg_addr[7:0] */
	_smi_readBit(1, &ACK);						/* ACK for setting reg_addr[7:0] */	
	_SMI_ACK_RESPONSE(ACK==0);
printk("ccccccccccccc\n");
	_smi_writeBit((mAddrs>>8), 8); 				/* Set reg_addr[15:8] */
	_smi_readBit(19, &rawData);					/* 1-bit ACK + read data [7:0] + 1-bit ACK + data[15:8] + 1-bit ACK */
	_SMI_ACK_RESPONSE(((rawData&0x040000)==0) && ((rawData&0x200)==0) && ((rawData&0x01)==1));
printk("dddddddddddddddd\n");
	_smi_stop();
	*rData = ((rawData>>10)&0xff) | ((rawData>>1)&0xff);
printk("==>%x\n", 	rawData);

	return SUCCESS;
	
}



int32 smi_write(uint16 mAddrs, uint16 rData)
{
	uint32 ACK;
	
	_smi_start();								/* Start SMI */
	_smi_writeBit(0x0a, 4); 						/* CTRL code: 4'b1010 */
	_smi_writeBit(0x4, 3);						/* CTRL code: 3'b100 */
	_smi_writeBit(0x1, 0);						/* 0: issue WRITE command */
	_smi_readBit(1, &ACK);						/* ACK for issuing WRITE command*/
	_SMI_ACK_RESPONSE(ACK==0);
	_smi_writeBit((mAddrs&0xff), 8); 				/* Set reg_addr[7:0] */
	_smi_readBit(1, &ACK);						/* ACK for setting reg_addr[7:0] */
	_SMI_ACK_RESPONSE(ACK==0);
	_smi_writeBit((mAddrs>>8), 8); 				/* Set reg_addr[15:8] */
	_smi_readBit(1, &ACK);						/* ACK for setting reg_addr[15:8] */
	_SMI_ACK_RESPONSE(ACK==0);
	_smi_writeBit(rData&0xff, 8);				/* Write Data [7:0] out */
	_smi_readBit(1, &ACK);						/* ACK for writting data [7:0] */
	_SMI_ACK_RESPONSE(ACK==0);
	_smi_writeBit(rData>>8, 8);					/* Write Data [15:8] out */
	_smi_readBit(1, &ACK);						/* ACK for writting data [15:8] */
	_SMI_ACK_RESPONSE(ACK==1);
	_smi_stop();	
	
	return SUCCESS;

}







