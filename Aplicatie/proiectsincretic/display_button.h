/*
 * _7_segmente.h
 *
 * Created: 01-Dec-16 3:31:13 PM
 *  Author: user
 */ 
#ifndef DISPLAY_BUTTON_H
#define DISPLAY_BUTTON_H

#include <avr/io.h>
#include <avr/eeprom.h>
#include<avr/interrupt.h>

void display_init();
void display_digit(int digit);
void pushbutton_init();



#endif