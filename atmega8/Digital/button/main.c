/*********************************************************************************
Atmega8 LED Toggle using Push Button Program
Author : Surya Sundar Raj
*********************************************************************************/
//Specify the Functional Clock with respectie External Crystal
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

/*********************************************************************************
Function Name     : main
Description       : Initialize the LED pin as a OUTPUT,  
					Button pin as INPUT and Toggle the LED using the Button
Parameters        : void
Return            : void
*********************************************************************************/
int main()
{
	DDRB &= ~(1<<PINB1);
	DDRB |= 1<<PINB0;
	PORTB |= 1<<PINB0;
	while(1)
	{
		if(((1<<PINB1) & PINB) == 0) 
		{
			PORTB ^= 1<<PINB0;
			_delay_ms(500);
		}
	}
}

//End of the Program
