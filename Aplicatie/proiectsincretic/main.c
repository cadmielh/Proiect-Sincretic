/*
 * proiectsincretic.c
 *
 * Created: 25-Oct-16 1:57:23 PM
 * Author : user
 */ 


#include "pwm.h"
#include "timer_interrupt.h"
#include "serial.h"


int main(void)
{	
	
	PWM_init();
	timer1_init();
	timer2_init();
	USART_Init(MYUBRR);
	
	unsigned char str[]="Hello World!";
	int once=0;
	
	sei();
    
	/* Replace with your application code */
    while (1) 
    {
		PWM_fadein_fadeout();
		if(once==0)
		{
			sending_string(str);
			once=1;
		}
		
    }
}

