#include <Arduino.h>
#include <LowPower.h>

#include "game.hpp"
#include "countdown.hpp"
#include "display.hpp"

#define PSW_LENGHT 6
#define SIZE 3

GameModeQueue::GameModeQueue() {
    gamemodes[0] = SIMPLE;
    gamemodes[1] = BOMB;
    gamemodes[2] = DOMINATION;
    index = 0;
}

GameMode GameModeQueue::Next() {
    index++;
    index = index % SIZE;
    return gamemodes[index];
}

GameMode GameModeQueue::Previous() {
    index--;
    if (index < 0) {
        index = SIZE-1;
    }
    return gamemodes[index];
}

GameMode GameModeQueue::Current() {
    return gamemodes[index];
}

String GameModeQueue::GetCurrentAsString() {
    switch (gamemodes[index])
    {
    case SIMPLE:
        return "Semplice";
    case BOMB:
        return "Bomba";
    case DOMINATION:
        return "Dominio";
    default:
        break;
    }
    return "";
}

void _end_game(GameMode gamemode, int winner) {
    
    switch(gamemode){
        case SIMPLE:
            break;
        case BOMB:
            break;
        case DOMINATION:
            break;
        default:
            break;
    }
}

String _read_password() {
    String psw;
    //TODO read password
    return psw;
}

void start_simple_game(time_t duration){
    if (start_game_timer(duration) < 0) {
        print_lcd("Error timer", "-Duration");
        return;
    }

    while(true) {
        if(did_game_tick()) {
            time_t game_time = get_remaining_gametime();
            print_time_remaining(game_time);
            if (game_time.minutes == 0 && game_time.seconds == 0) {
                #ifdef DEBUG
                Serial.println("End Simple game");
                #endif
                stop_timer();
                _end_game(SIMPLE, 0);
                return;
            }
            clear_game_tick();
        }
        // Enter power down state with ADC and BOD module disabled.
        // Wake up when wake up pin is low.
        LowPower.idle(SLEEP_FOREVER, ADC_OFF, TIMER2_OFF, TIMER1_ON, TIMER0_OFF, 
                SPI_OFF, USART0_OFF, TWI_OFF);
    }
}

void start_domination_game(time_t duration){

}

void start_bomb_game(time_t duration) {

    //LCD.print(Select a password)

    String password = _read_password();

    if (start_game_timer(duration) < 0) {
        print_lcd("Error timer", "-Duration");
        return;
    }

    while(true) {
        if(did_game_tick()) {
            time_t game_time = get_remaining_gametime();
            print_time_remaining(game_time);
            if (game_time.minutes == 0 && game_time.seconds == 0) {
                #ifdef DEBUG
                Serial.println("End Bomb game");
                #endif
                stop_timer();
                _end_game(BOMB, BLUE_TEAM);
                return;
            }
            clear_game_tick();
        }

        // check keypad

        // Enter power down state with ADC and BOD module disabled.
        // Wake up when wake up pin is low.
        LowPower.idle(SLEEP_FOREVER, ADC_OFF, TIMER2_OFF, TIMER1_ON, TIMER0_OFF, 
                SPI_OFF, USART0_OFF, TWI_OFF);
    }
}