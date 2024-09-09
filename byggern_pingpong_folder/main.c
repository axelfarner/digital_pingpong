/*
 * byggern_pingpong.c
 *
 * Created: 05.09.2024 09:49:36
 * Author : axelmf
 */ 

#include "UART.h"
#include <avr/io.h>
#include <avr/sleep.h>
#include <stdint.h>
//#include "stdio.h"
#include "utilities.h"



int main(void)
{
	UART_init(MYUBRR);
    /* Replace with your application code */
	uint32_t i = 0;	
	uint32_t delay = 10000;
	
	//PORTA &= ~(1 << PA0);

	

	while(1) {
		UART_transmit(UART_receive());
		i+=1;
		printf(":%d ",i);
	}
	

	while (1) 
    {
		PORTA |= (1 << PA0);
		UART_transmit('g');	
		while (i < delay)
		{
			i++;
		}
		i = 0;

		PORTA &= ~(1 << PA0);
		
		while (i < delay)
		{
			i++;
		}
		i = 0;
    }
}

