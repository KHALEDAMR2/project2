/*
* Keypad.c
*
* Created: 7/3/2021 9:51:52 PM
*  Author: karim
*/
#include "KEYPAD.h"

const uint8_t KEYPAD [4][4]=
{
	{'7','4','1','C'},
	{'8','5','2','0'},
	{'9','6','3','='},
	{'/','*','-','+'}
};

void KEYPAD_Init(void)
{
	/*Define direction for output pins*/
	DIO_SetPin_Direction(KEYPAD_PORT, KEYPAD_PIN_OUTPUT0, KEYPAD_OUTPUT);
	DIO_SetPin_Direction(KEYPAD_PORT, KEYPAD_PIN_OUTPUT1, KEYPAD_OUTPUT);
	DIO_SetPin_Direction(KEYPAD_PORT, KEYPAD_PIN_OUTPUT2, KEYPAD_OUTPUT);
	DIO_SetPin_Direction(KEYPAD_PORT, KEYPAD_PIN_OUTPUT3, KEYPAD_OUTPUT);
	/*Define default state of output pins*/
	DIO_SetPin_Value(KEYPAD_PORT, KEYPAD_PIN_OUTPUT0, KEYPAD_HIGH);
	DIO_SetPin_Value(KEYPAD_PORT, KEYPAD_PIN_OUTPUT1, KEYPAD_HIGH);
	DIO_SetPin_Value(KEYPAD_PORT, KEYPAD_PIN_OUTPUT2, KEYPAD_HIGH);
	DIO_SetPin_Value(KEYPAD_PORT, KEYPAD_PIN_OUTPUT3, KEYPAD_HIGH);
	/*Define direction of input pins*/
	DIO_SetPin_Direction(KEYPAD_PORT, KEYPAD_PIN_INPUT0, KEYPAD_INPUT);
	DIO_SetPin_Direction(KEYPAD_PORT, KEYPAD_PIN_INPUT1, KEYPAD_INPUT);
	DIO_SetPin_Direction(KEYPAD_PORT, KEYPAD_PIN_INPUT2, KEYPAD_INPUT);
	DIO_SetPin_Direction(KEYPAD_PORT, KEYPAD_PIN_INPUT3, KEYPAD_INPUT);
	/*Activate internal pull-up resistor*/
	DIO_SetPullUp(KEYPAD_PORT, KEYPAD_PIN_INPUT0);
	DIO_SetPullUp(KEYPAD_PORT, KEYPAD_PIN_INPUT1);
	DIO_SetPullUp(KEYPAD_PORT, KEYPAD_PIN_INPUT2);
	DIO_SetPullUp(KEYPAD_PORT, KEYPAD_PIN_INPUT3);
}
uint8_t KEYPAD_Read(void)
{
	uint8_t LOC_COL = 0; //Counter for Columns
	uint8_t LOC_ROW = 0; //Counter for Rows
	uint8_t valu = 0;    //Return value from array Keypad
	uint8_t temp = 0;    //Read value for button
	for (LOC_COL = KEYPAD_COL_INIT;LOC_COL <= KEYPAD_COL_END; LOC_COL++)//Loop for Columns
	{
		DIO_SetPin_Value(KEYPAD_PORT, LOC_COL, KEYPAD_LOW);
		for (LOC_ROW = KEYPAD_ROW_INIT; LOC_ROW <= KEYPAD_ROW_END; LOC_ROW++)//Loop for rows
		{
			temp = DIO_ReadPin_Value(KEYPAD_PORT, LOC_ROW);
			if(temp == KEYPAD_PRESSED)
			{
				//Array[Row][Column] = Value
				valu = KEYPAD[LOC_ROW - KEYPAD_ROW_INIT][LOC_COL - KEYPAD_COL_INIT];
				while (temp == KEYPAD_PRESSED)
				{
					temp = DIO_ReadPin_Value(KEYPAD_PORT, LOC_ROW);
				}
				_delay_ms(10);
			}
			
		}
		DIO_SetPin_Value(KEYPAD_PORT, LOC_COL, KEYPAD_HIGH);
	}
	return valu;
}