
#include "STD_TYPES.h"
#include "DIO_int.h"
#include "CLOCK.h"


static CLK_Time_t Time;

extern void CLK_Initialize(void)
{
	Time.Sec=0;
	Time.Min=0;
	Time.Hr=0;
}

extern void CLK_ResetTime(void)
{
	Time.Sec=0;
	Time.Min=0;
	Time.Hr=0;
}

extern void CLK_Adjustment(u8 Copy_Time_Type)
{
	if(Copy_Time_Type == SECONDS)
	{
		Time.Sec++;
		if(Time.Sec == 60)
		{
			Time.Sec=0;
			Time.Min++;
		}
		if(Time.Min == 60)
		{
			Time.Min=0;
			Time.Hr++;
		}
		if(Time.Hr == 24)
		{
			Time.Hr=0;
		}
	}
	else if(Copy_Time_Type == MINUTES)
	{
		Time.Min++;
		if(Time.Min == 60)
		{
			Time.Min=0;
			Time.Hr++;
		}
		if(Time.Hr == 24)
		{
			Time.Hr=0;
		}
	}
	else if(Copy_Time_Type == HOURS)
	{
		Time.Hr++;
		if(Time.Hr == 24)
		{
			Time.Hr=0;
		}
	}
}

extern void CLK_SetSec(u8 Copy_u8Sec)
{
	Time.Sec=Copy_u8Sec;
}

extern void CLK_SetMin(u8 Copy_u8Min)
{
	Time.Min=Copy_u8Min;
}

extern void CLK_SetHr(u8 Copy_u8Hr)
{
	Time.Hr=Copy_u8Hr;
}

extern void CLK_GetTime(CLK_Time_t* Copy_Time_ptr)
{
	Copy_Time_ptr->Sec = Time.Sec;
	Copy_Time_ptr->Min = Time.Min;
	Copy_Time_ptr->Hr  = Time.Hr ;
}

extern void CLK_TASK(void)
{
	Time.Sec++;
	if(Time.Sec == 60)
	{
		Time.Sec=0;
		Time.Min++;
	}
	
	if(Time.Min == 60)
	{
		Time.Min=0;
		Time.Hr++;
	}
	
	if(Time.Hr == 24)
	{
		Time.Hr=0;
	}
}
