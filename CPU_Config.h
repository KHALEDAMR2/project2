/*
 * CPU_Config.h
 *
 * Created: 6/26/2021 8:10:10 PM
 *  Author: karim
 */ 


#ifndef CPU_CONFIG_H_
#define CPU_CONFIG_H_

#undef F_CPU //Deactivate internal clock
#define F_CPU 16000000 //Activate external clock 16MHz
#include <avr/io.h> //Define registers and pins for AVR
#include <util/delay.h> //Define Delay function
#include <avr/interrupt.h> //Define interrupts for AVR
#include "BIT_MATH.h"
#include "STD_Types.h"
#include "DIO.h"

#endif /* CPU_CONFIG_H_ */