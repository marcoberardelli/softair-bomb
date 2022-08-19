#define NONE_GAME       0b000
#define BOMB_GAME       0b001
#define SIMPLE_GAME     0b010
#define DOMINATION_GAME 0b011


void start_simple_game(uint16_t duration);
void start_domination_game(uint16_t duration);
void start_bomb_game(uint16_t duration);
void end_game();