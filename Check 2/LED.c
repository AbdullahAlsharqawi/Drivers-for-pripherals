

#include "STD_TYPES.h"
#include "DIO_int.h"
#include "LED.h"

extern void LED_voidInitialize(void)
{
	DIO_voidSetPinValue(DIO_u8_PIN_12,DIO_u8_LOW);
	DIO_voidSetPinValue(DIO_u8_PIN_11,DIO_u8_LOW);
}

extern void LED_voidSetLED(u8 Copy_u8LED, u8 Copy_u8State)
{
	if(Copy_u8LED == LED_1)
	{
		if(Copy_u8State == ON)
		{
			DIO_voidSetPinValue(DIO_u8_PIN_12,DIO_u8_HIGH);
		}
		else if(Copy_u8State == OFF)
		{
			DIO_voidSetPinValue(DIO_u8_PIN_12,DIO_u8_LOW);
		}	
	}
	else if(Copy_u8LED == LED_2)
	{
		if(Copy_u8State == ON)
		{
			DIO_voidSetPinValue(DIO_u8_PIN_11,DIO_u8_HIGH);
		}
		else if(Copy_u8State == OFF)
		{
			DIO_voidSetPinValue(DIO_u8_PIN_11,DIO_u8_LOW);
		}
	}
}

