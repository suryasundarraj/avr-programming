#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define setOutput(x,y) x |= (1<<y)
#define setInput(x,y)  x &= ~(1<<y)
#define setBit(x,y)    x |= _BV(y)
#define clearBit(x,y)  x &= ~_BV(y)
#define toggleBit(x,y) x ^= _BV(y)

int main(){
	setOutput(DDRB,PINB0);
	setInput(DDRB,PINB1);
	PCICR = _BV(PCIE0);
	PCMSK0 = _BV(PCINT1);
	sei();
	while(1){
		clearBit(PORTB,PINB0);
		_delay_ms(1000);
	}
}

ISR(PCINT0_vect){
	if(((1<<PINB0)&PINB)==0){
		setBit(PORTB,PINB0);
		_delay_ms(1000);
	}
}