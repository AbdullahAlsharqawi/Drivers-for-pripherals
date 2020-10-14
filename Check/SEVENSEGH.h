


#ifndef	_SEVEN_SEG_H
#define	_SEVEN_SEG_H


typedef enum
{
	deactivate,
	activate
}EnableState_t;

typedef enum 
{
	SEG_A_DIO_PIN=2,
	SEG_B_DIO_PIN,
	SEG_C_DIO_PIN,
	SEG_D_DIO_PIN,
	SEG_E_DIO_PIN,
	SEG_F_DIO_PIN,
	SEG_G_DIO_PIN
}SSConfig;


typedef enum
{
	ZERO,
	ONE,
	TWO,
	THREE,
	FOUR,
	FIVE,
	SIX,
	SEVEN,
	EIGHT,
	NINE
}NUMBER_T;



typedef enum
{
	Seg1,
	Seg2
}Seg_Num_t;



typedef enum
{
	SEG_Enable_Pin
}Enablepin_cfg;

extern void SevenSeg_voidSetEnablePin(u8 Copy_u8SegNum,boolean state);

extern void SeveSeg_voidInitialize(void);

static boolean MapState(boolean Copy_Enable_state);


static u8 MapPins(u8 Copy_u8PinIndex);


static void voidDisplayZero(void);
static void voidDisplayOne(void);
static void voidDisplayTwo(void);
static void voidDisplayThree(void);
static void voidDisplayFour(void);
static void voidDisplayFive(void);
static void voidDisplaySix(void);
static void voidDisplaySeven(void);
static void voidDisplayEight(void);
static void voidDisplayNine(void);

extern void SevenSeg_voidDisplayNum(u8 Copy_u8SegNum,u8 Copy_u8Num);

#endif
