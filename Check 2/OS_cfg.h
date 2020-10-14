

#ifndef _OS_CFG_H_
#define _OS_CFG_H_


typedef struct 
{
	void (*pf) (void);
	u16 periodicity;
}OS_cfg_t;

extern const OS_cfg_t  OS_cfg[];


#endif
