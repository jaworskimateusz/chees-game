#include "field.h"

Field::Field() {

}

Field::~Field() {

}

void Field::setPiece(Piece *piece, QString color, QString pieceType, QString iconName ) {
    this->piece = piece;
    this->color = color;
    this->pieceType = pieceType;
    this->iconName = iconName;
}
