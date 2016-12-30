/*
 * adc.c
 *
 * Created: 29-Nov-16 11:29:25 AM
 *  Author: user
 */ 
#include "adc.h"

float medie=0;


void adc_init()
{
	//setting Port A as input
	DDRC = 0x00;
	//adc enable, interrupt enable, prescaler of 128
	ADCSRA|=(1<<ADEN)|(1<<ADIE)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);
	// AVcc voltage reference
	ADMUX|=(1<<REFS0);	
	//setting pinb5 as output for the temperature led
	DDRB|=(1<<PINB5);
	//start first conversion
	ADCSRA |= 1<<ADSC;
}

void sending_temperature(float temperature)
{
	int temp = (int)(temperature*10);
	int c,cifra=1;
	
	while(temp/10)
		{
			cifra++;
			temp=temp/10;
		}

	while(cifra)
	{
		c=((int)(temperature*10)/(int)pow(10,cifra-1))%10;
		USART_Transmit(48+c);
		if(cifra==2)
			USART_Transmit('.');
		cifra--;
	}
	USART_Transmit('\n');
}

/*ADC Conversion Complete Interrupt Service Routine (ISR)*/
ISR(ADC_vect)
{
	uint16_t val = ADC;
	float mv = (val/1024.0)*5000;
	float cel = mv/10;
	
	temperatura = cel;
	//sending_temperature(cel);
		
	if(temperatura>=34.5)
		PORTB|=(1<<PINB5);
	else
		PORTB&=~(1<<PINB5);
	
	ADCSRA |= 1<<ADSC;		// Start Conversion
}