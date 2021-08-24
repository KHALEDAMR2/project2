/*
* External_Interrupt.c
*
* Created: 7/9/2021 9:14:56 PM
*  Author: karim
*/

#include "External_Interrupt.h"


void External_Interrupt_Init(void)
{
	//Initialize interrupt sense according to configuration
	#if EXT_INTERRUPT_SENSE   == EXT_INTRRUPT_SENSE_LOW
	MCUCR &=~((1<< ISC01) | (1<< ISC00));//In case INT0
	MCUCR &=~((1<< ISC11) | (1<< ISC10));//In case INT1
	/*
	MCUSR |= 0b0000000; 
	MCUCR |= 0x00;
	CLR_BIT(MCUCR, ISC01);CLR_BIT(MCUCR, ISC00);
	CLR_BIT(MCUCR, ISC11);CLR_BIT(MCUCR, ISC10);
	*/
	#elif EXT_INTERRUPT_SENSE == EXT_INTRRUPT_SENSE_LOGICALCHANGE
	MCUCR |= ((1<< ISC10) | (1<< ISC00));
	MCUCR &=~((1<< ISC11) | (1<< ISC01));
	#elif EXT_INTERRUPT_SENSE == EXT_INTRRUPT_SENSE_FALLING
	MCUCR |= ((1<< ISC11) | (1<< ISC01));
	MCUCR &=~((1<< ISC10) | (1<< ISC00));
	#elif EXT_INTERRUPT_SENSE == EXT_INTRRUPT_SENSE_RISING
	MCUCR |= ((1<< ISC01) | (1<< ISC00));//In case INT0
	MCUCR |= ((1<< ISC11) | (1<< ISC10));//In case INT1
	#endif
	//Initialize interrupt according to configuration(Room Door)
	#if EXT_INTERRUPT_ACTIVATE   == EXT_INTERRUPT_INT0
	//SET_BIT(GICR, INT0);
	GICR |= (1<<INT0);
	#elif EXT_INTERRUPT_ACTIVATE == EXT_INTERRUPT_INT1
	//SET_BIT(GICR, INT1);
	GICR |= (1<<INT1);
	#elif EXT_INTERRUPT_ACTIVATE == EXT_INTERRUPT_INT2
	//SET_BIT(GICR, INT2
	GICR |= (1<<INT2);
	#endif
	//Enable Global interrupt(Apartment Door)
	SET_BIT(SREG, 7);
	//SREG |= (1 << 7);
}

/*void ISR(INT0_vect) //function for interrupt routine service
{
	////
	
};*/