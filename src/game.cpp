#include <Arduino.h>
#include <LowPower.h>
#include <AltSoftSerial.h>
#include "game.hpp"
#include "gamemode.hpp"
#include "timer.hpp"
#include "display.hpp"
#include "button.hpp"
#include "keypad.hpp"
#include "serial.hpp"

#define PSW_LENGHT 6


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

void _read_password(char *password) {
    #ifdef DEBUG
    println("Reading password");
    #endif

    uint8_t len = 0;
    while(len < PSW_LENGHT) {
        
        LowPower.idle(SLEEP_FOREVER, ADC_OFF, TIMER2_OFF, TIMER1_ON, TIMER0_OFF, 
                SPI_OFF, USART0_OFF, TWI_OFF);
        if(did_keypad_read()) {
            password[len] = read_key();
        }
    }
}

void start_simple_game(time_t duration){
    if (start_game_timer(duration) < 0) {
        print_lcd("Error timer", "-Duration");
        return;
    }

    lcd_off();
    while(true) {
        if(did_game_tick()) {
            time_t game_time = get_remaining_gametime();
            print_time_remaining(game_time);
            if (game_time.minutes == 0 && game_time.seconds == 0) {
                #ifdef DEBUG
                println("End Simple game");
                #endif
                stop_timer();
                _end_game(SIMPLE, 0);
                return;
            }
            clear_game_tick();
        }

        LowPower.idle(SLEEP_FOREVER, ADC_OFF, TIMER2_OFF, TIMER1_ON, TIMER0_OFF, 
                SPI_OFF, USART0_OFF, TWI_OFF);
    }
    lcd_on();
}

void start_domination_game(time_t duration){
    if (start_game_timer(duration) < 0) {
        print_lcd("Error timer", "-Duration");
        return;
    }

    uint8_t team = BLUE_TEAM;

    while(true) {
        if(did_game_tick()) {
            time_t game_time = get_remaining_gametime();
            print_time_remaining(game_time);
            if (game_time.minutes == 0 && game_time.seconds == 0) {
                #ifdef DEBUG
                println("End Domination game");
                #endif
                stop_timer();
                _end_game(BOMB, BLUE_TEAM);
                return;
            }
            clear_game_tick();
        }

        PressedButton btn = read_button();
        if(btn == RED && team == BLUE_TEAM) {
            #ifdef DEBUG
            println("Red team hold");
            #endif
            team = RED_TEAM;
            //play audio
        } else if (btn == BLUE && team == RED_TEAM) {
            #ifdef DEBUG
            println("Blue team hold");
            #endif
            team = BLUE_TEAM;
            //play audio
        }

        LowPower.idle(SLEEP_FOREVER, ADC_OFF, TIMER2_OFF, TIMER1_ON, TIMER0_OFF, 
                SPI_OFF, USART0_OFF, TWI_OFF);
    }
    lcd_on();
}

void start_bomb_game(time_t duration) {

    //LCD.print(Select a password)
    char password[PSW_LENGHT];
    _read_password(password);

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
                println("End Bomb game");
                #endif
                stop_timer();
                _end_game(BOMB, BLUE_TEAM);
                return;
            }
            clear_game_tick();
        }

        // check keypad

        LowPower.idle(SLEEP_FOREVER, ADC_OFF, TIMER2_OFF, TIMER1_ON, TIMER0_OFF, 
                SPI_OFF, USART0_OFF, TWI_OFF);
    }
    lcd_on();
}


void start_audio_gamemode() {

}