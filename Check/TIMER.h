


#ifndef	_TIMER_H
#define _TIMER_H

#define TCCR0 *((volatile u8*) 0x53)
#define TCNT0 *((volatile u8*) 0x52)
#define OCR0  *((volatile u8*) 0x5C)
#define TIMSK *((volatile u8*) 0x59)
#define TIFR  *((volatile u8*) 0x58)

/* bits of register TCCR0 					*/       
#define FOC0	 	7
#define WGM00 	 	6
#define COM01		5
#define COM00		4
#define WGM01		3
#define CS02		2
#define CS01		1
#define CS00		0



/*bits of register TIMSK					*/
#define OCIE0		1
#define TOIE0		0

/*bits of register TIFR						*/
#define OCF0		1
#define TOV0		0


typedef enum 
{
	TIM0_DIV_1,
	TIM0_DIV_8,
	TIM0_DIV_64,
	TIM0_DIV_256,
	TIM0_DIV_1024
}Prescaler_T;

typedef enum
{
	Normal_Port_Operation,
	Toggle_OC0_On_Compare_Match,
	Clear_OC0_On_Compare_Match,
	Set_OC0_On_Compare_Match
}Timer_Mode_t;



extern void voidsetPrescaler(u8 Copy_u8Prescaler);

extern void TIMER0_voidInitialize(u8 Copy_u8Prescaler);


extern void TIMER0_voidSetMode(u8 Copy_u8Mode);

extern void TIMER0_voidSetCompareValue(u8 Copy_u8InitialValue);

extern void TIMER0_voidEnableCompareMatch(void);

extern void TIMER0_voidDisable(void);

extern void TIMER0_SetCallbackFunc(void (*Copt_PTR_Func) (void) );


#endif
