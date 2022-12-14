#include <Arduino.h>

#include <LowPower.h>
#include "timer.hpp"
#include "button.hpp"
#include "display.hpp"
#include "gamemode.hpp"
#include "game.hpp"
#include "keypad.hpp"
/**
 * Holy Bible of power saving: http://www.gammon.com.au/forum/?id=11497
*/
GameModeQueue gamemodes;

void setup() {
    
    Serial.begin(9600);

    init_lcd_display();
    init_segment_display();
    init_timer();
    

    init_RB_btns(true);
    delay(500);
    //enable_keypad();
    gamemodes = GameModeQueue();
    #ifdef DEBUG
    Serial.println("create queue");
    #endif
    print_lcd("Modalita", gamemodes.GetCurrentAsString());
    #ifdef DEBUG
    Serial.println(gamemodes.GetCurrentAsString());
    #endif

    #ifdef DEBUG
    Serial.println("Finish setup");
    #endif
}

void loop() {
    PressedButton btn = read_button();
    if( btn == RED) {
        #ifdef DEBUG
        Serial.println("Pressed RED button");
        #endif
        gamemodes.Next();
        print_row_lcd(gamemodes.GetCurrentAsString(), 1);
    } else if (btn == BLUE) { // game is selected, need time then start

        #ifdef DEBUG
        Serial.println("Pressed BLUE button");
        #endif

        time_t time = {0,30}; //TODO: select timer
        switch (gamemodes.Current())
        {
        case BOMB:
            #ifdef DEBUG
            Serial.println("Stard Bomb game");
            #endif
            start_bomb_game(time);
            break;
       
        case DOMINATION:
            #ifdef DEBUG
            Serial.println("Started Domination game");
            #endif
            start_domination_game(time);
            break;
        case SIMPLE:
            #ifdef DEBUG
            Serial.println("Started Simple game");
            #endif
            start_simple_game(time);
            break;
         case AUDIO:
            #ifdef DEBUG
            Serial.println("Started audio mode");
            #endif
            start_audio_gamemode();
            break;
        default:
            break;
        }
    }
    clear_button_state();
    #ifdef DEBUG
    Serial.println("Enter sleep...");
    #endif
    
    LowPower.idle(SLEEP_FOREVER, ADC_OFF, TIMER2_OFF, TIMER1_ON, TIMER0_OFF, 
                SPI_OFF, USART0_OFF, TWI_OFF);
}

