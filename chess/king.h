#ifndef KING_H
#define KING_H

#include "piece.h"

class King : public Piece {

public:
    virtual vector<pair<int,int>> getPossiblePieceMoves(int x, int y) override;
};

#endif // KING_H
