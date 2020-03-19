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
    friend class Field;
protected:
    vector<pair<int,int>> moves;
    Color color;
    PieceType pieceType;
    string iconName;
public:
    Piece();
    ~Piece();
    Piece(Color color, PieceType pieceType, string iconName);
    Color getColor();
    PieceType getPieceType();
    string getIconName();
    void setIconName(string iconName);
    virtual vector<pair<int,int>> getPossiblePieceMoves(int x, int y);

};

#endif // PIECE_H
