#include "game.h"
#include "pawn.h"

Game::Game() {

    for(int i = 0; i < 8; i++ ) {
        for(int j = 0; j < 8; j++) {
            fields[i][j].setPiece(new class Pawn, WHITE, PAWN, ":/Resources/pawn.png");
        }
    }
}

Field Game::getField(int x, int y) {
    return fields[x][y];
}
