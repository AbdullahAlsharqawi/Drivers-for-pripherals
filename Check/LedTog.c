

#include "STD_TYPES.h"
#include "Led.h"
#include "LedTog.h"


void void_TogglingLedInitialize(void)
{
	
}

void LEDToggle_Task(void)
{
	static boolean PreviousLedStatus = 0;
	if(PreviousLedStatus )
	{
		PreviousLedStatus=0;
		LED_voidSetLED(LED_1, ON);
	}
	else
	{
		PreviousLedStatus=1;
		LED_voidSetLED(LED_1, OFF);
	}
	
}
