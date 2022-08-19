#include <LowPower.h>
#include "countdown.hpp"
#include "display.hpp"
#include "game.hpp"

#define WAKE_UP_PIN 2

void setup() {
    
    Serial.begin(9600);

    init_display();
    init_countdown();

    pinMode(WAKE_UP_PIN, INPUT); // enable interrupt for wake up
    enable_menu_btns();

}

void loop() {


}
