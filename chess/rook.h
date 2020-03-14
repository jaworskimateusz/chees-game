#ifndef ROOK_H
#define ROOK_H

#include "piece.h"

class Rook : public Piece {

public:
    Rook();
    virtual vector<pair<int,int>> getPossiblePieceMoves(int x, int y) override;
};

#endif // ROOK_H
