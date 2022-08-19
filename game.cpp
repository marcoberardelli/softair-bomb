#include <Arduino.h>
#include "countdown.hpp"
#include "display.hpp"
#include "game.hpp"

#define PSW_LENGHT 6

uint8_t gamemode;

String _read_password() {
    String psw;
    //TODO read password

    #ifdef DEBUG
    Serial.Println("Password is %s", psw.c_str());
    #endif
    return psw;
}

void start_simple_game(uint16_t duration){

}

void start_domination_game(uint16_t duration){

}

void start_bomb_game(uint16_t duration) {

    //LCD.print(Select a password)

    String password = _read_password();

    #ifdef DEBUG
    Serial.Println("Started countdown");
    #endif
    if (start_countdown(duration) < 0) {
        lcd_print("Error starting timer");
    }
    
    gamemode = BOMB_GAME;

    while(true) {
        //sleep
        //read keypad
    }
}


void end_game() {
    stop_countdown();
    switch(gamemode){
        case BOMB_GAME:
            break;
        case DOMINATION_GAME:
            break;
        case SIMPLE_GAME:
            break;
        default:
            break;
    }
}