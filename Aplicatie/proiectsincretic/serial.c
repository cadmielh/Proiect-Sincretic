/*
 * CFile1.c
 *
 * Created: 15-Nov-16 12:05:28 PM
 *  Author: user
 */ 

#include "serial.h"


void USART_Init( unsigned int ubrr)
{
	/*Set baud rate */
	UBRR0H = (unsigned char)(ubrr>>8);
	UBRR0L = (unsigned char)ubrr;
	/*Enable receiver and transmitter */
	UCSR0B = (1<<RXEN0)|(1<<TXEN0)|(1<<RXCIE0);
	/* Set frame format: 8data, 2stop bit */
	UCSR0C = (1<<USBS0)|(1<<UCSZ01)|(1<<UCSZ00);
	DDRB |= (1<<PINB4);
}

void USART_Transmit( unsigned char data )
{
	/* Wait for empty transmit buffer */
	while ( !( UCSR0A & (1<<UDRE0)) )
	;
	/* Put data into buffer, sends the data */
	UDR0 = data;
}

unsigned char USART_Receive( void )
{
	/* Wait for data to be received */
	while ( !(UCSR0A & (1<<RXC0)) )
	;
	/* Get and return received data from buffer */
	return UDR0;
}

void sending_string(unsigned char* str)
{
	int i;
	for ( i = 0; i < 256; i++ )
	{
		if (str[i] == '\0')
		{
			break;
		}
		else
		{
			USART_Transmit(str[i]);
		}
	}
}

ISR (USART_RX_vect)
{
	PORTB|= 1<<PINB4;
	/*if(UDR0=='a')
		{
			PORTB|= 1<<PINB4;
		}
	else if(UDR0=='s')
		{
			PORTB &= ~(1<<PINB4);
		}*/
}