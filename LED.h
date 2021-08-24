/*
 * LED.h
 *
 * Created: 6/25/2021 10:23:10 PM
 *  Author: karim
 */ 
/*
What should I write inside header file ?
1- Macros
2- USerdefined Data-types (If exist)
3- Global Variables (If exist)
4- Functions Prototypes 
*/
#ifndef LED_H_
#define LED_H_

#include "LED_Config.h"
//Function for LED0 prototype
void LED0_Initialization(void);
void LED0_ON(void);
void LED0_OFF(void);
void LED0_TGL(void);

void LED1_Initialization(void);
void LED1_ON(void);
void LED1_OFF(void);
void LED1_TGL(void);

void LED2_Initialization(void);
void LED2_ON(void);
void LED2_OFF(void);
void LED2_TGL(void);


#endif /* LED_H_ */