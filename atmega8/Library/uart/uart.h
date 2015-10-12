#ifndef uart
#define uart

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#define UBBR(BAUD) ((F_CPU/16)/BAUD)-1

void uartBegin(uint16_t baud);
void serialWrite(char data);
char serialRead(void);
void printString(char *str);
void printStringln(char *str);
int main(void);

#endif
