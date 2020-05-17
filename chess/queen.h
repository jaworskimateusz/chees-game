#ifndef QUEEN_H
#define QUEEN_H

#include "piece.h"

/**
 *  @file   queen.h
 *  @brief  Child class which inherits behaviour for piece
 *  @author Mateusz Jaworski
 *  @date   14-05-2020
 ***********************************************/
class Queen : public Piece{
public:
    /**
     *  @brief Method calculates possible moves for queen
     *  @param x X-coordinate in field table
     *  @param y Y-coordinate in field table
     *  @return Returns vector of points where piece (queen) can move
     ***********************************************/
    virtual vector<pair<int,int>> getPossiblePieceMoves(int x, int y) override;
};

#endif // QUEEN_H
