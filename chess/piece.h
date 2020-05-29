#ifndef PIECE_H
#define PIECE_H

#include "Color.h"
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

/**
 *  @file   piece.h
 *  @brief  Parent class which describes behaviour for child pieces
 *  @author Mateusz Jaworski
 *  @date   14-05-2020
 ***********************************************/
class Piece {
private:
    Color color;
    string iconName;
protected:
    vector<pair<int,int>> moves;
public:

    /**
     *  @brief No-args constructor for Piece class
     ***********************************************/
    Piece();
    /**
     *  @brief Destructor for Piece class
     ***********************************************/
    ~Piece();
    /**
     *  @brief Args constructor for piece class.
     *  @param color color of the piece
     *  @param iconName path to icon
     ***********************************************/
    Piece(Color color, string iconName);
    /**
     *  @return Returns color of the piece
     ***********************************************/
    Color getColor();
    /**
     *  @return Returns path co icon
     ***********************************************/
    string getIconName();
    /**
     *  @brief Method set piece color
     *  @return void
     ***********************************************/
    void setColor(Color color);
    /**
     *  @brief Method set piece icon name
     *  @return void
     ***********************************************/
    void setIconName(string iconName);
    /**
     *  @brief Method calculates possible moves for specific piece
     *  @param x X-coordinate in field table
     *  @param y Y-coordinate in field table
     *  @return Returns vector of points where piece can move
     ***********************************************/
    virtual vector<pair<int,int>> getPossiblePieceMoves(int x, int y);
    /**
     *  @brief Method calculates if piece is opponent
     *  @param positionTo pair of X and Y coordinate in field table
     *  @return Returns true if on specific piece position in field table opponent is set
     ***********************************************/
    bool isOpponent(pair<int,int> positionTo);
    /**
     *  @brief Method calculates if field is empty
     *  @param positionTo pair of X and Y coordinate in field table
     *  @return Returns true if on specific piece position in field table piece is emptyField
     ***********************************************/
    bool isEmpty(pair<int,int> positionTo);

};

#endif // PIECE_H
