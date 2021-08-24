/*
* LCD_Config.h
*
* Created: 7/3/2021 8:35:26 PM
*  Author: karim
*/


#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_
//Define macros needed
#include "CPU_Config.h"
//Modes
#define BIT4_Mode 0
#define BIT8_Mode 1
//Renaming Ports
#define LCD_DTA_PRT  DIO_PORTA
#define LCD_CTRL_PRT DIO_PORTB
//Renaming Pins
#define LCD_RS     DIO_PIN1
#define LCD_RW     DIO_PIN2
#define LCD_EN     DIO_PIN3
#define LCD_D0     DIO_PIN0
#define LCD_D1     DIO_PIN1
#define LCD_D2     DIO_PIN2
#define LCD_D3     DIO_PIN3
#define LCD_D4     DIO_PIN4
#define LCD_D5     DIO_PIN5
#define LCD_D6     DIO_PIN6
#define LCD_D7     DIO_PIN7
//Renaming States
#define LCD_LOW    DIO_PIN_LOW
#define LCD_HIGH   DIO_PIN_HIGH
#define LCD_OUTPUT DIO_PIN_OUTPUT
//Data port renaming
#define LCD_PRT    PORTA
//Define LCD mode will be used
#define LCD_MODE   BIT4_Mode
#endif /* LCD_CONFIG_H_ */