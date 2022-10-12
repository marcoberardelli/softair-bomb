#include <Arduino.h>
#include "countdown.hpp"

time_t select_time(){
    time_t time = {5,30};
    #if DEBUG
    time = time_t{5,30};
    #endif
    return time;
}