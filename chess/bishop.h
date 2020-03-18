#ifndef BISHOP_H
#define BISHOP_H

#include <piece.h>

class Bishop : public Piece {

public:
    virtual vector<pair<int,int>> getPossiblePieceMoves(int x, int y) override;
};

#endif // BISHOP_H
