/*
 * timer_interrupt.c
 *
 * Created: 02-Nov-16 5:48:30 PM
 *  Author: user
 */ 

#include "timer_interrupt.h"

int t=0;


void timer1_init()
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


void timer2_init()
{
	//TCNT2 = 3036;
	TCCR2B|=(1<<CS22)|(1<<CS21)|(1<<CS20); //1024 prescaler
	//enabling overflow interrupt
	TIMSK2|=(1<<TOIE2);

}




ISR(TIMER1_COMPA_vect)
{
	//PORTD ^= ( 1 << PIND7 );
}


ISR	(TIMER2_OVF_vect)
{
	t++;
	if(t==61)
	{
		PORTD ^= ( 1 << PIND7 );
		t=0;
	}
}
