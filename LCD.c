/*
* LCD.c
*
* Created: 7/3/2021 8:35:44 PM
*  Author: karim
*/
#include "LCD.h"
#include <stdio.h>
#include <math.h>

void reverse(char* str, int len)
{
	int i = 0, j = len - 1, temp;
	while (i < j) {
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
}
int intToStr(int x, char str[], int d)
{
	int i = 0;
	while (x) {
		str[i++] = (x % 10) + '0';
		x = x / 10;
	}
	
	// If number of digits required is more, then
	// add 0s at the beginning
	while (i < d)
	str[i++] = '0';
	
	reverse(str, i);
	str[i] = '\0';
	return i;
}
void ftoa(float n, char* res, int afterpoint)
{
	// Extract integer part
	int ipart = (int)n;
	
	// Extract floating part
	float fpart = n - (float)ipart;
	
	// convert integer part to string
	int i = intToStr(ipart, res, 0);
	
	// check for display option after point
	if (afterpoint != 0) {
		res[i] = '.'; // add dot
		
		// Get the value of fraction part upto given no.
		// of points after dot. The third parameter
		// is needed to handle cases like 233.007
		fpart = fpart * pow(10, afterpoint);
		
		intToStr((int)fpart, res + i + 1, afterpoint);
	}
}
void LCD_Initialization(void)
{
	//Define pins direction for control pins
	DIO_SetPin_Direction(LCD_CTRL_PRT, LCD_RS, LCD_OUTPUT);
	DIO_SetPin_Direction(LCD_CTRL_PRT, LCD_RW, LCD_OUTPUT);
	DIO_SetPin_Direction(LCD_CTRL_PRT, LCD_EN, LCD_OUTPUT);
	//Define pins direction for data pins
	DIO_SetPin_Direction(LCD_DTA_PRT, LCD_D4, LCD_OUTPUT);
	DIO_SetPin_Direction(LCD_DTA_PRT, LCD_D5, LCD_OUTPUT);
	DIO_SetPin_Direction(LCD_DTA_PRT, LCD_D6, LCD_OUTPUT);
	DIO_SetPin_Direction(LCD_DTA_PRT, LCD_D7, LCD_OUTPUT);
	//Check mode
	#if   LCD_MODE   == BIT4_Mode
	LCD_Command(0x33);/*Define working in 4BIT mode*/
	LCD_Command(0x32);/*Define working in 4BIT mode*/
	LCD_Command(0x28);/*Use 4BIT mode*/
	LCD_Command(0x02);/*Return home*/
	LCD_Command(0x0C);/*Display ON, Cursor OFF*/
	LCD_Command(0x01);/*Clear screen*/
	LCD_Command(0x06);/*Increment cursor right*/
	#elif LCD_MODE == BIT8_Mode
	LCD_Command(0x0E);/*Define working in 4BIT mode*/
	LCD_Command(0x38);/*Use 4BIT mode*/
	LCD_Command(0x02);/*Return home*/
	LCD_Command(0x0C);/*Display ON, Cursor OFF*/
	LCD_Command(0x01);/*Clear screen*/
	LCD_Command(0x06);/*Increment cursor right*/
	#else
	/*Error State*/
	#endif
	//To be sure that all pins are in off state
	DIO_SetPin_Value(LCD_CTRL_PRT, LCD_RS, LCD_LOW);
	DIO_SetPin_Value(LCD_CTRL_PRT, LCD_RW, LCD_LOW);
	DIO_SetPin_Value(LCD_CTRL_PRT, LCD_EN, LCD_LOW);
	DIO_SetPin_Value(LCD_DTA_PRT, LCD_D4, LCD_LOW);
	DIO_SetPin_Value(LCD_DTA_PRT, LCD_D5, LCD_LOW);
	DIO_SetPin_Value(LCD_DTA_PRT, LCD_D6, LCD_LOW);
	DIO_SetPin_Value(LCD_DTA_PRT, LCD_D7, LCD_LOW);
}
void LCD_Clear(void)
{
	LCD_Command(0x01);
}
void LCD_Command(uint8_t command)
{
	DIO_SetPin_Value(LCD_CTRL_PRT, LCD_RS, LCD_LOW);//Select Command Register
	DIO_SetPin_Value(LCD_CTRL_PRT, LCD_RW, LCD_LOW);//Write on Screen
	DIO_SetPin_Value(LCD_CTRL_PRT, LCD_EN, LCD_LOW);//Disable data
	//Sending High nibbles
	LCD_PRT = ((command & 0xF0) | (LCD_PRT & 0x0F));
	DIO_SetPin_Value(LCD_CTRL_PRT, LCD_EN, LCD_HIGH);//Enable data
	_delay_ms(1);
	DIO_SetPin_Value(LCD_CTRL_PRT, LCD_EN, LCD_LOW);//Disable data
	//Sending Low nibbles
	LCD_PRT = ((command << 4) | (LCD_PRT & 0x0F));
	DIO_SetPin_Value(LCD_CTRL_PRT, LCD_EN, LCD_HIGH);//Enable data
	_delay_ms(1);
	DIO_SetPin_Value(LCD_CTRL_PRT, LCD_EN, LCD_LOW);//Disable data
	_delay_ms(5);
}
void LCD_Character(uint8_t character)
{
	DIO_SetPin_Value(LCD_CTRL_PRT, LCD_RS, LCD_HIGH);//Select Data Register
	DIO_SetPin_Value(LCD_CTRL_PRT, LCD_RW, LCD_LOW);//Write on Screen
	DIO_SetPin_Value(LCD_CTRL_PRT, LCD_EN, LCD_LOW);//Disable data
	//Sending High nibbles
	LCD_PRT = ((character & 0xF0) | (LCD_PRT & 0x0F));
	DIO_SetPin_Value(LCD_CTRL_PRT, LCD_EN, LCD_HIGH);//Enable data
	_delay_ms(1);
	DIO_SetPin_Value(LCD_CTRL_PRT, LCD_EN, LCD_LOW);//Disable data
	//Sending Low nibbles
	LCD_PRT = ((character << 4) | (LCD_PRT & 0x0F));
	DIO_SetPin_Value(LCD_CTRL_PRT, LCD_EN, LCD_HIGH);//Enable data
	_delay_ms(1);
	DIO_SetPin_Value(LCD_CTRL_PRT, LCD_EN, LCD_LOW);//Disable data
	_delay_ms(5);
}
void LCD_String(uint8_t* str)
{
	while (*str != '\0')
	{
		LCD_Character(*str);
		str++;
	}
}
void LCD_Number(uint32_t DecimalNumber)
{
	uint8_t num[10];
	ltoa(DecimalNumber, (uint8_t*)num, 10);
	LCD_String((uint8_t*)num);
}
void LCD_Float(Fint32_t FloatNumber)
{
	char num[10];
	ftoa(FloatNumber, num, 3);
	LCD_String((uint8_t*)num);
}
void LCD_Arabic(uint8_t* Arabic)
{
	//Task of the week
}