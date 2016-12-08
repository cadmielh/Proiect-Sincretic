/*
 * proiectsincretic.c
 *
 * Created: 25-Oct-16 1:57:23 PM
 * Author : user
 */ 


#include "pwm.h"
#include "led_blink.h"
#include "serial.h"
#include "adc.h"
#include "display_button.h"


int main(void)
{	
	
	PWM_init();
	timer1_init();
	timer2_init();
	USART_Init(MYUBRR);
	adc_init();
	display_init();
	pushbutton_init();
	
	sei();
	
    while (1) 
    {
		
    }
}

