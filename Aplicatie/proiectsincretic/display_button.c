/*
 * _7_segmente.c
 *
 * Created: 01-Dec-16 3:30:52 PM
 *  Author: user
 */ 
#include "display_button.h"


int push=1;

void display_init()
{
	//setting 7-digit display leds as output
	DDRB |= (1<<PINB0)|(1<<PINB1)|(1<<PINB2)|(1<<PINB3);
	DDRC |= (1<<PINC1)|(1<<PINC2)|(1<<PINC3)|(1<<PINC4);
	
}

void pushbutton_init()
{
	//setting pushbutton pin as input
	DDRD&=~(1<<PIND2);
	// turn On the Pull-up
	PORTD |= (1 << PIND2);
	//interrupt on falling edge
	EICRA|=(1<<ISC01);
	//enabling external INT0 
	EIMSK|=(1<<INT0);
	//selecting PIND2 as interrupt pin
	//PCMSK2|=(1<<PCINT18);
}

void display_digit(int digit)
{
	switch(digit)
	{
		case 0: PORTB&=~(1<<PINB0);
				PORTC&=~(1<<PINC1);
				PORTB|=(1<<PINB1)|(1<<PINB2)|(1<<PINB3);
				PORTC|=(1<<PINC2)|(1<<PINC3)|(1<<PINC4);
				break;
		case 1: PORTB&=~(1<<PINB0)&~(1<<PINB1)&~(1<<PINB2);
				PORTC&=~(1<<PINC1)&~(1<<PINC3)&~(1<<PINC4);
				PORTB|=1<<PINB3;
				PORTC|=1<<PINC2;
				break;
		case 2: PORTB&=~(1<<PINB1);
				PORTC&=~(1<<PINC1)&~(1<<PINC2);
				PORTB|=(1<<PINB0)|(1<<PINB2)|(1<<PINB3);
				PORTC|=(1<<PINC3)|(1<<PINC4);
				break;
		case 3: PORTB&=~(1<<PINB1);
				PORTC&=~(1<<PINC1)&~(1<<PINC4);
				PORTB|=(1<<PINB0)|(1<<PINB2)|(1<<PINB3);
				PORTC|=(1<<PINC2)|(1<<PINC3);
				break;	
		case 4: PORTB&=~(1<<PINB2);
				PORTC&=~(1<<PINC1)&~(1<<PINC3)&~(1<<PINC4);
				PORTB|=(1<<PINB0)|(1<<PINB1)|(1<<PINB3);
				PORTC|=(1<<PINC2);
				break;	
		case 5: PORTB&=~(1<<PINB3);
				PORTC&=~(1<<PINC1)&~(1<<PINC4);
				PORTB|=(1<<PINB0)|(1<<PINB1)|(1<<PINB2);
				PORTC|=(1<<PINC2)|(1<<PINC3);
				break;
		case 6: PORTB&=~(1<<PINB3);
				PORTC&=~(1<<PINC1);
				PORTB|=(1<<PINB0)|(1<<PINB1)|(1<<PINB2);
				PORTC|=(1<<PINC2)|(1<<PINC3)|(1<<PINC4);
				break;
		case 7: PORTB&=~(1<<PINB0)&~(1<<PINB1);
				PORTC&=~(1<<PINC1)&~(1<<PINC3)&~(1<<PINC4);
				PORTB|=(1<<PINB2)|(1<<PINB3);
				PORTC|=(1<<PINC2);
				break;
		case 8: PORTC&=~(1<<PINC1);
				PORTB|=(1<<PINB0)|(1<<PINB1)|(1<<PINB2)|(1<<PINB3);
				PORTC|=(1<<PINC2)|(1<<PINC3)|(1<<PINC4);
				break;
		case 9: PORTC&=~(1<<PINC1)&~(1<<PINC4);
				PORTB|=(1<<PINB0)|(1<<PINB1)|(1<<PINB2)|(1<<PINB3);
				PORTC|=(1<<PINC2)|(1<<PINC3);
				break;
		default:PORTC&=~(1<<PINC2);
				PORTB&=~(1<<PINB3);
				PORTB|=(1<<PINB0)|(1<<PINB1)|(1<<PINB2);
				PORTC|=(1<<PINC1)|(1<<PINC3)|(1<<PINC4);
				break;
	}
	
	
}

ISR (INT0_vect)
{
	
	
	//int nr = memory_read(200);
	
	
	display_digit(digit_value);
	EEPROM_write(200,digit_value);
	digit_value++;
	
	
	
	if(digit_value>=10)
		digit_value=0;
}