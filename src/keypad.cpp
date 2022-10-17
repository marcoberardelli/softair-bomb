#include <Arduino.h>
#include "Wire.h"
#include "halt.hpp"
#include "keypad.hpp"


// maybe need 4.7kresistor for i2c (probably lcd already has it)
I2CKeyPad keyPad(KEYPAD_ADDRESS);
volatile bool has_key;
char keys[] = "123A456B789C*0#DNF";  // N = NoKey, F = Fail (e.g. >1 keys pressed)

void enable_keypad() {
    Wire.begin(); // TODO: check if useless
    pinMode(KEYPAD_INT_PIN, INPUT_PULLUP);
    //enableInterrupt(KEYPAD_INT_PIN, read_key_INT, FALLING);
    //attachInterrupt(KEYPAD_INT_PIN, _read_key_INT, FALLING);
    has_key = false;

    Wire.begin();
    if (keyPad.begin() == false)
    {
        panic("ERR KEYPAD INIT");
    }
    Wire.setClock(100000); //TODO: check if useless
}

void read_key_INT() {
    has_key = true;
}

bool did_keypad_read() {
    return has_key;
}

char read_key() {
    uint8_t index = keyPad.getKey();
    return keys[index];
}