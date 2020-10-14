
#include "STD_TYPES.h"
#include "DIO_int.h"
#include "SEVENSEGH.h"


static Seg_Num_t segnum;

extern void SevenSeg_voidSetEnablePin(u8 Copy_u8SegNum,boolean state)
{
	segnum = Copy_u8SegNum;
	DIO_voidSetPinValue(MapPins(SEG_Enable_Pin),MapState(state));
}



extern void SeveSeg_voidInitialize(void)
{
	SevenSeg_voidSetEnablePin(Seg1,deactivate);
	SevenSeg_voidSetEnablePin(Seg2,deactivate);
}

static u8 MapPins(u8 Copy_u8PinIndex)
{
	u8 local_u8SegmentPin;

	switch(segnum)
	{
		case Seg1:
			switch (Copy_u8PinIndex)
			{
			    case SEG_A_DIO_PIN:
			        local_u8SegmentPin=DIO_u8_PIN_8;
			    break;
			    case SEG_B_DIO_PIN:
					local_u8SegmentPin=DIO_u8_PIN_9;
			    break;
			    case SEG_C_DIO_PIN:
					local_u8SegmentPin=DIO_u8_PIN_10;
				break;
				case SEG_D_DIO_PIN:
					local_u8SegmentPin=DIO_u8_PIN_11;
			    break;
			    case SEG_E_DIO_PIN:
					local_u8SegmentPin=DIO_u8_PIN_12;
				break;
			    case SEG_F_DIO_PIN:
					local_u8SegmentPin=DIO_u8_PIN_13;
			    break;
				case SEG_G_DIO_PIN:
					local_u8SegmentPin=DIO_u8_PIN_14;
				break;
				case SEG_Enable_Pin:
					local_u8SegmentPin=DIO_u8_PIN_15;
				break;
			}
		break;
		case Seg2:
			switch (Copy_u8PinIndex)
			{
			    case SEG_A_DIO_PIN:
			        local_u8SegmentPin=DIO_u8_PIN_24;
			    break;
			    case SEG_B_DIO_PIN:
					local_u8SegmentPin=DIO_u8_PIN_25;
			    break;
			    case SEG_C_DIO_PIN:
					local_u8SegmentPin=DIO_u8_PIN_26;
				break;
				case SEG_D_DIO_PIN:
					local_u8SegmentPin=DIO_u8_PIN_27;
			    break;
			    case SEG_E_DIO_PIN:
					local_u8SegmentPin=DIO_u8_PIN_28;
				break;
			    case SEG_F_DIO_PIN:
					local_u8SegmentPin=DIO_u8_PIN_29;
			    break;
				case SEG_G_DIO_PIN:
					local_u8SegmentPin=DIO_u8_PIN_30;
				break;
				case SEG_Enable_Pin:
					local_u8SegmentPin=DIO_u8_PIN_31;
				break;
			}
		break;
	}

	return local_u8SegmentPin;
}

static boolean MapState(boolean Copy_Enable_state)
{
	boolean Local_booleanEnableState;
	switch(Copy_Enable_state)
	{
		case deactivate:
			Local_booleanEnableState=DIO_u8_LOW;
		break;
		case activate:
			Local_booleanEnableState=DIO_u8_HIGH;
		break;
	}
	return Local_booleanEnableState;
}

static void voidDisplayZero(void)
{
	DIO_voidSetPinValue(MapPins(SEG_A_DIO_PIN),DIO_u8_HIGH);
	DIO_voidSetPinValue(MapPins(SEG_B_DIO_PIN),DIO_u8_HIGH);
	DIO_voidSetPinValue(MapPins(SEG_C_DIO_PIN),DIO_u8_HIGH);
	DIO_voidSetPinValue(MapPins(SEG_D_DIO_PIN),DIO_u8_HIGH);
	DIO_voidSetPinValue(MapPins(SEG_E_DIO_PIN),DIO_u8_HIGH);
	DIO_voidSetPinValue(MapPins(SEG_F_DIO_PIN),DIO_u8_HIGH);
	DIO_voidSetPinValue(MapPins(SEG_G_DIO_PIN),DIO_u8_LOW);
}

