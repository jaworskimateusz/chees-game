#ifndef PAWN_H
#define PAWN_H

#include "piece.h"

/**
 *  @file   pawn.h
 *  @brief  Child class which inherits behaviour for piece
 *  @author Mateusz Jaworski
 *  @date   14-05-2020
 ***********************************************/
class Pawn : public Piece {

public:
    /**
     *  @brief Method calculates possible moves for pawn
     *  @param x X-coordinate in field table
     *  @param y Y-coordinate in field table
     *  @return Returns vector of points where piece (pawn) can move
     ***********************************************/
    virtual vector<pair<int,int>> getPossiblePieceMoves(int x, int y) override;
};

#endif // PAWN_H
