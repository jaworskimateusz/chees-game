#ifndef KNIGHT_H
#define KNIGHT_H

#include "piece.h"

class Knight : public Piece{

public:
    Knight();
    virtual vector<pair<int,int>> getAllPieceMoves() override;
    virtual vector<pair<int,int>> getPossiblePieceMoves() override;
};

#endif // KNIGHT_H
