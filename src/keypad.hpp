#ifndef KEYPAD_HPP
#define KEYPAD_HPP
#include "timer.hpp"

#define EI_NOTEXTERNAL

void enable_keypad();
bool did_keypad_read();
uint8_t read_key();

#endif