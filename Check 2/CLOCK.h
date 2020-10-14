

#ifndef _CLOCK_H
#define	_CLOCK_H

typedef struct
{
	u8 Sec;
	u8 Min;
	u8 Hr;
}CLK_Time_t;


typedef enum
{
	SECONDS,
	MINUTES,
	HOURS
}CLK_TIME_TYPE_t;

extern void CLK_Initialize(void);

extern void CLK_ResetTime(void);

extern void CLK_Adjustment(u8 Copy_Time);

extern void CLK_SetSec(u8 Copy_u8Sec);

extern void CLK_SetMin(u8 Copy_u8Min);

extern void CLK_SetHr(u8 Copy_u8Hr);

extern void CLK_GetTime(CLK_Time_t* Copy_Time_ptr);

extern void CLK_TASK(void);

#endif
