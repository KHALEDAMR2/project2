/*
 * Keypad_Config.h
 *
 * Created: 7/3/2021 9:49:34 PM
 *  Author: karim
 */ 


#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_

#include "CPU_Config.h"
//Renaming Ports
#define KEYPAD_PORT             DIO_PORTC
//Renaming for pins
#define KEYPAD_PIN_OUTPUT0      DIO_PIN0
#define KEYPAD_PIN_OUTPUT1      DIO_PIN1
#define KEYPAD_PIN_OUTPUT2      DIO_PIN2
#define KEYPAD_PIN_OUTPUT3      DIO_PIN3
#define KEYPAD_PIN_INPUT0       DIO_PIN4
#define KEYPAD_PIN_INPUT1       DIO_PIN5
#define KEYPAD_PIN_INPUT2       DIO_PIN6
#define KEYPAD_PIN_INPUT3       DIO_PIN7
//Renaming States
#define KEYPAD_INPUT            DIO_PIN_INPUT
#define KEYPAD_OUTPUT           DIO_PIN_OUTPUT
#define KEYPAD_LOW              DIO_PIN_LOW
#define KEYPAD_HIGH             DIO_PIN_HIGH
//Renaming buttons
#define KEYPAD_COL_INIT         0
#define KEYPAD_COL_END          3

#define KEYPAD_ROW_INIT         4
#define KEYPAD_ROW_END          7

#define KEYPAD_PRESSED          0

#endif /* KEYPAD_CONFIG_H_ */