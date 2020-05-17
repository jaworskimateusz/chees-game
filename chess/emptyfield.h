#ifndef EMPTYFIELD_H
#define EMPTYFIELD_H

#include "piece.h"

/**
 *  @file   emptyfield.h
 *  @brief  Child class which represents empty field without piece.
 *  @author Mateusz Jaworski
 *  @date   14-05-2020
 ***********************************************/
class EmptyField : public Piece {

public:
    virtual vector<pair<int,int>> getPossiblePieceMoves(int x, int y) override;
};

#endif // EMPTYFIELD_H