static void voidDisplayOne(void)
{
	DIO_voidSetPinValue(MapPins(SEG_A_DIO_PIN),DIO_u8_LOW);
	DIO_voidSetPinValue(MapPins(SEG_B_DIO_PIN),DIO_u8_HIGH);
	DIO_voidSetPinValue(MapPins(SEG_C_DIO_PIN),DIO_u8_HIGH);
	DIO_voidSetPinValue(MapPins(SEG_D_DIO_PIN),DIO_u8_LOW);
	DIO_voidSetPinValue(MapPins(SEG_E_DIO_PIN),DIO_u8_LOW);
	DIO_voidSetPinValue(MapPins(SEG_F_DIO_PIN),DIO_u8_LOW);
	DIO_voidSetPinValue(MapPins(SEG_G_DIO_PIN),DIO_u8_LOW);
}

static void voidDisplayTwo(void)
{
	DIO_voidSetPinValue(MapPins(SEG_A_DIO_PIN),DIO_u8_HIGH);
	DIO_voidSetPinValue(MapPins(SEG_B_DIO_PIN),DIO_u8_HIGH);
	DIO_voidSetPinValue(MapPins(SEG_C_DIO_PIN),DIO_u8_LOW);
	DIO_voidSetPinValue(MapPins(SEG_D_DIO_PIN),DIO_u8_HIGH);
	DIO_voidSetPinValue(MapPins(SEG_E_DIO_PIN),DIO_u8_HIGH);
	DIO_voidSetPinValue(MapPins(SEG_F_DIO_PIN),DIO_u8_LOW);
	DIO_voidSetPinValue(MapPins(SEG_G_DIO_PIN),DIO_u8_HIGH);
}

static void voidDisplayThree(void)
{
	DIO_voidSetPinValue(MapPins(SEG_A_DIO_PIN),DIO_u8_HIGH);
	DIO_voidSetPinValue(MapPins(SEG_B_DIO_PIN),DIO_u8_HIGH);
	DIO_voidSetPinValue(MapPins(SEG_C_DIO_PIN),DIO_u8_HIGH);
	DIO_voidSetPinValue(MapPins(SEG_D_DIO_PIN),DIO_u8_HIGH);
	DIO_voidSetPinValue(MapPins(SEG_E_DIO_PIN),DIO_u8_LOW);
	DIO_voidSetPinValue(MapPins(SEG_F_DIO_PIN),DIO_u8_LOW);
	DIO_voidSetPinValue(MapPins(SEG_G_DIO_PIN),DIO_u8_HIGH);
}

static void voidDisplayFour(void)
{
	DIO_voidSetPinValue(MapPins(SEG_A_DIO_PIN),DIO_u8_LOW);
	DIO_voidSetPinValue(MapPins(SEG_B_DIO_PIN),DIO_u8_HIGH);
	DIO_voidSetPinValue(MapPins(SEG_C_DIO_PIN),DIO_u8_HIGH);
	DIO_voidSetPinValue(MapPins(SEG_D_DIO_PIN),DIO_u8_LOW);
	DIO_voidSetPinValue(MapPins(SEG_E_DIO_PIN),DIO_u8_LOW);
	DIO_voidSetPinValue(MapPins(SEG_F_DIO_PIN),DIO_u8_HIGH);
	DIO_voidSetPinValue(MapPins(SEG_G_DIO_PIN),DIO_u8_HIGH);
}

static void voidDisplayFive(void)
{
	DIO_voidSetPinValue(MapPins(SEG_A_DIO_PIN),DIO_u8_HIGH);
	DIO_voidSetPinValue(MapPins(SEG_B_DIO_PIN),DIO_u8_LOW);
	DIO_voidSetPinValue(MapPins(SEG_C_DIO_PIN),DIO_u8_HIGH);
	DIO_voidSetPinValue(MapPins(SEG_D_DIO_PIN),DIO_u8_HIGH);
	DIO_voidSetPinValue(MapPins(SEG_E_DIO_PIN),DIO_u8_LOW);
	DIO_voidSetPinValue(MapPins(SEG_F_DIO_PIN),DIO_u8_HIGH);
	DIO_voidSetPinValue(MapPins(SEG_G_DIO_PIN),DIO_u8_HIGH);
}

