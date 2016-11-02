/*
 * timer_interrupt.c
 *
 * Created: 02-Nov-16 5:48:30 PM
 *  Author: user
 */ 

#include "timer_interrupt.h"


void timer_init()
{
	//TIMER 1 (16 bit)    -    normal mode
	//prescaler 1024
	TCCR1B |=(1<<CS12)|(1<<CS10)|(1<<WGM12);
	//enabling output compare match A
	TIMSK1 |= (1<<OCIE1A);
	//setting the output compare register A
	OCR1A = 15625;
	
	//setting PIND7 as output - LED
	DDRD|=(1<<PIND7);
}


ISR	(TIMER1_COMPA_vect)
{
	if((PORTD&0b10000000) != 0b10000000)
		PORTD|=(1<<PIND7);
		
	else
		PORTD&=~(1<<PIND7);
}
