#ifndef TIMER_HPP
#define TIMER_HPP
#include "Arduino.h"

#define USE_TIMER_1 true
#define USE_TIMER_2 false //8bit timer
#define USE_TIMER_3 false
#define USE_TIMER_4 false
#define USE_TIMER_5 false

#define GAME_DURATION_SECOND 1
#define SEGMENT_BLINK_DURATION_MS 5000

typedef struct {
    uint8_t minutes;
    uint8_t seconds;
}time_t;

void init_timer();
int8_t start_game_timer(time_t time);
int8_t start_game_timer(uint8_t minutes, uint8_t seconds);
int8_t start_segment_timer();
void stop_timer();
time_t get_remaining_gametime();
bool did_game_tick();
void clear_game_tick();


#endif