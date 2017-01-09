/*
 * eeprom.h
 *
 * Created: 03-Jan-17 9:27:11 PM
 *  Author: user
 */ 
 #include <avr/io.h>
 #include <avr/interrupt.h>

 void EEPROM_write(unsigned int uiAddress, unsigned char ucData);
 unsigned char EEPROM_read(unsigned int uiAddress);