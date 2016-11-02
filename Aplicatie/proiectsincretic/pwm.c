/*
 * PWM.c
 *
 * Created: 01-Nov-16 10:46:00 AM
 *  Author: user
 */ 
#include "pwm.h"


void PWM_init()
{
	//Fast PWM mode, clear on compare match
	TCCR0A|=(1<<COM0A1)|(1<<WGM01)|(1<<WGM00);
	TCCR0B|=(1<<CS00);	//no prescaler
	//PWM pin
	DDRD|=(1<<PIND6);
}

void PWM_fadein_fadeout()
{
	
	for(i=0;i<=255;i++)
	{
		OCR0A=i;
		_delay_ms(4);
	}
	_delay_ms(1000);
	for(i=255;i>=0;i--)
	{
		OCR0A=i;
		_delay_ms(4);
	}
	OCR0A=0;
	_delay_ms(1000);
	
}