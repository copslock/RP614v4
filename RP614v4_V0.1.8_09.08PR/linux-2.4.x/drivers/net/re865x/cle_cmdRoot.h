#ifndef __CLE_CMD_H__
#define __CLE_CMD_H__

#ifdef CONFIG_RTL865XB_EXP_PERFORMANCE_EVALUATION
	void   clearCOP3Counters(void);
	void   startCOP3Counters(int32 countInst);
	uint32 stopCOP3Counters(void);
	void   DisplayCOP3Counters(void);
	void   pauseCOP3Counters(void);
#endif

#endif
