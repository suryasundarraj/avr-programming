#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

#define setOutput(x,y) x |= (1<<y)
#define setInput(x,y)  x &= ~(1<<y)
#define setBit(x,y)    x |= _BV(y)
#define clearBit(x,y)  x &= ~_BV(y)
#define toggleBit(x,y) x ^= _BV(y)

int main(){
	setInput(DDRB,PINB1);
	setOutput(DDRB,PINB0);
	int l_pressedButton = 0;
	int l_pressed = 0;
	int l_releasedButton = 0;
	while(1){
		if(((1<<PINB1)&PINB)==0){
			l_pressedButton++;
			if(l_pressedButton>500){
				l_pressedButton=0;
				if(l_pressed == 1){
					toggleBit(PORTB,PINB0);
					l_pressed = 0;		
				}
			}
		}
		else{
			l_releasedButton++;
			if(l_releasedButton>500){
				l_releasedButton=0;
				l_pressed = 1;
			}
		}
	}
}