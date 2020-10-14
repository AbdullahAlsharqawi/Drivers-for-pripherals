

#ifndef   _BUTTONH_H
#define   _BUTTONH_H

typedef enum
{
	button_1
}BUTTON_t;

static void MapButton(u8 Copy_u8Button);

extern void Button_voidInitialise(void);

extern boolean Button_booleanGetStatus(u8 Copy_u8Button);

extern void Bouncing_Task(void);

#endif
