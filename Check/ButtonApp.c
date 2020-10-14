


#include "STD_TYPES.h"
#include "DIO_int.h"
#include "BUTTONH.h"
#include "LED.h"


extern void ButtonApp_voidInitialize(void)
{
	
	
}





extern void ButtonApp_Task(void)  //periodicity = 25ms
{
	static u8 counter=0;
	static boolean previousState=0,currentState=0;
	currentState=Button_booleanGetStatus(button_1);
	
	if (previousState==currentState)
	{
		counter++;
		if(counter==40)
		{
			while(Button_booleanGetStatus(button_1) == 1)
			{
				LED_voidSetLED(LED_2, ON);
			}
			LED_voidSetLED(LED_2, OFF);
			counter=0;
		}
	}
	else
	{
		counter=0;
	}
}