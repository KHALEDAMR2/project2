 
/*
 * main.c
 *
 * Created: 6/25/2021 10:50:38 PM
 *  Author: ziyed & hessan
 */

#include "SPI.h"
#include "UART.h"
#include "InOut.h"
#include "LCD.h"
#include "LED.h"

char data;




int main(void)
	
{	LED0_Initialization();
	LED1_Initialization();
	LED2_Initialization();
	Relay_Initialization();
	Buzzer_Initialization();
	LCD_Initialization();
	UART_Init(); 
	LCD_String("Smart Home");
	SPI_Init();
	
	
	sei();  // interrupt for get data coming from bluetooth


}


ISR(USART_RXC_vect)
{
	data = UDR;
while(1)
{
	data = UART_Receive();  // send data to anthor microcontroller
	
	SPI_Transmit(data);
	
	if(data == '1')       // if data = 1 on/off led 1
	{
		LCD_Clear();
		LCD_String("led 1 on ");
		LED0_TGL();
		buzzer_ring();
	}
	
	else if(data == '2')   // if data = 2 on/off led 2
	{
		
		
		LCD_Clear();
		LCD_String("led 2 on");
		LED1_TGL();
		buzzer_ring();
	}
	
	else if(data == '3')   // if data = 3 on/off led 3
	{
		SPI_Transmit(data);
		LCD_Clear();
		LCD_String("led 3 on ");
		LED2_TGL();
		buzzer_ring();
	}
	
}	
	
}