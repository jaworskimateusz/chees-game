#include "piece.h"
Piece::Piece() {

}

Piece::~Piece() {

}

void Piece::setColor(QString color) {
    this->color = color;
}

QString Piece::getColor() {
    return color;
}

void Piece::setPieceType(QString pieceType) {
    this->pieceType = pieceType;
}

QString Piece::getPieceType() {
    return pieceType;
}

void Piece::displayPiece() {

}

QString Piece::getIconName() {
    return iconName;
}

void Piece::setIconName(QString iconName) {
    this->iconName = iconName;
}
