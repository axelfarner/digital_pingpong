#include <avr/io.h>
#include <stdint.h>

#define F_CPU 4915200// Clock Speed
#define BAUD 9600
#define MYUBRR F_CPU/16/BAUD-1

void UART_init(uint32_t ubrr);
void UART_transmit(unsigned char data);
unsigned char UART_receive( void );