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
#include<avr/interrupt.h>


void PWM_init();
void timer2_init(); 

#endif