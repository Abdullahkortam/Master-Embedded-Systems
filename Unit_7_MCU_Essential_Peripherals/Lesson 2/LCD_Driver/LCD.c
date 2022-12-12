/*
 * LCD.c
 *
 * Created: 04/11/2022 08:08:21 م
 *  Author: Abdullah Kortam
 */ 
#include "LCD.h"
void LCD_KICK()
{
	LCD_CTRL &= ~(1<<EN_PIN);
	_delay_ms(30);
	LCD_CTRL |= (1<<EN_PIN);
}

void LCD_GOTO(int line , int position)
{
	if(line == 1)
	{
		if(position <16 && position >=0)
		LCD_WRITE_COMMAND(LCD_CMD_BEGIN_AT_FIRST_ROW+position);
	}
	else if(line == 2)
	{
		if(position <16 && position >=0)
		LCD_WRITE_COMMAND(LCD_CMD_BEGIN_AT_SECOND_ROW+position);
	}
	else if(line == 3)
	{
		if(position <16 && position >=0)
		LCD_WRITE_COMMAND(LCD_CMD_BEGIN_AT_THIRD_ROW+position);
	}
	else if(line == 4)
	{
		if(position <16 && position >=0)
		LCD_WRITE_COMMAND(LCD_CMD_BEGIN_AT_fourth_ROW+position);
	}
}
void LCD_Clear_Screen(void)
{
	LCD_WRITE_COMMAND(LCD_CMD_CLEAR_SCREEN);
}
void LCD_isbusy()
{
	_delay_ms(20);
	DataDir_LCD_PORT &= ~ (0xFF << DATA_SHIFT) ;
	LCD_CTRL |= (1<<RW_PIN) ;
	LCD_CTRL &= ~(1<<RS_PIN) ;
	LCD_KICK();
	DataDir_LCD_PORT = 0xFF ;
	LCD_CTRL &= ~(1<<RW_PIN);
}
void LCD_INIT()
{
	_delay_ms(20);
	LCD_isbusy();
	DataDir_LCD_CTRL |= (1<<RS_PIN) | (1<<RW_PIN) | (1<<EN_PIN) ;
	LCD_CTRL &= ~ (1<<RS_PIN) | (1<<RW_PIN) | (1<<EN_PIN) ;
	DataDir_LCD_PORT = 0xFF ;
	_delay_ms(15);
	LCD_Clear_Screen();
	
	#ifdef EIGHT_BIT_MODE
		LCD_WRITE_COMMAND(LCD_CMD_FUNCTION_8BIT_2LINES);
	#endif
	
	#ifdef FOUR_BIT_MODE
		LCD_WRITE_COMMAND(0x02);
		LCD_WRITE_COMMAND(LCD_CMD_FUNCTION_4BIT_2LINES);
	#endif
	
	LCD_WRITE_COMMAND(LCD_CMD_ENTRY_MODE);
	LCD_WRITE_COMMAND(LCD_CMD_BEGIN_AT_FIRST_ROW);
	LCD_WRITE_COMMAND(LCD_CMD_DISP_ON_CURSOR_BLINK);
	
}

void LCD_WRITE_COMMAND(unsigned char command)
{
	#ifdef EIGHT_BIT_MODE
		LCD_isbusy();
		LCD_PORT = command ;
		LCD_CTRL &= ~(1<<RW_PIN);
		LCD_CTRL &= ~(1<<RS_PIN);
		_delay_ms(1);
		LCD_KICK();
	#endif
	
	#ifdef  FOUR_BIT_MODE
		LCD_isbusy();
		LCD_PORT = (LCD_PORT & 0x0F) | (command & 0xF0) ;
		LCD_CTRL &= ~ ((1<<RW_PIN) | (1<<RS_PIN)) ;
		_delay_ms(1);
		LCD_KICK() ;
		LCD_PORT = (LCD_PORT & 0x0F) | (command<<4)  ;
		LCD_CTRL &= ~ ((1<<RW_PIN) | (1<<RS_PIN)) ;
		_delay_ms(1);
		LCD_KICK() ;
	#endif
	
	
}

void LCD_WRITE_CHAR(unsigned char data)
{
	#ifdef EIGHT_BIT_MODE
		LCD_isbusy();
		LCD_CTRL |=  (1<<RS_PIN);
		LCD_PORT = data ;
		LCD_CTRL &= ~(1<<RW_PIN);
		LCD_CTRL |=  (1<<RS_PIN);
		LCD_KICK();
	#endif
	
	#ifdef FOUR_BIT_MODE
		LCD_PORT = (LCD_PORT & 0x0F) | (data & 0xF0) ;
		LCD_CTRL &= ~(1<<RW_PIN) ;
		LCD_CTRL |= (1<<RS_PIN);
		LCD_KICK();
		_delay_ms(1);
		LCD_PORT = (LCD_PORT & 0x0F) | (data<<4); 
		LCD_CTRL &= ~(1<<RW_PIN) ;
		LCD_CTRL |= (1<<RS_PIN);
		_delay_ms(1);
		LCD_KICK();
		
	#endif
}

void LCD_WRITE_STRING(char* data)
{
	int count =0 ;
	while(*data >0)
	{
		count++ ;
		LCD_WRITE_CHAR(*data++);
		if (count==16)
		{
			LCD_GOTO(2,0);
		}
		else if(count ==32)
		{
			LCD_GOTO(3,0);
		}
		else if(count ==48)
		{
			LCD_GOTO(4,0);
		}
		else if(count ==64)
		{
			LCD_Clear_Screen();
			LCD_GOTO(1,0);
			count =0 ;
		}
	}
	
}
void LCD_Interface(char r)
{
	switch(r)
	{
		case('?'):
		LCD_Clear_Screen();
		break;
		case 'N':
		break;
		default:
		LCD_WRITE_CHAR(r);
		break;
	}
}