/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: hp
 */

#include "STD_TYPES.h"
#include "DIO_int.h"
#include "LED.h"
#include "LedTog.h"
#include "BUTTONH.h"
#include "ButtonApp.h"
#include "KEYPADH.h"
#include "TIMER.h"
#include "CLOCK.h"
#include "KEYPAD7SEGAPP.h"
#include "OS.h"

void main (void)
{



	OS_Initialize();
	OS_Start();
}
