/*
 * Button_Config.h
 *
 * Created: 6/26/2021 8:13:51 PM
 *  Author: karim
 */ 


#ifndef BUTTON_CONFIG_H_
#define BUTTON_CONFIG_H_
#include "DIO.h"
#define BTN0_DDR        DDRB
#define BTN0_PRT        PORTB
#define BTN0_PIN        PINB
#define BTN0            0
#define BTN1_DDR        DDRD 
#define BTN1_PIN        PIND
#define BTN1            6
#define BTN2_DDR        DDRD 
#define BTN2_PIN        PIND 
#define BTN2            2
#define BTN_Pressed     0
#define BTN_NPressed    1
#endif /* BUTTON_CONFIG_H_ */