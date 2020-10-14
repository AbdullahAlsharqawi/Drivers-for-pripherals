


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_int.h"

#include "GIE_reg.h"
#include "GIE_priv.h"
#include "GIE_config.h"
#include "GIE_int.h"


void GIE_voidEnable(void)
{
	SETBIT(SREG,GIE_u8_BIT_INDEX);
}

void GIE_voidDisable(void)
{
	CLRBIT(SREG,GIE_u8_BIT_INDEX);
}
