#include "piece.h"

Piece::Piece() {

}

Piece::~Piece() {

}

Color Piece::getColor() {
    return color;
}

PieceType Piece::getPieceType() {
    return pieceType;
}

string Piece::getIconName() {
    return iconName;
}

void Piece::setIconName(string iconName) {
    this->iconName = iconName;
}

vector<pair<int,int>> Piece::getPossiblePieceMoves(int x, int y) {
    return vector<pair<int,int>>();
}
