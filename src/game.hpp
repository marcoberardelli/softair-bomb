#ifndef GAME_HPP
#define GAME_HPP
#include "timer.hpp"

#define RED_TEAM    1
#define BLUE_TEAM   2


void start_simple_game(time_t duration);
void start_domination_game(time_t duration);
void start_bomb_game(time_t duration);
void start_audio_gamemode();

#endif