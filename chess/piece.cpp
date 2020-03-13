#include "piece.h"

Piece::Piece() {

}

Piece::~Piece() {

}

void Piece::setColor(Color color) {
    this->color = color;
}

Color Piece::getColor() {
    return color;
}

void Piece::setPieceType(PieceType pieceType) {
    this->pieceType = pieceType;
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

vector<pair<int,int>> Piece::getAllPieceMoves() {
    return vector<pair<int,int>>();
}

vector<pair<int,int>> Piece::getPossiblePieceMoves() {
    return vector<pair<int,int>>();
}
