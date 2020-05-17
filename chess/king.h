#ifndef KING_H
#define KING_H

#include "piece.h"

/**
 *  @file   king.h
 *  @brief  Child class which inherits behaviour for piece
 *  @author Mateusz Jaworski
 *  @date   14-05-2020
 ***********************************************/
class King : public Piece {

public:
    /**
     *  @brief Method calculates possible moves for king
     *  @param x X-coordinate in field table
     *  @param y Y-coordinate in field table
     *  @return Returns vector of points where piece (king) can move
     ***********************************************/
    virtual vector<pair<int,int>> getPossiblePieceMoves(int x, int y) override;
};

#endif // KING_H
