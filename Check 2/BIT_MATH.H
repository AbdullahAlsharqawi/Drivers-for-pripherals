#ifndef _MATH_H
#define _MATH_H
//set bit
#define SETBIT(var,bit) var = (var) | (1 << (bit))
							  
						  
//clear bit
#define CLRBIT(var,bit) var = (var) & ~(1 << (bit))
							  
						  
//toggle bit
#define TOGGLE(var,bit)	(var) ^= (1 << (bit))
						  
					  
//get bit
#define GETBIT(var,bit) ((var) & (1 << (bit)))>>(bit)
							

//set low nibble							
#define setlownib(var)	(var) | (0x0F)
							
		
//set high nibble
#define sethighnib(var) (var) | (0xF0)
				

//clear low nibble			
#define clrlownib(var)  (var) & (0xF0)
							
						
//clear high nibble
#define clrhighnib(var) (var) & (0x0F)
					
//toggle low nibble				
#define togglelownib(var)  (var) ^ (0x0F)
							
//toggle high nibble
#define togglehighnib(var)  (var) ^ (0xF0)

#define CONC_HELP(b7,b6,b5,b4,b3,b2,b1,b0) 	0b##b7##b6##b5##b4##b3##b2##b1##b0
#define CONCBIT(b7,b6,b5,b4,b3,b2,b1,b0)	CONC_HELP(b7,b6,b5,b4,b3,b2,b1,b0)

				
#endif
