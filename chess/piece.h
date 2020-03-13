#ifndef PIECE_H
#define PIECE_H
#include "position.h"
#include "PieceType.h"
#include "Color.h"
#include <stdio.h>
#include <string>
#include <vector>


using namespace std;
class Piece {

private:
    Color color;
    PieceType pieceType;
    string iconName;
public:
    Piece();
    ~Piece();
    Piece(Color color, PieceType pieceType, string iconName);
    void setColor(Color color);
    Color getColor();
    void setPieceType(PieceType pieceType);
    PieceType getPieceType();
    string getIconName();
    void setIconName(string iconName);
    virtual vector<pair<int,int>> getAllPieceMoves() = 0;
    virtual vector<pair<int,int>> getPossiblePieceMoves() = 0;

};

#endif // PIECE_H
