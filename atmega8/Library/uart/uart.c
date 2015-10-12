#include "uart.h"

void uartBegin(uint16_t baud)
{
   UBRRL =  (uint8_t) UBBR(baud);
   UBRRH =  (uint8_t) (UBBR(baud)>>8);
   UCSRC=(1<<URSEL)|(3<<UCSZ0);
   UCSRB=(1<<RXEN)|(1<<TXEN);
}

char serialRead()
{
   while(!(UCSRA & (1<<RXC)))
   {
      //Do nothing
   }
   return UDR;
}

void serialWrite(char data)
{
   while(!(UCSRA & (1<<UDRE)))
   {
      //Do nothing
   }
   UCSRB &= ~(1<<TXB8);
   if ( data & 0x0100 )
   UCSRB |= (1<<TXB8);
   UDR=data;
}

void printString(char *str)
{
	while(*str>0){	
	serialWrite(*str++);}
}

void printStringln(char *str)
{
  while(*str>0){	
	serialWrite(*str++);}
	serialWrite(0x0a);
  serialWrite(0x0D);
}

void readString(char myString[], uint8_t maxLength)
{
  char response;
  uint8_t i;
  i = 0;
  while (i < (maxLength - 1)) 
  {                 
    response = receiveByte();
    transmitByte(response);                             
    if (response == '\r') 
    {                    
      break;
    }
    else 
    {
      myString[i] = response;                  
      i++;
    }
  }
  myString[i] = 0;                         
}
