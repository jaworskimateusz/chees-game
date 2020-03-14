#ifndef PAWN_H
#define PAWN_H

#include "piece.h"


class Pawn : public Piece {

public:
    Pawn();
    virtual vector<pair<int,int>> getPossiblePieceMoves(int x, int y) override;
};

#endif // PAWN_H
