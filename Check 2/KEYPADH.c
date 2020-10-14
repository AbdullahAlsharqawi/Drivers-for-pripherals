

#include "STD_TYPES.h"
#include "DIO_int.h"
#include "KEYPADH.h"



static u16 KeypadStatus;
static u16 Local_u16Result;

extern void KEYPAD_voidIntialize(void)
{
	KeypadStatus=0;
	Local_u16Result=0;
}

extern u16 KEYPAD_u16GetStatus(void)
{
	return KeypadStatus;
}

static u8 u8MapInput(u8 Copy_u8InputIndx)
{
	u8 Local_u8Input;
	switch (Copy_u8InputIndx)
	{
		case KEYPAD_INPUT_1:
			Local_u8Input=DIO_u8_PIN_8;
		break;
		case KEYPAD_INPUT_2:
			Local_u8Input=DIO_u8_PIN_9;
		break;
		case KEYPAD_INPUT_3:
			Local_u8Input=DIO_u8_PIN_10;
		break;
		case KEYPAD_INPUT_4:
			Local_u8Input=DIO_u8_PIN_11;
		break;
	}
	return Local_u8Input;
}


static u8 u8MapOutput(u8 Copy_u8OutputIndx)
{
	u8 Local_u8Output;
	switch (Copy_u8OutputIndx)
	{
		case KEYPAD_OUTPUT_1:
			Local_u8Output=DIO_u8_PIN_12;
		break;
		case KEYPAD_OUTPUT_2:
			Local_u8Output=DIO_u8_PIN_13;
		break;
		case KEYPAD_OUTPUT_3:
			Local_u8Output=DIO_u8_PIN_14;
		break;
		case KEYPAD_OUTPUT_4:
			Local_u8Output=DIO_u8_PIN_15;
		break;
	}
	return Local_u8Output;
}

static u16 u16GetKpStatus(void)
{
	
	
	/*Generate sequence 1*/
	DIO_voidSetPinValue(u8MapOutput(KEYPAD_OUTPUT_1),DIO_u8_LOW);
	DIO_voidSetPinValue(u8MapOutput(KEYPAD_OUTPUT_2),DIO_u8_HIGH);
	DIO_voidSetPinValue(u8MapOutput(KEYPAD_OUTPUT_3),DIO_u8_HIGH);
	DIO_voidSetPinValue(u8MapOutput(KEYPAD_OUTPUT_4),DIO_u8_HIGH);
	voidCheckInputs(0);
	
	
	/*Generate sequence 2*/
	DIO_voidSetPinValue(u8MapOutput(KEYPAD_OUTPUT_1),DIO_u8_HIGH);
	DIO_voidSetPinValue(u8MapOutput(KEYPAD_OUTPUT_2),DIO_u8_LOW);
	DIO_voidSetPinValue(u8MapOutput(KEYPAD_OUTPUT_3),DIO_u8_HIGH);
	DIO_voidSetPinValue(u8MapOutput(KEYPAD_OUTPUT_4),DIO_u8_HIGH);
	voidCheckInputs(1);
	
	/*Generate sequence 3*/
	DIO_voidSetPinValue(u8MapOutput(KEYPAD_OUTPUT_1),DIO_u8_HIGH);
	DIO_voidSetPinValue(u8MapOutput(KEYPAD_OUTPUT_2),DIO_u8_HIGH);
	DIO_voidSetPinValue(u8MapOutput(KEYPAD_OUTPUT_3),DIO_u8_LOW);
	DIO_voidSetPinValue(u8MapOutput(KEYPAD_OUTPUT_4),DIO_u8_HIGH);
	voidCheckInputs(2);
	
	/*Generate sequence 4*/
	DIO_voidSetPinValue(u8MapOutput(KEYPAD_OUTPUT_1),DIO_u8_HIGH);
	DIO_voidSetPinValue(u8MapOutput(KEYPAD_OUTPUT_2),DIO_u8_HIGH);
	DIO_voidSetPinValue(u8MapOutput(KEYPAD_OUTPUT_3),DIO_u8_HIGH);
	DIO_voidSetPinValue(u8MapOutput(KEYPAD_OUTPUT_4),DIO_u8_LOW);
	voidCheckInputs(3);
	
	
	return Local_u16Result;
}

static void voidCheckInputs(u8 Copy_u8SequenceNumber)
{
	/*check input1*/
	if(DIO_u8GetPinValue(u8MapInput(KEYPAD_INPUT_1))  == DIO_u8_LOW)
	{
		Local_u16Result |= (1 << Copy_u8SequenceNumber);
	}
	else
	{
		Local_u16Result &= ~(1 << Copy_u8SequenceNumber);
	}
	
	/*check input2*/
	if(DIO_u8GetPinValue(u8MapInput(KEYPAD_INPUT_2))  == DIO_u8_LOW)
	{
		Local_u16Result |= (1 << (Copy_u8SequenceNumber+4));
	}
	else
	{
		Local_u16Result &= ~(1 << (Copy_u8SequenceNumber+4));
	}
	
	/*check input3*/
	if(DIO_u8GetPinValue(u8MapInput(KEYPAD_INPUT_3))  == DIO_u8_LOW)
	{
		Local_u16Result |= (1 << (Copy_u8SequenceNumber+8));
	}
	else
	{
		Local_u16Result &= ~(1 << (Copy_u8SequenceNumber+8));
	}
	
	/*check input4*/
	if(DIO_u8GetPinValue(u8MapInput(KEYPAD_INPUT_4))  == DIO_u8_LOW)
	{
		Local_u16Result |= (1 << (Copy_u8SequenceNumber+12));
	}
	else
	{
		Local_u16Result &= ~(1 << (Copy_u8SequenceNumber+12));
	}
	
}



extern void KEYPADH_Task(void)
{
	static u8 BouncingCounter=0;
	static u16 PreviousStatus=0,CurrentStatus=0; 
	CurrentStatus = u16GetKpStatus();
	if(PreviousStatus == CurrentStatus)
	{
		BouncingCounter++;
		if(BouncingCounter == 5)
		{
			KeypadStatus = CurrentStatus;
			BouncingCounter=0;
		}
	}
	else
	{
		BouncingCounter=0;
	}
}