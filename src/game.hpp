#ifndef GAME_HPP
#define GAME_HPP
#include "countdown.hpp"


#define N_GAMEMODES 3
#define RED_TEAM    1
#define BLUE_TEAM   2

enum GameMode {
    SIMPLE,
    BOMB,
    DOMINATION
};

class GameModeQueue {

private:
    GameMode gamemodes[N_GAMEMODES];
    int8_t index;
    uint8_t size;

public:
    GameModeQueue();
    bool Add(GameMode mode);
    GameMode Next();
    GameMode Previous();
    GameMode Current();
    String GetCurrentAsString();
};

void start_simple_game(time_t duration);
void start_domination_game(time_t duration);
void start_bomb_game(time_t duration);


#endif