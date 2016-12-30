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


void EEPROM_write(uint16_t uiAddress, uint8_t ucData)
{
	/* Wait for completion of previous write */
	while(EECR & (1<<EEPE))
	;
	/* Set up address and Data Registers */
	EEAR = uiAddress;
	EEDR = ucData;
	/* Write logical one to EEMPE */
	EECR |= (1<<EEMPE);
	/* Start eeprom write by setting EEPE */
	EECR |= (1<<EEPE);
}

uint8_t EEPROM_read(uint16_t uiAddress)
{
	/* Wait for completion of previous write */
	while(EECR & (1<<EEPE))
	;
	/* Set up address register */
	EEAR = uiAddress;
	/* Start eeprom read by writing EERE */
	EECR |= (1<<EERE);
	/* Return data from Data Register */
	return EEDR;
}





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
	
	display_digit(0);
    
	while (1) 
    {
		
    }
}

