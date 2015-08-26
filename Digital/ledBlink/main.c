//Specify the Functional Clock with respectie External Crystal 
#define F_CPU 16000000UL		            //16 MHz Clock

//Import the Libiraries Required
#include <avr/io.h>
#include <util/delay.h>

//Main Program
int main(void)
{
  DDRB |= (1<<PINB0);                   //Setting the Data Direction for the Specfic Pin Used as Output
  PORTB |= (1<<PINB0);                  //Initial High 

  while (1) {
    PORTB ^= (1<<PINB0);                //Toggling the Pin using the EX-OR Bit Wise Operator
    _delay_ms(500);                     //500 ms Delay
  }
}
//End of the Program


