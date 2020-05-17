#ifndef KNIGHT_H
#define KNIGHT_H

#include "piece.h"

/**
 *  @file   knight.h
 *  @brief  Child class which inherits behaviour for piece
 *  @author Mateusz Jaworski
 *  @date   14-05-2020
 ***********************************************/
class Knight : public Piece{

public:
    /**
     *  @brief Method calculates possible moves for knight
     *  @param x X-coordinate in field table
     *  @param y Y-coordinate in field table
     *  @return Returns vector of points where piece (knight) can move
     ***********************************************/
    virtual vector<pair<int,int>> getPossiblePieceMoves(int x, int y) override;
};

#endif // KNIGHT_H
