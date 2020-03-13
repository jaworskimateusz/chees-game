#ifndef BISHOP_H
#define BISHOP_H

#include <piece.h>

class Bishop : public Piece {

public:
    Bishop();
    virtual vector<pair<int,int>> getAllPieceMoves() override;
    virtual vector<pair<int,int>> getPossiblePieceMoves() override;
};

#endif // BISHOP_H
