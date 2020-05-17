#ifndef BISHOP_H
#define BISHOP_H

#include <piece.h>

/**
 *  @file   bishop.h
 *  @brief  Child class which inherits behaviour for piece
 *  @author Mateusz Jaworski
 *  @date   14-05-2020
 ***********************************************/
class Bishop : public Piece {

public:
    /**
     *  @brief Method calculates possible moves for bishop
     *  @param x X-coordinate in field table
     *  @param y Y-coordinate in field table
     *  @return Returns vector of points where piece (bishop) can move
     ***********************************************/
    virtual vector<pair<int,int>> getPossiblePieceMoves(int x, int y) override;
};

#endif // BISHOP_H
