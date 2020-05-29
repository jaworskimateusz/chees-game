#ifndef BOARD_H
#define BOARD_H

#include "field.h"
#include "pawn.h"
#include "emptyfield.h"
#include "rook.h"
#include "bishop.h"
#include "knight.h"
#include "queen.h"
#include "king.h"
#include "Color.h"

/**
 *  @file   board.h
 *  @brief  Class which represents chess board.
 *  @author Mateusz Jaworski
 *  @date   14-05-2020
 ***********************************************/
class Board {
private:
    Field ***fields;
public:

    /**
     *  @brief No-args constructor for Board class. Here is created table of fields. Specific pieces are set in fields
     ***********************************************/
    Board();
    /**
     *  @brief Destructor for Board class. All initialized fields in table are deleted.
     ***********************************************/
    ~Board();
    /**
     *  @brief Swapes two pieces, if piece is matted field is set to empty
     *  @param previousPosition X,Y-coordinates of the previous piece position
     *  @param newPosition X,Y-coordinates of the new piece position
     *  @return Void
     ***********************************************/
    void swapPiece(pair<int,int> previousPosition, pair<int,int> newPosition);
    /**
     *  @brief Get specific field
     *  @param x X-coordinate in field table
     *  @param y Y-coordinate in field table
     *  @return Returns specific field
     ***********************************************/
    Field* getField(int x, int y) ;
    /**
     *  @brief Checks how many kings are in fields
     *  @return Returns true if kings < 2
     ***********************************************/
    bool isKingMatted();
};

#endif // BOARD_H
