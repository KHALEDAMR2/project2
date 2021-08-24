/*
* DIO.h
*
* Created: 6/26/2021 8:41:42 PM
*  Author: karim
*/


#ifndef DIO_H_
#define DIO_H_

#include "CPU_Config.h"
//#include "DIO_Address.h"
#include "DIO_Config.h"

void DIO_SetPin_Direction(uint8_t port, uint8_t pin, uint8_t direction);
void DIO_SetPin_Value(uint8_t port, uint8_t pin, uint8_t value);
void DIO_TogglePin_Value(uint8_t port, uint8_t pin);
void DIO_SetPin_PullUp(uint8_t port, uint8_t pin);
uint8_t DIO_ReadPin_Value(uint8_t port, uint8_t pin);
void DIO_SetPullUp(uint8_t port, uint8_t pin);



#endif /* DIO_H_ */