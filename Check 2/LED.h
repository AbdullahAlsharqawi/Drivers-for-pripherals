



#ifndef	_LED_H
#define _LED_H

typedef enum
{
	LED_1,
	LED_2
}LEd_t;

typedef enum 
{
	OFF,
	ON
}LED_Status_cfg;

extern void LED_voidInitialize(void);

extern void LED_voidSetLED(u8 Copy_u8LED, u8 Copy_u8State);


#endif
