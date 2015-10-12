#ifndef LCD
#define LCD

#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>

#define Scribble 					    PORTB
#define DataDir_Scribble 			DDRB
#define Control 					    PORTD
#define DataDir_Control 			DDRD
#define Enable 						    5
#define ReadWrite 					  7
#define BiPolarMood 				  2

void Check_IF_MrLCD_isBusy	(void);
void Peek_A_Boo						  (void);
void Send_A_Command					(unsigned char command);
void Send_A_Character				(unsigned char character);
void LCDPrint						    (char *String);
void GotoXY							    (uint8_t x, uint8_t y);
void LCDBegin						    (void);
void LCDClear						    (void);
void LCDCursorBlink					(int num);
void LCDCursor						  (int num);
void LCDDisplay						  (int num);
void LCDShiftLeft					  (int num);
void LCDGotoXYPrint					(uint8_t x, uint8_t y, char *strings);
void LCDShiftRight					(int num);
#endif
