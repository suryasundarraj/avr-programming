#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

#define setOutput(x,y) x |= (1<<y)
#define setInput(x,y)  x &= ~(1<<y)
#define setBit(x,y)    x |= _BV(y)
#define clearBit(x,y)  x &= ~_BV(y)
#define toggleBit(x,y) x ^= _BV(y)

int main(){
	setOutput(DDRB,PINB0);
	TCCR1B |= (1 << CS10);
	int delayCount = 0;
	while(1){
		if(TCNT1 > 10000){
			TCNT1 = 0;
			delayCount++;
			if(delayCount > 1600){
				toggleBit(PORTB,PINB0);
				delayCount = 0;
			}
		}
	}
}