/*
 * LED_Config.h
 *
 * Created: 6/25/2021 10:22:59 PM
 *  Author: karim
 */ 
/*
What should I write inside configuration file ?
1- Macros
2- Register Re-Naming
3- Pin Re-naming
4- Status Re-Naming
*/
#ifndef LED_CONFIG_H_
#define LED_CONFIG_H_
#include "DIO.h"
//Configuration layered naming
#define LED0_PORT   DIO_PORTC
#define LED0_PIN    DIO_PIN2
#define LED1_PORT   DIO_PORTC
#define LED1_PIN    DIO_PIN7
#define LED2_PORT   DIO_PORTD
#define LED2_PIN    DIO_PIN3
//Status
#define LED_ON      DIO_PIN_HIGH
#define LED_OFF     DIO_PIN_LOW
#define LED_OUTPUT  DIO_PIN_OUTPUT
#endif /* LED_CONFIG_H_ */