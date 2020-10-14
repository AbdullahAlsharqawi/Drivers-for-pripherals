


#ifndef _KEYPADH_H
#define	_KEYPADH_H


typedef enum
{
	KEYPAD_OUTPUT_1,
	KEYPAD_OUTPUT_2,
	KEYPAD_OUTPUT_3,
	KEYPAD_OUTPUT_4
}Keypad_output_indx_t;



typedef enum
{
	KEYPAD_INPUT_1,
	KEYPAD_INPUT_2,
	KEYPAD_INPUT_3,
	KEYPAD_INPUT_4
}Keypad_input_indx_t;

extern void KEYPAD_voidIntialize(void);

extern u16 KEYPAD_u16GetStatus(void);

static u16 u16GetKpStatus(void);

static u8 u8MapInput(u8 Copy_u8InputIndx);

static u8 u8MapOutput(u8 Copy_u8OutputIndx);

static void voidCheckInputs(u8 Copy_u8SequenceNumber);

extern void KEYPADH_Task(void);

#endif