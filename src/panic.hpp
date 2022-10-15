#ifndef PANIC_HPP
#define PANIC_HPP
#include "display.hpp"


void static(* sw_reset) (void) = 0;

void reset_arduino() {
    #ifdef DEBUG
    Serial.println("Resetting...");
    #endif
    sw_reset();
}

void panic(String error) {
    print_lcd(error, "!!!Riavvia!!!");
    while(1);
}

#endif