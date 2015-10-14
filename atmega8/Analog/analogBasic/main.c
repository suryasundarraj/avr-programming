/***************************************************************************************
Analog Value 10 Bit Resolution
Author : Surya Sundar Raj D
Description : The code reads the data from the A0 pin of the Atmega8a and transmit the 
data through the UART Port
Required Library : uart [available in the Library/uart in this repo]
***************************************************************************************/
#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <uart.h>
#include <stdio.h>

int main(void)
{
	//Start the Uart Communication with 9600 Baud with 2 Stop Bits
	uartBegin(9600);
	//Reference Voltage as AVcc with external capacitor on Aref
	ADMUX |= (1<<REFS0);
	//Enable the ADC Interrupt Enalbe
	ADCSRA |= (1<<ADIE);
	//Set the Prescalar to 128
	ADCSRA |= (1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0);
	//Enable the ADC Enable to start the ADC Converstion 
	ADCSRA |= (1<<ADEN);
	//Enalbe the Global Interrupt
	sei();
	//Reads the changes in the Pin and updates the Register
	ADCSRA |= (1<<ADSC);
	while(1);
}

ISR(ADC_vect)
{
	char ADCvalue[4];
	//Obtaining the 10 Bit Resolution value 
	uint8_t ADClow=ADCL;
	uint16_t analogValue=ADCH<<8 |ADClow;
	//Conveting as a string
	itoa(analogValue,ADCvalue,10);
	ADCSRA |= (1<<ADSC);
	_delay_ms(100);
	//Sending the value serial to print on terminal
	printStringln(ADCvalue);
}

//End of the Program
