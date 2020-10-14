

#include "STD_TYPES.h"
#include "LedTog.h"
#include "ButtonApp.h"
#include "KEYPAD7SEGAPP.h"
#include "OS_cfg.h"


const OS_cfg_t  OS_cfg[]=
{
	{LEDToggle_Task,1},
	{ButtonApp_Task,2},
	{KPSeg_Task,200}
};


