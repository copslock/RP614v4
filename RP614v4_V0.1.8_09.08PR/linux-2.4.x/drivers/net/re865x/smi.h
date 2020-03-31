

#ifndef __SMI_H__
#define __SMI_H__


typedef uint32 gpioID;


int32 smi_init(uint32 port, uint32 pinSCK, uint32 pinSDA);
int32 smi_read(uint32 mAddrs, uint32 *rData);
int32 smi_write(uint16 mAddrs, uint16 rData);


#endif /* __SMI_H__ */


