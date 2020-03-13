#ifndef KING_H
#define KING_H

#include "piece.h"

class King : public Piece {

public:
    King();
    virtual vector<pair<int,int>> getAllPieceMoves() override;
    virtual vector<pair<int,int>> getPossiblePieceMoves() override;
};

#endif // KING_H
