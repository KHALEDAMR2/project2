/*
* DIO.c
*
* Created: 6/26/2021 8:41:52 PM
*  Author: karim
*/

#include "DIO.h"

void DIO_SetPin_Direction(uint8_t port, uint8_t pin, uint8_t direction)
{
	switch (direction)
	{
		case DIO_PIN_INPUT:
		switch(port)
		{
			case DIO_PORTA:
			CLR_BIT(DDRA, pin);
			break;
			case DIO_PORTB:
			CLR_BIT(DDRB, pin);
			break;
			case DIO_PORTC:
			CLR_BIT(DDRC, pin);
			break;
			case DIO_PORTD:
			CLR_BIT(DDRD, pin);
			break;
		}
		break;
		case DIO_PIN_OUTPUT:
		switch(port)
		{
			case DIO_PORTA:
			SET_BIT(DDRA, pin);
			break;
			case DIO_PORTB:
			SET_BIT(DDRB, pin);
			break;
			case DIO_PORTC:
			SET_BIT(DDRC, pin);
			break;
			case DIO_PORTD:
			SET_BIT(DDRD, pin);
			break;
		}
		break;
	}
}
void DIO_SetPin_Value(uint8_t port, uint8_t pin, uint8_t value)
{
	switch (value)
	{
		case DIO_PIN_LOW:
		switch(port)
		{
			case DIO_PORTA:
			CLR_BIT(PORTA, pin);
			break;
			case DIO_PORTB:
			CLR_BIT(PORTB, pin);
			break;
			case DIO_PORTC:
			CLR_BIT(PORTC, pin);
			break;
			case DIO_PORTD:
			CLR_BIT(PORTD, pin);
			break;
		}
		break;
		case DIO_PIN_HIGH:
		switch(port)
		{
			case DIO_PORTA:
			SET_BIT(PORTA, pin);
			break;
			case DIO_PORTB:
			SET_BIT(PORTB, pin);
			break;
			case DIO_PORTC:
			SET_BIT(PORTC, pin);
			break;
			case DIO_PORTD:
			SET_BIT(PORTD, pin);
			break;
		}
		break;
	}
}
void DIO_TogglePin_Value(uint8_t port, uint8_t pin)
{
	switch(port)
	{
		case DIO_PORTA:
		TGL_BIT(PORTA, pin);
		break;
		case DIO_PORTB:
		TGL_BIT(PORTB, pin);
		break;
		case DIO_PORTC:
		TGL_BIT(PORTC, pin);
		break;
		case DIO_PORTD:
		TGL_BIT(PORTD, pin);
		break;
	}
}
void DIO_SetPin_PullUp(uint8_t port, uint8_t pin)
{
	switch(port)
	{
		case DIO_PORTA:
		SET_BIT(PORTA, pin);
		break;
		case DIO_PORTB:
		SET_BIT(PORTB, pin);
		break;
		case DIO_PORTC:
		SET_BIT(PORTC, pin);
		break;
		case DIO_PORTD:
		SET_BIT(PORTD, pin);
		break;
	}
}
uint8_t DIO_ReadPin_Value(uint8_t port, uint8_t pin)
{
	uint8_t btn = 1;
	switch (port)
	{
		case DIO_PORTA:
		btn = GET_BIT(PINA, pin);
		break;
		case DIO_PORTB:
		btn = GET_BIT(PINB, pin);
		break;
		case DIO_PORTC:
		btn = GET_BIT(PINC, pin);
		break;
		case DIO_PORTD:
		btn = GET_BIT(PIND, pin);
		break;
	}
	return btn;
}
void DIO_SetPullUp(uint8_t port, uint8_t pin)
{
	switch(port)
	{
		case DIO_PORTA:
		SET_BIT(PORTA, pin);
		break;
		case DIO_PORTB:
		SET_BIT(PORTB, pin);
		break;
		case DIO_PORTC:
		SET_BIT(PORTC, pin);
		break;
		case DIO_PORTD:
		SET_BIT(PORTD, pin);
		break;
	}
}
