#include "countdown.hpp"
#include <TimerInterrupt.h>
#include "game.hpp"

volatile uint16_t game_time;

void clock_handler(uint16_t game_duration) {
    // TODO: Update time screen
    game_time++;
    if(game_time > game_duration) {
        end_game();
    }
}

void stop_countdown() {
    ITimer1.stopTimer();
    ITimer1.detachInterrupt();
}


int8_t start_countdown(uint16_t duration) {
    /**
     * choose if using wdt or timer
     * https://circuitdigest.com/microcontroller-projects/arduino-sleep-modes-and-how-to-use-them-to-reduce-power-consumption
     * 
     * WDT Library: https://github.com/nadavmatalon/WatchDog
     * LowPower Library: https://github.com/rocketscream/Low-Power
     * 
     * Holy Bible of power saving: http://www.gammon.com.au/forum/?id=11497
     * 
     */
    //TODO: choose if using wdt or timer
    game_time = 0;
    if(!ITimer1.attachInterruptInterval(duration, clock_handler, (uint16_t) &duration)) {
        return -1;
    }
    return 0;
}

void init_countdown() {
    ITimer1.init();
}