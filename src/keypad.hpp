#ifndef KEYPAD_HPP
#define KEYPAD_HPP
#define EI_NOTPORTB
#define EI_NOTPINCHANGE 

#include "I2CKeyPad.h"

#define KEYPAD_INT_PIN 7
#define KEYPAD_ADDRESS 0x20


extern volatile bool has_key;
extern I2CKeyPad keyPad;

void read_key_INT();
bool did_keypad_read();
char read_key();

#endif