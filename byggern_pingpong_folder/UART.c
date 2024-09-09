#include "UART.h"


void UART_init(uint32_t ubrr) {
	fdevopen(UART_transmit,UART_receive);
	UBRR0H = (unsigned char)(ubrr>>8);
	UBRR0L = (unsigned char)(ubrr);
	
	UCSR0B = (1<<RXEN0) | (1<<TXEN0);
	UCSR0C =  (1<<URSEL0)|(1<<USBS0)|(3<<UCSZ00);
}

void UART_transmit(unsigned char data)
{
	/* Wait for empty transmit buffer */
	while ( !( UCSR0A & (1<<UDRE0)) ){};
	
	/* Put data into buffer, sends the data */
	UDR0 = data;
}

unsigned char UART_receive( void )
{
	/* Wait for data to be received */
	while ( !(UCSR0A & (1<<RXC0)) )
	;
	/* Get and return received data from buffer */
	return UDR0;
}