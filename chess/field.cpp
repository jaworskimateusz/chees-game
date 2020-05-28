#include "field.h"

Field::Field() {

}

Field::~Field() {

}

void Field::setPiece(Piece *p, Color color, PieceType pieceType, string iconName ) {
    piece = p;
    piece->setColor(color);
    piece->setPieceType(pieceType);
    piece->setIconName(iconName);
}

Piece* Field::getPiece() {
    return piece;
}

vector<pair<int,int>> Field::getMoves(int x, int y) {
    return piece->getPossiblePieceMoves(x,y);
}


