#include "gamemode.hpp"

GameModeQueue::GameModeQueue() {
    gamemodes[0] = SIMPLE;
    gamemodes[1] = BOMB;
    gamemodes[2] = DOMINATION;
    gamemodes[3] = AUDIO;
    index = 0;
}

GameMode GameModeQueue::Next() {
    index++;
    index = index % N_GAMEMODES;
    return gamemodes[index];
}

GameMode GameModeQueue::Previous() {
    index--;
    if (index < 0) {
        index = N_GAMEMODES-1;
    }
    return gamemodes[index];
}

GameMode GameModeQueue::Current() {
    return gamemodes[index];
}

String GameModeQueue::GetCurrentAsString() {
    switch (gamemodes[index])
    {
    case SIMPLE:
        return "Semplice";
    case BOMB:
        return "Bomba";
    case DOMINATION:
        return "Dominio";
    case AUDIO:
        return "Audio";
    default:
        break;
    }
    return "Uknown";
}