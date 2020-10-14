

#include "STD_TYPES.h"
#include "GIE_int.h"
#include "TIMER.h"
#include "OS.h"

static boolean flag;
static u32 tick;

static void ISR(void);

void OS_Initialize(void)
{
	flag=0;
	tick=0;
	TIMER0_voidSetMode(Clear_OC0_On_Compare_Match);
	voidsetPrescaler(TIM0_DIV_64);
	TIMER0_SetCallbackFunc(ISR);
	TIMER0_voidSetCompareValue(100);  
	TIMER0_voidEnableCompareMatch();
	GIE_voidEnable();
}


void OS_Start(void)
{
	while(1)
	{
		for(int i=0;i<3; i++)
		{
			if(tick%OS_cfg[i].periodicity == 0)
			{
				OS_cfg[i].pf();
			}
		}
	}
}



void ISR(void)
{
	flag=1;
	tick++;
}
