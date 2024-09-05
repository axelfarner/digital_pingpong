/*
 * byggern_pingpong.c
 *
 * Created: 05.09.2024 09:49:36
 * Author : axelmf
 */ 

#include <avr/io.h>
#include <avr/sleep.h>
#include <stdint.h>

int main(void)
{
    /* Replace with your application code */
	uint32_t i = 0;	
	uint32_t delay = 100000;
	
	//PORTA &= ~(1 << PA0);
	
	while (1) 
    {
		PORTA |= (1 << PA0);	
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
