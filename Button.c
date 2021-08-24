/*
* Button.c
*
* Created: 6/26/2021 8:14:24 PM
*  Author: karim
*/

#include "Button.h"

void Button0_Initialization(void)
{
	//Define Direction as input
	CLR_BIT(BTN0_DDR, BTN0);
	//Activate Internal Pull-Up Resistor, Avoid Floating
	SET_BIT(BTN0_PRT, BTN0);
}
uint8_t Button0_Read(void)
{
	_delay_ms(10);//For denouncing
	if(GET_BIT(BTN0_PIN, BTN0) == 0)
	{
		return 1;
	}
	return 0;
}
void Button1_Initialization(void)
{
	
}
uint8_t Button1_Read(void)
{
	return BTN_NPressed;
}
void Button2_Initialization(void)
{
	
}
uint8_t Button2_Read(void)
{
	return BTN_NPressed;
}