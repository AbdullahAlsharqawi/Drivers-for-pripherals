#include "STD_TYPES.h"
#include "DIO_int.h"
#include "SEVENSEGH.h"
#include "KEYPADH.h"
#include "CLOCK.h"
#include "KEYPAD7SEGAPP.h"


extern void KPSegInitialize(void)
{
	
}

extern void KPSeg_Task(void)
{
	static u8 counter=0;
	static u16 previousState=0,currentState=0;
	currentState=KEYPAD_u16GetStatus();
	u8 sec;
	u8 min;
	u8 hr;
	u8 TypeOfTimeOnDisplay=SECONDS;
	if (previousState==currentState)
	{
		counter++;
		if(counter==40)
		{
			switch(currentState)
			{
				case ZERO_BUTTON:
					SevenSeg_voidSetEnablePin(Seg2,deactivate);
					SevenSeg_voidSetEnablePin(Seg1,activate);
					SevenSeg_voidDisplayNum(Seg1,0);
				break;
				case ONE_BUTTON:
					SevenSeg_voidSetEnablePin(Seg2,deactivate);
					SevenSeg_voidSetEnablePin(Seg1,activate);
					SevenSeg_voidDisplayNum(Seg1,1);
				break;
				case TWO_BUTTON:
					SevenSeg_voidSetEnablePin(Seg2,deactivate);
					SevenSeg_voidSetEnablePin(Seg1,activate);
					SevenSeg_voidDisplayNum(Seg1,2);
				break;
				case THREE_BUTTON:
					SevenSeg_voidSetEnablePin(Seg2,deactivate);
					SevenSeg_voidSetEnablePin(Seg1,activate);
					SevenSeg_voidDisplayNum(Seg1,3);
				break;
				case FOUR_BUTTON:
					SevenSeg_voidSetEnablePin(Seg2,deactivate);
					SevenSeg_voidSetEnablePin(Seg1,activate);
					SevenSeg_voidDisplayNum(Seg1,4);
				break;
				case FIVE_BUTTON:
					SevenSeg_voidSetEnablePin(Seg2,deactivate);
					SevenSeg_voidSetEnablePin(Seg1,activate);
					SevenSeg_voidDisplayNum(Seg1,5);
				break;
				case SIX_BUTTON:
					SevenSeg_voidSetEnablePin(Seg2,deactivate);
					SevenSeg_voidSetEnablePin(Seg1,activate);
					SevenSeg_voidDisplayNum(Seg1,6);
				break;				
				case SEVEN_BUTTON:
					SevenSeg_voidSetEnablePin(Seg2,deactivate);
					SevenSeg_voidSetEnablePin(Seg1,activate);
					SevenSeg_voidDisplayNum(Seg1,7);
				break;
				case EIGHT_BUTTON:
					SevenSeg_voidSetEnablePin(Seg2,deactivate);
					SevenSeg_voidSetEnablePin(Seg1,activate);
					SevenSeg_voidDisplayNum(Seg1,8);
				break;
				case NINE_BUTTON:
					SevenSeg_voidSetEnablePin(Seg2,deactivate);
					SevenSeg_voidSetEnablePin(Seg1,activate);
					SevenSeg_voidDisplayNum(Seg1,9);
				break;
				case A_BUTTON:
					TypeOfTimeOnDisplay=SECONDS;
					CLK_SetSec(sec);
					SevenSeg_voidSetEnablePin(Seg2,activate);
					SevenSeg_voidDisplayNum(Seg2,sec/10);
					SevenSeg_voidSetEnablePin(Seg1,activate);
					SevenSeg_voidDisplayNum(Seg1,sec%10);
				break;
				case B_BUTTON:
					TypeOfTimeOnDisplay=MINUTES;
					CLK_SetSec(min);
					SevenSeg_voidSetEnablePin(Seg2,activate);
					SevenSeg_voidDisplayNum(Seg2,min/10);
					SevenSeg_voidSetEnablePin(Seg1,activate);
					SevenSeg_voidDisplayNum(Seg1,min%10);
				break;
				case C_BUTTON:
					TypeOfTimeOnDisplay=HOURS;
					CLK_SetSec(hr);
					SevenSeg_voidSetEnablePin(Seg2,activate);
					SevenSeg_voidDisplayNum(Seg2,hr/10);
					SevenSeg_voidSetEnablePin(Seg1,activate);
					SevenSeg_voidDisplayNum(Seg1,hr%10);
				break;
				case D_BUTTON:
					CLK_ResetTime();
					SevenSeg_voidSetEnablePin(Seg2,activate);
					SevenSeg_voidDisplayNum(Seg2,0);
					SevenSeg_voidSetEnablePin(Seg1,activate);
					SevenSeg_voidDisplayNum(Seg1,0);
				break;
				case ASTERISK_BUTTON:
					CLK_Adjustment(TypeOfTimeOnDisplay);
					if(TypeOfTimeOnDisplay == SECONDS)
					{
						CLK_SetSec(sec);
						SevenSeg_voidSetEnablePin(Seg2,activate);
						SevenSeg_voidDisplayNum(Seg2,sec/10);
						SevenSeg_voidSetEnablePin(Seg1,activate);
						SevenSeg_voidDisplayNum(Seg1,sec%10);
					}
					else if(TypeOfTimeOnDisplay == MINUTES)
					{
						CLK_SetSec(min);
						SevenSeg_voidSetEnablePin(Seg2,activate);
						SevenSeg_voidDisplayNum(Seg2,min/10);
						SevenSeg_voidSetEnablePin(Seg1,activate);
						SevenSeg_voidDisplayNum(Seg1,min%10);
					}
					else if(TypeOfTimeOnDisplay == HOURS)
					{
						CLK_SetSec(hr);
						SevenSeg_voidSetEnablePin(Seg2,activate);
						SevenSeg_voidDisplayNum(Seg2,hr/10);
						SevenSeg_voidSetEnablePin(Seg1,activate);
						SevenSeg_voidDisplayNum(Seg1,hr%10);
					}
				break;
			}
			counter=0;
		}
	}
	else
	{
		counter=0;
	}
}
