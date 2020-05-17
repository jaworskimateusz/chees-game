#ifndef GAME_H
#define GAME_H

#include "field.h"
#include "pawn.h"
#include "emptyfield.h"
#include "rook.h"
#include "bishop.h"
#include "knight.h"
#include "queen.h"
#include "king.h"
#include "PieceType.h"
#include "Color.h"

/**
 *  @file   game.h
 *  @brief  Class which represents single game. At first game must be created then other behaviours.
 *  @author Mateusz Jaworski
 *  @date   14-05-2020
 ***********************************************/
class Game {

private:
    Color currentMove;
    vector<pair<int,int>> pieceMoves;
    bool isGameOver = false;
public:
    Field ***fields;
public:
    /**
     *  @brief No-args constructor for Game class. Here is created table of fields. Specific pieces are set in fields
     ***********************************************/
    Game();
    /**
     *  @brief Destructor for Game class. All initialized fields in table are deleted.
     ***********************************************/
    ~Game();
    /**
     *  @brief Get specific field
     *  @param x X-coordinate in field table
     *  @param y Y-coordinate in field table
     *  @return Returns specific field
     ***********************************************/
    Field *getField(int x, int y);
    /**
     *  @brief Get current move color
     *  @return Returns piece color which turn is now
     ***********************************************/
    Color getCurrentMove();
    /**
     *  @return Returns true if game is over
     ***********************************************/
    bool getGameOver();
    /**
     *  @brief Checks how many kings are in fields, true if kings < 2
     *  @return Void
     ***********************************************/
    void setGameOver();
    /**
     *  @brief Fills all fields with empty field
     *  @return Void
     ***********************************************/
    void endGame();
    /**
     *  @brief Sets black or white piece move
     *  @return Void
     ***********************************************/
    void setCurrentMove();
    /**
     *  @brief Swapes two pieces, if piece is matted field is set to empty
     *  @param previousPosition X,Y-coordinates of the previous piece position
     *  @param newPosition X,Y-coordinates of the new piece position
     *  @return Void
     ***********************************************/
    void swapPiece(pair<int,int> previousPosition, pair<int,int> newPosition);
};

#endif // GAME_H
