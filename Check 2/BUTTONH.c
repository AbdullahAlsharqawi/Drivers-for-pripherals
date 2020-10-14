
#include "STD_TYPES.h"
#include "DIO_int.h"
#include "BUTTONH.h"


static u8 button;
static boolean CheckButton;

extern void Button_voidInitialise(void)
{
	CheckButton=0;
	MapButton(button_1);
	
}

static void MapButton(u8 Copy_u8Button)
{
	switch (Copy_u8Button)
	{
		case button_1:
			button=DIO_u8_PIN_10;
		break;
	} 
}
extern boolean Button_booleanGetStatus(u8 Copy_u8Button)
{
	
	MapButton(Copy_u8Button);
	return CheckButton;
}

extern void Bouncing_Task(void)
{
	static u8 counter=0;
	static boolean previousState=0,currentState=0;
	currentState=DIO_u8GetPinValue(button);
	
	if (previousState==currentState)
	{
		counter++;
		if(counter==5)
		{
			CheckButton=currentState;
			counter=0;
		}
	}
	else
	{
		counter=0;
	}
}
