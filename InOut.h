/*
 * InOut.h
 *
 * Created: 6/26/2021 6:27:37 PM
 *  Author: karim
 */ 


#ifndef INOUT_H_
#define INOUT_H_

#include "InOut_Config.h"

void Buzzer_Initialization(void);
void Buzzer_ON(void);
void Buzzer_OFF(void);
void Buzzer_TGL(void);
void buzzer_ring(void);

void Relay_Initialization(void);
void Relay_ON(void);
void Relay_OFF(void);
void Relay_TGL(void);

#endif /* INOUT_H_ */