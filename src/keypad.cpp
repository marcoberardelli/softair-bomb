#include <Arduino.h>
#include "Wire.h"
#include "halt.hpp"
#include "keypad.hpp"


// maybe need 4.7kresistor for i2c (probably lcd already has it)
I2CKeyPad keyPad(KEYPAD_ADDRESS);
char keys[] = "123A456B789C*0#DNF";  // N = NoKey, F = Fail (e.g. >1 keys pressed)
volatile bool has_key;

void enable_keypad() {
    Wire.begin(); // TODO: check if useless
    if (keyPad.begin() == false)
    {
        panic("ERR KEYPAD INIT");
    }
    Wire.setClock(100000); //TODO: check if useless

    pinMode(KEYPAD_INT_PIN, INPUT_PULLUP);
    PCICR |= (1 << PCIE2); // Enable port INT[23:16]
    PCMSK2 |= (1 << PCINT23); // Enable PCINT23 (D7)

    has_key = false;
}

bool did_keypad_read() {
    return has_key;
}

char read_key() {
    uint8_t index = keyPad.getKey();
    return keys[index];
}

ISR(PCINT2_vect) {
    has_key = true;
}