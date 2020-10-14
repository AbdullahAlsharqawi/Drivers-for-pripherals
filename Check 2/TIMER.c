
#include "STD_TYPES.h"
#include "DIO_int.h"
#include "TIMER.h"


static void (*CallBack_PTR) (void);


extern void voidsetPrescaler(u8 Copy_u8Prescaler)
{
	TCCR0 &= ~(1<<CS02);
	TCCR0 &= ~(1<<CS01);
	TCCR0 &= ~(1<<CS00);
	switch(Copy_u8Prescaler)
	{
		case TIM0_DIV_1:
			TCCR0 |= (1<<CS00);
		break;
		case TIM0_DIV_8:
			TCCR0 |= (1<<CS01);
		break;
		case TIM0_DIV_64:
			TCCR0 |= (1<<CS01);
			TCCR0 |= (1<<CS00);
		break;
		case TIM0_DIV_256:
			TCCR0 |= (1<<CS02);
		break;
		case TIM0_DIV_1024:
			TCCR0 |= (1<<CS02);
			TCCR0 |= (1<<CS00);
		break;
	}
}

extern void TIMER0_voidInitialize(u8 Copy_u8Prescaler)
{
	TIMSK &= ~(1<<OCIE0);
	TIMSK &= ~(1<<TOIE0);
	
	TIFR |= (1<<OCF0);
	TIFR |= (1<<TOV0);
	
	voidsetPrescaler(Copy_u8Prescaler);
}

extern void TIMER0_voidSetMode(u8 Copy_u8Mode)
{
	TCCR0 &= ~(1<<COM01);
	TCCR0 &= ~(1<<COM00);
	switch(Copy_u8Mode)
	{
		case Normal_Port_Operation:
			TCCR0 &= ~(1<<COM01);
			TCCR0 &= ~(1<<COM00); 
		break;
		case Toggle_OC0_On_Compare_Match:
			TCCR0 &= ~(1<<COM01);
			TCCR0 |=  (1<<COM00); 
		break;
		case Clear_OC0_On_Compare_Match:
			TCCR0 |=  (1<<COM01);
			TCCR0 &= ~(1<<COM00); 
		break;
		case Set_OC0_On_Compare_Match:
			TCCR0 |=  (1<<COM01);
			TCCR0 |=  (1<<COM00); 
		break;
	}
	
}

extern void TIMER0_voidSetCompareValue(u8 Copy_u8InitialValue)
{
	OCR0 = Copy_u8InitialValue;
}

extern void TIMER0_voidEnableCompareMatch(void)
{
	TIMSK |= (1<<OCIE0);
}

extern void TIMER0_voidDisable(void)
{
	TIMSK &= ~(1<<OCIE0);
}

extern void TIMER0_SetCallbackFunc(void (*Copt_PTR_Func) (void) )
{
	CallBack_PTR=Copt_PTR_Func;
}

extern void __vector_11(void) __attribute__((signal,used));
extern void __vector_11(void) 
{
	CallBack_PTR();
}
