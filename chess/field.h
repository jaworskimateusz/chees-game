#ifndef FIELD_H
#define FIELD_H
#include "piece.h"

class Field {

private:
    Color color;
    PieceType pieceType;
    string iconName;
    Piece *piece;
public:
    Field();
    ~Field();
    void setPiece(Piece *piece, Color color, PieceType pieceType, string iconName);
    Piece getPiece();
    Color getColor();
    PieceType getPieceType();
    string getIconName();
};

#endif // FIELD_H
