#ifndef GAME_H
#define GAME_H

#include "field.h"
#include "pawn.h"
#include "emptyfield.h"
#include "rook.h"
#include "bishop.h"
#include "knight.h"
#include "queen.h"
#include "king.h"
#include "PieceType.h"
#include "Color.h"

class Game {

    Color currentMove;
    vector<pair<int,int>> pieceMoves;
public:
    Field ***fields;

public:
    Game();
    ~Game();
    Field *getField(int x, int y);
    Color getCurrentMove();
    void setCurrentMove();
    void swapPiece(pair<int,int> previousPosition, pair<int,int> newPosition);
    vector<pair<int,int>> getPieceMoves();
};

#endif // GAME_H
