#ifndef GAME_H
#define GAME_H

#include "field.h"

class Game {

    Field fields[8][8];

public:
    Game();
    ~Game();
    Field getField(int x, int y);

};

#endif // GAME_H
