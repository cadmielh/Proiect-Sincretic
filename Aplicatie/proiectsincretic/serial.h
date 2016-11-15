/*
 * uart.h
 *
 * Created: 15-Nov-16 12:06:24 PM
 *  Author: user
 */ 

#ifndef SERIAL_H
#define SERIAL_H

#define BAUD 9600
#define MYUBRR F_CPU/16/BAUD-1

#include "pwm.h"

void USART_Init(unsigned int ubrr);
void USART_Transmit( unsigned char data );
unsigned char USART_Receive( void );
void sending_string(unsigned char* str);



#endif