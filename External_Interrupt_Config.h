/*
 * External_Interrupt_Config.h
 *
 * Created: 7/9/2021 9:15:16 PM
 *  Author: karim
 */ 


#ifndef EXTERNAL_INTERRUPT_CONFIG_H_
#define EXTERNAL_INTERRUPT_CONFIG_H_

#include "CPU_Config.h"
/*
//Define Address for registers
#define GICR   (*(volatile uint8_t*) 0x5B)
#define GIFR   (*(volatile uint8_t*) 0x5A)
#define MCUCR  (*(volatile uint8_t*) 0x55)
#define MCUCSR (*(volatile uint8_t*) 0x54)
*/
//Interrupt Sense
#define EXT_INTRRUPT_SENSE_LOW              0
#define EXT_INTRRUPT_SENSE_LOGICALCHANGE    1
#define EXT_INTRRUPT_SENSE_FALLING          2
#define EXT_INTRRUPT_SENSE_RISING           3
//Interrupts
#define EXT_INTERRUPT_INT0 0
#define EXT_INTERRUPT_INT1 1
#define EXT_INTERRUPT_INT2 2
//State
#define EXT_INTERRUPT_ACTIVATE  EXT_INTERRUPT_INT0
#define EXT_INTERRUPT_SENSE     EXT_INTRRUPT_SENSE_LOW

#endif /* EXTERNAL_INTERRUPT_CONFIG_H_ */