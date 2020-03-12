#include "field.h"

Field::Field() {

}

Field::~Field() {

}

void Field::setPiece(Piece *piece, Color color, PieceType pieceType, string iconName ) {
    this->piece = piece;
    this->color = color;
    this->pieceType = pieceType;
    this->iconName = iconName;
}
