#include "LCD.h"

void LCDBegin()
{
  DataDir_Control |= 1<<Enable | 1<<ReadWrite | 1<<BiPolarMood;
	_delay_ms(15);
	Send_A_Command(0x01); 
	_delay_ms(2);
	Send_A_Command(0x38);
	_delay_us(50);
	Send_A_Command(0b00001100);
	_delay_us(50);
}

void Check_IF_MrLCD_isBusy()
{
	DataDir_Scribble = 0;
	Control |= 1<<ReadWrite;
	Control &= ~1<<BiPolarMood;

	while (Scribble >= 0x80)
	{
		Peek_A_Boo();
	}
	DataDir_Scribble = 0xFF; //0xFF means 0b11111111
}

void Peek_A_Boo()
{
	Control |= 1<<Enable;
	asm volatile ("nop");
	asm volatile ("nop");
	Control &= ~1<<Enable;
}

void Send_A_Command(unsigned char command)
{
	Check_IF_MrLCD_isBusy();
	Scribble = command;
	_delay_us(50);
	Control &= ~ ((1<<ReadWrite)|(1<<BiPolarMood));
	Peek_A_Boo();
	Scribble = 0;
}

void Send_A_Character(unsigned char character)
{
	Check_IF_MrLCD_isBusy();
	Scribble = character;
	_delay_us(50);
	Control &= ~ (1<<ReadWrite);
	Control |= 1<<BiPolarMood;
	Peek_A_Boo();
	Scribble = 0;
}

void LCDPrint(char *String)
{
	while (*String>0)
	{
		Send_A_Character(*String++);
		_delay_us(45);
	}
}

char columnposition[2] = {0,64};

void GotoXY(uint8_t x, uint8_t y)
{
	Send_A_Command(0x80 + columnposition[y-1] + (x-1));
}

void LCDClear()
{
	Send_A_Command(0x01); 
	_delay_ms(2);
}

void LCDCursor(int num)
{
	if(num == 0)
	{
		Send_A_Command(0x0C); 
		_delay_ms(50);
	}
	if(num == 1)
	{
		Send_A_Command(0x0E); 
		_delay_ms(50);
	}
}

void LCDCursorBlink(int num)
{
	if(num == 0)
	{
		Send_A_Command(0x0C); 
		_delay_ms(50);
	}
	if(num == 1)
	{
		Send_A_Command(0x0D); 
		_delay_ms(50);
	}
}


void LCDDisplay(int num)
{
	if(num == 0)
	{
		Send_A_Command(0x08); 
		_delay_ms(50);
	}
	if(num == 1)
	{
		Send_A_Command(0x0c); 
		_delay_ms(50);
	}
}

void LCDShiftLeft(int num)
{
	if(num == 0)
	{
	Send_A_Command(0x10);
	_delay_ms(50);
	}
	
	if(num == 1)
	{
	Send_A_Command(0x18);
	_delay_ms(50);
	}
}

void LCDShiftRight(int num)
{
	if(num == 0)
	{
	Send_A_Command(0x14);
	_delay_ms(50);
	}
	
	if(num == 1)
	{
	Send_A_Command(0x1C);
	_delay_ms(50);
	}
}

void LCDGotoXYPrint(uint8_t x, uint8_t y, char *strings)
{
	
	Send_A_Command(0x80 + columnposition[y-1] + (x-1));
	while (*strings>0)
	{
		Send_A_Character(*strings++);
		_delay_us(45);
	}
}
