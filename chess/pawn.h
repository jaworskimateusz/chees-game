#ifndef PAWN_H
#define PAWN_H

#include "piece.h"


class Pawn : public Piece {

public:
    virtual QVector<Position> getAllPieceMoves() override;
    virtual QVector<Position> getPossiblePieceMoves() override;
};

#endif // PAWN_H
