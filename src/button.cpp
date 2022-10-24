#include <Arduino.h>
#include <avr/interrupt.h>
#include "button.hpp"
/**
 * @brief 
 * Pinout: https://www.circuito.io/blog/arduino-uno-pinout/
 * https://thewanderingengineer.com/2014/08/11/arduino-pin-change-interrupts/
 * http://www.gammon.com.au/forum/?id=11488
 * 
 *  Pin Change Interrupt Request 0 (pins D8 to D13) (PCINT0_vect)
 *  Pin Change Interrupt Request 1 (pins A0 to A5)  (PCINT1_vect)
 *  Pin Change Interrupt Request 2 (pins D0 to D7)  (PCINT2_vect)
 *  https://www.teachmemicro.com/arduino-pins-manipulation/ internal pinout
 */

#define DEBOUNCE_TIME_MS 50UL

volatile unsigned long last_pressed_time = 0;
volatile static uint8_t cont = 0;

volatile static PressedButton pressed_button = NONE;

void init_RB_btns(bool enable) {
  #ifdef DEBUG
  Serial.println("Enabling RB");
  #endif

  pinMode(BLUE_BTN_PIN, INPUT_PULLUP);
  pinMode(RED_BTN_PIN, INPUT_PULLUP);

  if(enable) {
    enable_RB_btns();
  }
  pressed_button = NONE;

  #ifdef DEBUG
  Serial.println("Enabled RB");
  #endif
}

void enable_RB_btns() {
  attachInterrupt(0, blue_btn_INT, FALLING);
  attachInterrupt(1, red_btn_INT, FALLING);
  #ifdef DEBUG
  Serial.println("Started RB");
  #endif
}

void disable_RB_btns() {
  detachInterrupt(0);
  detachInterrupt(1);
}


void red_btn_INT() {
  pressed_button = RED;
  for(int i = 0; i < 10; i++) {
    delayMicroseconds(5000);
  }
}

void blue_btn_INT() {
  pressed_button = BLUE;
  for(int i = 0; i < 10; i++) {
    delayMicroseconds(5000);
  }
}

PressedButton read_button() {
    return pressed_button;
}

void clear_button_state() {
  pressed_button = NONE;
}