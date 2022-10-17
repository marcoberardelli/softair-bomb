#include <Arduino.h>

#include <LowPower.h>
#include "timer.hpp"
#include "button.hpp"
#include "display.hpp"
#include "gamemode.hpp"
#include "game.hpp"
#include "interrupt.hpp"

#include "serial.hpp"


/**
 * Holy Bible of power saving: http://www.gammon.com.au/forum/?id=11497
*/
GameModeQueue gamemodes;

void setup() {
    
    init_serial(9600);

    init_lcd_display();
    init_segment_display();
    init_timer();
    

    enable_menu_btns();
    enable_keypad();
    gamemodes = GameModeQueue();
    print_lcd("Modalita", gamemodes.GetCurrentAsString());

    #ifdef DEBUG
    println("Finish setup");
    #endif
}

void loop() {
    PressedButton btn = read_button();
    if( btn == RED) {
        #ifdef DEBUG
        println("Pressed RED button");
        #endif
        gamemodes.Next();
        print_row_lcd(gamemodes.GetCurrentAsString(), 1);
    } else if (btn == BLUE) { // game is selected, need time then start

        #ifdef DEBUG
        println("Pressed BLUE button");
        #endif

        time_t time = {0,30}; //TODO: select timer
        switch (gamemodes.Current())
        {
        case BOMB:
            #ifdef DEBUG
            println("Stard Bomb game");
            #endif
            start_bomb_game(time);
            break;
       
        case DOMINATION:
            #ifdef DEBUG
            println("Started Domination game");
            #endif
            start_domination_game(time);
            break;
        case SIMPLE:
            #ifdef DEBUG
            println("Started Simple game");
            #endif
            start_simple_game(time);
            break;
         case AUDIO:
            #ifdef DEBUG
            println("Started audio mode");
            #endif
            start_audio_gamemode();
            break;
        default:
            break;
        }
    }
    clear_button_state();
    
    LowPower.idle(SLEEP_FOREVER, ADC_OFF, TIMER2_OFF, TIMER1_ON, TIMER0_OFF, 
                SPI_OFF, USART0_OFF, TWI_OFF);
}

