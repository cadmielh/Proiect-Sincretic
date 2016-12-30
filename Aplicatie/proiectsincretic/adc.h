/*
 * adc.h
 *
 * Created: 29-Nov-16 11:29:36 AM
 *  Author: user
 */ 
#ifndef ADC_H
#define ADC_H

#include <avr/interrupt.h>
#include <avr/io.h>
#include <math.h>
#include "pwm.h"
#include "serial.h"


void adc_init();
float temperatura;

#endif