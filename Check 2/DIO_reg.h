/****************************************/
/* 	Author 	: 	zeinab ali         		*/
/*	Date 	:	25/1/2018			 	*/
/*	version	:	V01						*/
/****************************************/

#ifndef 	_DIO_REG_H
#define _DIO_REG_H


/*	comment: GROUP A Register			*/
#define DDRA		*((u8*)0x3A)
#define PORTA		*((u8*)0x3B)
#define PINA 		*((u8*)0x39)

/*	comment: GROUP B Register			*/
#define DDRB		*((u8*)0x37)
#define PORTB		*((u8*)0x38)
#define PINB		*((u8*)0x36)

/*	comment: GROUP C Register			*/
#define DDRC		*((u8*)0x34)
#define PORTC		*((u8*)0x35)
#define PINC		*((u8*)0x33)

/*	comment: GROUP D Register			*/
#define DDRD		*((u8*)0x31)
#define PORTD		*((u8*)0x32)
#define PIND 		*((u8*)0x30)

#endif
