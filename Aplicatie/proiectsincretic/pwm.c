/*
 * PWM.c
 *
 * Created: 01-Nov-16 10:46:00 AM
 *  Author: user
 */ 
#include "pwm.h"

int t=0,state=0;


void PWM_init()
{
	//Fast PWM mode, clear on compare match
	//TCCR0A|=(1<<COM0A1)|(1<<WGM01)|(1<<WGM00);
	//Phase correct, clear on compare match
	TCCR0A|=(1<<COM0A1)|(1<<WGM00);
	TCCR0B|=(1<<CS00);	//no prescaler
	//PWM pin
	DDRD|=(1<<PIND6);
}

void timer2_init()
{
	//TCNT2 = 3036;
	TCCR2B|=(1<<CS22)|(1<<CS21)|(1<<CS20); //1024 prescaler
	//enabling overflow interrupt
	TIMSK2|=(1<<TOIE2);

}


ISR	(TIMER2_OVF_vect)
{
	t++;
	switch(state)
	{
		case 0: OCR0A = OCR0A +	4;
		if(t==61)
		{
			state=1;
			t=0;
		}
		break;
		case 1:	
		if(t==61)
		{
			
			state=2;
			t=0;
		}
		break;
		case 2:	OCR0A = OCR0A - 4;
		if(t==61)
		{
			state=3;
			t=0;
		}
		break;
		case 3: OCR0A=0;
		if(t==61)
		{
			state=0;
			t=0;
		}
		break;
	}

}
