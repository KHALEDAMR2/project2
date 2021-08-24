/*
 * LCD.h
 *
 * Created: 7/3/2021 8:35:35 PM
 *  Author: karim
 */ 


#ifndef LCD_H_
#define LCD_H_
#include "LCD_Config.h"

void LCD_Initialization(void);
void LCD_Clear(void);
void LCD_Command(uint8_t command);
void LCD_Character(uint8_t character);
void LCD_String(uint8_t* str);
void LCD_Number(uint32_t DecimalNumber);
void LCD_Float(Fint32_t FloatNumber);
void LCD_Arabic(uint8_t* Arabic);



#endif /* LCD_H_ */