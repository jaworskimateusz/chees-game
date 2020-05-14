#ifndef FIELD_H
#define FIELD_H
#include "piece.h"

class Field {

private:
    Piece *piece;
public:
    Field();
    ~Field();
    void setPiece(Piece *piece, Color color, PieceType pieceType, string iconName);
    Piece* getPiece();
    vector<pair<int,int>> getMoves(int x, int y);
};

#endif // FIELD_H
