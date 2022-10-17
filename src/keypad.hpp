#ifndef KEYPAD_HPP
#define KEYPAD_HPP

#include "I2CKeyPad.h"

#define KEYPAD_INT_PIN 7
#define KEYPAD_ADDRESS 0x20

void enable_keypad();
void read_key_INT();
bool did_keypad_read();
char read_key();

#endif