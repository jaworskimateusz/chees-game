#ifndef KNIGHT_H
#define KNIGHT_H

#include "piece.h"

class Knight : public Piece{

public:
    virtual vector<pair<int,int>> getPossiblePieceMoves(int x, int y) override;
};

#endif // KNIGHT_H
