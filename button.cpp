#include <Arduino.h>
#include "button.hpp"
#include <avr/interrupt.h>

/**
 * @brief 
 * Pinout: https://www.circuito.io/blog/arduino-uno-pinout/
 * https://thewanderingengineer.com/2014/08/11/arduino-pin-change-interrupts/
 * http://www.gammon.com.au/forum/?id=11488
 * 
 *  Pin Change Interrupt Request 0 (pins D8 to D13) (PCINT0_vect)
 *  Pin Change Interrupt Request 1 (pins A0 to A5)  (PCINT1_vect)
 *  Pin Change Interrupt Request 2 (pins D0 to D7)  (PCINT2_vect)
 * 
 */

#define LED_TEST 12
#define PREV_BTN 
#define NEXT_BTN

uint8_t next_btn = false;
uint8_t prev_btn = false;



void enable_menu_btns() {

    PCICR |= 0b00000001; // Enable port B
    PCMSK0 |= 0b11000000; // Enable PCINT6 and PCINT7 TODO: check what pins are digitalPinToInterrupt(), pin 20 e 21, idk if physical or not

}

ISR(PCINT0) {
    if(digitalRead())
    digitalWrite(LED_TEST, HIGH);
}