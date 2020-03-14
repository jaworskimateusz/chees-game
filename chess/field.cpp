#include "field.h"

Field::Field() {

}

Field::~Field() {

}

void Field::setPiece(Piece *p, Color color, PieceType pieceType, string iconName ) {
    piece = p;
    this->color = color;
    this->pieceType = pieceType;
    this->iconName = iconName;
}

Piece Field::getPiece() {
    return *piece;
}

Color Field::getColor() {
    return color;
}

PieceType Field::getPieceType() {
    return pieceType;
}

string Field::getIconName() {
    return iconName;
}

vector<pair<int,int>> Field::getMoves(int x, int y) {
    return piece->getPossiblePieceMoves(x,y);
}
