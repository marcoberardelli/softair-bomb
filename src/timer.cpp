#include "timer.hpp"
#include <TimerInterrupt.h>
#include "game.hpp"
#include "display.hpp"
#include "halt.hpp"

volatile time_t game_time;
volatile static bool timer_tick;

void clock_handler() {
    if(game_time.seconds == 0) {
        game_time.seconds = 60;
        game_time.minutes--;
    }
    game_time.seconds--;
    timer_tick = true;
}

void blink_segment() {
    segment_off();
    //TODO: check if i can modify the timer when is running
    //ITimer1.setCount(20); 
}

void init_timer() {
    ITimer1.init();
}

void start_game_timer(time_t time) {
    start_game_timer(time.minutes, time.seconds);
}

void start_game_timer(uint8_t minutes, uint8_t seconds) {
    timer_tick = false;
    game_time.seconds = seconds;
    game_time.minutes = minutes;
    if(!ITimer1.attachInterruptInterval(GAME_DURATION_SECOND*1000, clock_handler)) {
        panic("ERR TIMER START");
    }
    #ifdef DEBUG
    Serial.println("Started timer");
    #endif
}

void start_segment_timer() {
    if(!ITimer1.attachInterruptInterval(SEGMENT_BLINK_DURATION_MS, clock_handler)) {
        panic("ERR TIMER SEGM");
    }
    #ifdef DEBUG
    Serial.println("Started segment timer");
    #endif
}

void stop_timer() {
    ITimer1.stopTimer();
    #ifdef DEBUG
    Serial.println("Stopped timer");
    #endif
}


time_t get_remaining_gametime(){
    return time_t {game_time.minutes, game_time.seconds};
}

void clear_game_tick(){
    timer_tick = false;
}

bool did_game_tick() {
    return timer_tick;
}