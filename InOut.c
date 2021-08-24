/*
 * InOut.c
 *
 * Created: 6/26/2021 6:27:55 PM
 *  Author: karim
 */ 

#include "InOut.h"

void Buzzer_Initialization(void)
{
	SET_BIT(BuzzerDDR, BuzzerPIN);
}
void Buzzer_ON(void)
{
	SET_BIT(BuzzerPRT, BuzzerPIN);
}
void Buzzer_OFF(void)
{
	CLR_BIT(BuzzerPRT, BuzzerPIN);
}
void Buzzer_TGL(void)
{
	TGL_BIT(BuzzerPRT, BuzzerPIN);
}

void Relay_Initialization(void)
{
	SET_BIT(RelayDDR, RelayPIN);
}
void Relay_ON(void)
{
	SET_BIT(RelayPRT, RelayPIN);
}
void Relay_OFF(void)
{
	CLR_BIT(RelayPRT, RelayPIN);
}
void Relay_TGL(void)
{
	TGL_BIT(RelayPRT, RelayPIN);
}

void buzzer_ring(void)//buzzer ring for one second
{
	Buzzer_ON();
	_delay_ms(500);
	Buzzer_OFF();
}