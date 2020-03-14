#ifndef QUEEN_H
#define QUEEN_H

#include "piece.h"

class Queen : public Piece{
public:
    Queen();
    virtual vector<pair<int,int>> getPossiblePieceMoves(int x, int y) override;
};

#endif // QUEEN_H
