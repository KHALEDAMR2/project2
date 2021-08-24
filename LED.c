/*
* LED.c
*
* Created: 6/25/2021 10:23:20 PM
*  Author: karim
*/
/*
What should I write inside header file ?
1- Macros
2- Function Implementations
*/
#include "LED.h"

void LED0_Initialization(void)
{
	//SET_BIT(LED0_DDR, LED0_PIN);//Define direction for LED
	DIO_SetPin_Direction(LED0_PORT, LED0_PIN, LED_OUTPUT);
}
void LED0_ON(void)
{
	//SET_BIT(LED0_PORT, LED0_PIN);//LED-ON
	DIO_SetPin_Value(LED0_PORT, LED0_PIN, LED_ON);
}
void LED0_OFF(void)
{
	//CLR_BIT(LED0_PORT, LED0_PIN);//LED-OFF
	DIO_SetPin_Value(LED0_PORT, LED0_PIN, LED_OFF);
}
void LED0_TGL(void)
{
	//TGL_BIT(LED0_PORT, LED0_PIN);//LED-Toggle
	DIO_TogglePin_Value(LED0_PORT, LED0_PIN);
}

void LED1_Initialization(void)
{
	DIO_SetPin_Direction(LED1_PORT, LED1_PIN, LED_OUTPUT);
}
void LED1_ON(void)
{
	//SET_BIT(LED0_PORT, LED0_PIN);//LED-ON
	DIO_SetPin_Value(LED1_PORT, LED1_PIN, LED_ON);
	
}
void LED1_OFF(void)
{
		//CLR_BIT(LED0_PORT, LED0_PIN);//LED-OFF
		DIO_SetPin_Value(LED1_PORT, LED1_PIN, LED_OFF);
}
void LED1_TGL(void)
{
	//TGL_BIT(LED0_PORT, LED0_PIN);//LED-Toggle
	DIO_TogglePin_Value(LED1_PORT, LED1_PIN);
}


void LED2_Initialization(void)
{
	DIO_SetPin_Direction(LED2_PORT, LED2_PIN, LED_OUTPUT);
}
void LED2_ON(void)
{
	//SET_BIT(LED0_PORT, LED0_PIN);//LED-ON
	DIO_SetPin_Value(LED2_PORT, LED2_PIN, LED_ON);
	
}
void LED2_OFF(void)
{
	
	//CLR_BIT(LED0_PORT, LED0_PIN);//LED-OFF
	DIO_SetPin_Value(LED2_PORT, LED2_PIN, LED_OFF);
}
void LED2_TGL(void)
{
	//TGL_BIT(LED0_PORT, LED0_PIN);//LED-Toggle
	DIO_TogglePin_Value(LED2_PORT, LED2_PIN);
	
}

