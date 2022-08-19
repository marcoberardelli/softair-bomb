#ifndef COUNTDOWN_HPP
#define COUNTDOWN_HPP
#include "Arduino.h"

#define USE_TIMER_1 true
#define USE_TIMER_2 false //8bit timer
#define USE_TIMER_3 false
#define USE_TIMER_4 false
#define USE_TIMER_5 false

#define CLOCK_TIMER_MS 1000L
#define GAME_DURATION_1 CLOCK_TIMER_MS*60
#define GAME_DURATION_5 GAME_DURATION_1*5
#define GAME_DURATION_10 GAME_DURATION_1*10

void stop_countdown();
int8_t start_countdown(uint16_t duration);
void init_countdown();


#endif