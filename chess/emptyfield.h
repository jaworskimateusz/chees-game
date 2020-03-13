#ifndef EMPTYFIELD_H
#define EMPTYFIELD_H

#include "piece.h"

class EmptyField : public Piece {

public:
    EmptyField();
    virtual vector<pair<int,int>> getAllPieceMoves() override;
    virtual vector<pair<int,int>> getPossiblePieceMoves() override;
};

#endif // EMPTYFIELD_H
