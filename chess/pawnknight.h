#ifndef PAWNKNIGHT_H
#define PAWNKNIGHT_H
#include "piece.h"

class PawnKnight : public Piece
{
public:
    PawnKnight();
    virtual vector<pair<int,int>> getPossiblePieceMoves(int x, int y) override;
};

#endif // PAWNKNIGHT_H
