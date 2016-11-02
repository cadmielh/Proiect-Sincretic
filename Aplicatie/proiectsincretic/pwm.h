/*
 * pwm.h
 *
 * Created: 01-Nov-16 10:46:39 AM
 *  Author: user
 */ 
#ifndef PWM_H_
#define PWM_H_

#define F_CPU 16000000

#include <avr/io.h>
#include <util/delay.h>


void PWM_init();
void PWM_fadein_fadeout();

int i;

#endif