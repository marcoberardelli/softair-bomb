#ifndef GAME_MODE_HPP
#define GAME_MODE_HPP
#include <Arduino.h>

#define N_GAMEMODES 4

enum GameMode {
    SIMPLE,
    BOMB,
    DOMINATION,
    AUDIO
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


#endif