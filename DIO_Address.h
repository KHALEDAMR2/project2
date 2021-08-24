/*
* DIO_Address.h
*
* Created: 6/25/2021 10:34:05 PM
*  Author: karim
*/
/*
1- Get registers name from "Register Description"
2- Get address of registers from "Register Summary"
3- Define Address for Micro controller
*/
/*
1- Define direction for DIO pin, DDRx
2- If output(set, clear, toggle), PORTx
3- If input (get), PINx
*/

#ifndef DIO_ADDRESS_H_
#define DIO_ADDRESS_H_

#define PORTA (*(volatile uint8_t*)0x3B)
#define DDRA  (*(volatile uint8_t*)0x3A)
#define PINA  (*(volatile uint8_t*)0x39)
#define PORTB (*(volatile uint8_t*)0x38)
#define DDRB  (*(volatile uint8_t*)0x37)
#define PINB  (*(volatile uint8_t*)0x36)
#define PORTC (*(volatile uint8_t*)0x35)
#define DDRC  (*(volatile uint8_t*)0x34)
#define PINC  (*(volatile uint8_t*)0x33)
#define PORTD (*(volatile uint8_t*)0x32)
#define DDRD  (*(volatile uint8_t*)0x31)
#define PIND  (*(volatile uint8_t*)0x30)



#endif /* DIO_ADDRESS_H_ */