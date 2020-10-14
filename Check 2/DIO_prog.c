/********************************************/
/* 	Author 	: 	zeinab ali         			*/
/*	Date 	:	25/1/2018			 		*/
/*	version	:	V01							*/
/********************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_reg.h"
#include "DIO_priv.h"
#include "DIO_config.h"
#include "DIO_int.h"


/**/
#define DIO_GROUPA_DIRECTIONS    CONCBIT(DIO_u8_PIN_DIR_7,DIO_u8_PIN_DIR_6,DIO_u8_PIN_DIR_5,DIO_u8_PIN_DIR_4,DIO_u8_PIN_DIR_3,DIO_u8_PIN_DIR_2,DIO_u8_PIN_DIR_1,DIO_u8_PIN_DIR_0)
#define DIO_GROUPB_DIRECTIONS    CONCBIT(DIO_u8_PIN_DIR_15,DIO_u8_PIN_DIR_14,DIO_u8_PIN_DIR_13,DIO_u8_PIN_DIR_12,DIO_u8_PIN_DIR_11,DIO_u8_PIN_DIR_10,DIO_u8_PIN_DIR_9,DIO_u8_PIN_DIR_8)
#define DIO_GROUPC_DIRECTIONS    CONCBIT(DIO_u8_PIN_DIR_23,DIO_u8_PIN_DIR_22,DIO_u8_PIN_DIR_21,DIO_u8_PIN_DIR_20,DIO_u8_PIN_DIR_19,DIO_u8_PIN_DIR_18,DIO_u8_PIN_DIR_17,DIO_u8_PIN_DIR_16)
#define DIO_GROUPD_DIRECTIONS    CONCBIT(DIO_u8_PIN_DIR_31,DIO_u8_PIN_DIR_30,DIO_u8_PIN_DIR_29,DIO_u8_PIN_DIR_28,DIO_u8_PIN_DIR_27,DIO_u8_PIN_DIR_26,DIO_u8_PIN_DIR_25,DIO_u8_PIN_DIR_24)

/********************************************/
/*Description: This function shall set		*/
/*				directions for IO Pins		*/
/********************************************/
void DIO_voidInitialize(void)
{
		DDRA = 	DIO_GROUPA_DIRECTIONS;
		DDRB =	DIO_GROUPB_DIRECTIONS;
		DDRC =	DIO_GROUPC_DIRECTIONS;
		DDRD = 	DIO_GROUPD_DIRECTIONS;
}

/********************************************/
/*Description: This function shall set		*/
/*				digital value for IO Pins	*/
/********************************************/
void DIO_voidSetPinValue(u8 Copy_u8_PinIndx, u8 Copy_Pin_Val)
{
	if 			( (Copy_u8_PinIndx >= DIO_u8_PORTA_START)&& (Copy_u8_PinIndx <= DIO_u8_PORTA_END) )
	{
		if (Copy_Pin_Val == DIO_u8_HIGH)
		{
			SETBIT(PORTA,Copy_u8_PinIndx);
		}
		
		else
		{
			CLRBIT(PORTA,Copy_u8_PinIndx);
		}
		
	}
	
	else if		( (Copy_u8_PinIndx >= DIO_u8_PORTB_START) && (Copy_u8_PinIndx <= DIO_u8_PORTB_END) )
	{
		Copy_u8_PinIndx -= DIO_u8_PORTA_SIZE;
		if (Copy_Pin_Val == DIO_u8_HIGH)
		{
			SETBIT(PORTB,Copy_u8_PinIndx);
		}
		
		else
		{
			CLRBIT(PORTB,Copy_u8_PinIndx);
		}
	}
	
	else if		( (Copy_u8_PinIndx >= DIO_u8_PORTC_START) && (Copy_u8_PinIndx <= DIO_u8_PORTC_END) )
	{
		Copy_u8_PinIndx -= (DIO_u8_PORTA_SIZE + DIO_u8_PORTB_SIZE);
		if (Copy_Pin_Val == DIO_u8_HIGH)
		{
			SETBIT(PORTC,Copy_u8_PinIndx);
		}
		
		else
		{
			CLRBIT(PORTC,Copy_u8_PinIndx);
		}
	}
	
	else if		( (Copy_u8_PinIndx >= DIO_u8_PORTD_START) && (Copy_u8_PinIndx <= DIO_u8_PORTD_END) )
	{
		Copy_u8_PinIndx = Copy_u8_PinIndx-DIO_u8_PORTA_SIZE-DIO_u8_PORTB_SIZE-DIO_u8_PORTD_SIZE;
		if (Copy_Pin_Val == DIO_u8_HIGH)
		{
			SETBIT(PORTD,Copy_u8_PinIndx);
		}
		
		else
		{
			CLRBIT(PORTD,Copy_u8_PinIndx);
		}
	}

}



u8 DIO_u8GetPinValue(u8 Copy_u8_PinIndx)
{
	u8 Local_u8Result;
	if( (Copy_u8_PinIndx >= DIO_u8_PORTA_START)&& (Copy_u8_PinIndx <= DIO_u8_PORTA_END) )
	{
		if(GETBIT(PINA,Copy_u8_PinIndx) )
		{
			 Local_u8Result=DIO_u8_HIGH;
		}

		else
		{
			Local_u8Result= DIO_u8_LOW;
		}

	}

	else if		( (Copy_u8_PinIndx >= DIO_u8_PORTB_START) && (Copy_u8_PinIndx <= DIO_u8_PORTB_END) )
	{
		Copy_u8_PinIndx -= DIO_u8_PORTA_SIZE;
		if(GETBIT(PINB,Copy_u8_PinIndx))
		{
			 Local_u8Result=DIO_u8_HIGH;
		}

		else
		{
			Local_u8Result= DIO_u8_LOW;
		}
	}
	else if		( (Copy_u8_PinIndx >= DIO_u8_PORTC_START) && (Copy_u8_PinIndx <= DIO_u8_PORTC_END) )
	{
		Copy_u8_PinIndx -= (DIO_u8_PORTA_SIZE + DIO_u8_PORTB_SIZE);
		if(GETBIT(PINC,Copy_u8_PinIndx))
		{
			 Local_u8Result=DIO_u8_HIGH;
		}
		else
		{
			Local_u8Result= DIO_u8_LOW;
		}
	}
	else if		( (Copy_u8_PinIndx >= DIO_u8_PORTD_START) && (Copy_u8_PinIndx <= DIO_u8_PORTD_END) )
	{
		Copy_u8_PinIndx = Copy_u8_PinIndx-DIO_u8_PORTA_SIZE-DIO_u8_PORTB_SIZE-DIO_u8_PORTD_SIZE;
		if(GETBIT(PIND,Copy_u8_PinIndx))
		{
			Local_u8Result=DIO_u8_HIGH;
		}
		else
		{
			Local_u8Result= DIO_u8_LOW;
		}
	}
	return Local_u8Result;
}

