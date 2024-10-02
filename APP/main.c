/*
 * LineFollow.c
 *
 * Created: 10/2/2024 10:58:47 AM
 * Author : Rober Maher
 */ 

#include <avr/io.h>
#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPE.h"

#include "../MCAL/DIO/DIO_interface.h"

#include "../HAL/DCMOTOR/DCMOTOR_interface.h"

#define F_CPU 16000000UL
#include <util/delay.h>



int main(void)
{
	DIO_voidSetPinDir(DIO_PORTA,DIO_PIN0,INPUT);
	DIO_voidSetPinDir(DIO_PORTA,DIO_PIN1,INPUT);
	
	
	while (1)
	{
		if (DIO_u8ReadpinVal(DIO_PORTA,DIO_PIN0)==1 && DIO_u8ReadpinVal(DIO_PORTA,DIO_PIN1)==1)
		{
			DCMOTOR_voidCW();
		}
		else if (DIO_u8ReadpinVal(DIO_PORTA,DIO_PIN0)==1 && DIO_u8ReadpinVal(DIO_PORTA,DIO_PIN1)==0)
		{
			DCMOTOR_voidCWRight();
		}
		else if (DIO_u8ReadpinVal(DIO_PORTA,DIO_PIN0)==0 && DIO_u8ReadpinVal(DIO_PORTA,DIO_PIN1)==1)
		{
			DCMOTOR_voidCWLeft();	
		}
		else if (DIO_u8ReadpinVal(DIO_PORTA,DIO_PIN0)==0 && DIO_u8ReadpinVal(DIO_PORTA,DIO_PIN1)==0)
		{
			DCMOTOR_voidStop();
		}
		
	}
}
