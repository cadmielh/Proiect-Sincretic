/*
 * proiectsincretic.c
 *
 * Created: 25-Oct-16 1:57:23 PM
 * Author : user
 */ 


#include "pwm.h"
#include "timer_interrupt.h"


int main(void)
{	
	
	PWM_init();
	timer_init();
	sei();
    /* Replace with your application code */
    while (1) 
    {
		PWM_fadein_fadeout();
		
    }
}