static void voidDisplaySix(void)
{
	DIO_voidSetPinValue(MapPins(SEG_A_DIO_PIN),DIO_u8_HIGH);
	DIO_voidSetPinValue(MapPins(SEG_B_DIO_PIN),DIO_u8_LOW);
	DIO_voidSetPinValue(MapPins(SEG_C_DIO_PIN),DIO_u8_HIGH);
	DIO_voidSetPinValue(MapPins(SEG_D_DIO_PIN),DIO_u8_HIGH);
	DIO_voidSetPinValue(MapPins(SEG_E_DIO_PIN),DIO_u8_HIGH);
	DIO_voidSetPinValue(MapPins(SEG_F_DIO_PIN),DIO_u8_HIGH);
	DIO_voidSetPinValue(MapPins(SEG_G_DIO_PIN),DIO_u8_HIGH);
}

static void voidDisplaySeven(void)
{
	DIO_voidSetPinValue(MapPins(SEG_A_DIO_PIN),DIO_u8_HIGH);
	DIO_voidSetPinValue(MapPins(SEG_B_DIO_PIN),DIO_u8_HIGH);
	DIO_voidSetPinValue(MapPins(SEG_C_DIO_PIN),DIO_u8_HIGH);
	DIO_voidSetPinValue(MapPins(SEG_D_DIO_PIN),DIO_u8_LOW);
	DIO_voidSetPinValue(MapPins(SEG_E_DIO_PIN),DIO_u8_LOW);
	DIO_voidSetPinValue(MapPins(SEG_F_DIO_PIN),DIO_u8_LOW);
	DIO_voidSetPinValue(MapPins(SEG_G_DIO_PIN),DIO_u8_LOW);
}

static void voidDisplayEight(void)
{
	DIO_voidSetPinValue(MapPins(SEG_A_DIO_PIN),DIO_u8_HIGH);
	DIO_voidSetPinValue(MapPins(SEG_B_DIO_PIN),DIO_u8_HIGH);
	DIO_voidSetPinValue(MapPins(SEG_C_DIO_PIN),DIO_u8_HIGH);
	DIO_voidSetPinValue(MapPins(SEG_D_DIO_PIN),DIO_u8_HIGH);
	DIO_voidSetPinValue(MapPins(SEG_E_DIO_PIN),DIO_u8_HIGH);
	DIO_voidSetPinValue(MapPins(SEG_F_DIO_PIN),DIO_u8_HIGH);
	DIO_voidSetPinValue(MapPins(SEG_G_DIO_PIN),DIO_u8_HIGH);
}

static void voidDisplayNine(void)
{

	DIO_voidSetPinValue(MapPins(SEG_A_DIO_PIN),DIO_u8_HIGH);
	DIO_voidSetPinValue(MapPins(SEG_B_DIO_PIN),DIO_u8_HIGH);
	DIO_voidSetPinValue(MapPins(SEG_C_DIO_PIN),DIO_u8_HIGH);
	DIO_voidSetPinValue(MapPins(SEG_D_DIO_PIN),DIO_u8_HIGH);
	DIO_voidSetPinValue(MapPins(SEG_E_DIO_PIN),DIO_u8_LOW);
	DIO_voidSetPinValue(MapPins(SEG_F_DIO_PIN),DIO_u8_HIGH);
	DIO_voidSetPinValue(MapPins(SEG_G_DIO_PIN),DIO_u8_HIGH);
}


extern void SevenSeg_voidDisplayNum(u8 Copy_u8SegNum,u8 Copy_u8Num)
{
	segnum = Copy_u8SegNum;
	switch(Copy_u8Num)
	{
		case ZERO:
			voidDisplayZero();
		break;
		case ONE:
			voidDisplayOne();
		break;
		case TWO:
			voidDisplayTwo();
		break;
		case THREE:
			voidDisplayThree();
		break;
		case FOUR:
			voidDisplayFour();
		break;
		case FIVE:
			voidDisplayFive();
		break;
		case SIX:
			voidDisplaySix();
		break;
		case SEVEN:
			voidDisplaySeven();
		break;
		case EIGHT:
			voidDisplayEight();
		break;
		case NINE:
			voidDisplayNine();
		break;
	}
}



