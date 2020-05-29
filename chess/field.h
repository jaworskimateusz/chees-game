#ifndef FIELD_H
#define FIELD_H
#include "piece.h"

/**
 *  @file   field.h
 *  @brief  Class which represents single field where piece is set.
 *  @author Mateusz Jaworski
 *  @date   14-05-2020
 ***********************************************/
class Field {

private:
    Piece *piece;
public:
    /**
     *  @brief No-args empty constructor
     ***********************************************/
    Field();
    /**
     *  @brief Empty destructor
     ***********************************************/
    ~Field();
    /**
     *  @brief Sets specific piece on a field
     *  @param *piece pointer to piece
     *  @param color color of the piece
     *  @param iconName path to icon
     *  @return Void
     ***********************************************/
    void setPiece(Piece *piece, Color color, string iconName);
    /**
     *  @brief Get specific pointer to piece
     *  @return Returns specific pointer to piece
     ***********************************************/
    Piece* getPiece();
    /**
     *  @param x X-coordinate in field table
     *  @param y Y-coordinate in field table
     *  @return Returns vector of points where piece can move
     ***********************************************/
    vector<pair<int,int>> getMoves(int x, int y);
};

#endif // FIELD_H
