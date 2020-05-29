#include "piece.h"
#include <game.h>
extern Game * game;

Piece::Piece() {

}

Piece::~Piece() {

}

Color Piece::getColor() {
    return color;
}

void Piece::setColor(Color color) {
    this->color = color;
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

bool Piece::isOpponent(pair<int,int> positionTo) {
    Color c = game->getBoard()->getField(positionTo.first, positionTo.second)->getPiece()->getColor();
    if(c != game->getCurrentMove() && c != INVISIBLE)
        return true;
    return false;
}

bool Piece::isEmpty(pair<int,int> positionTo) {
    if (dynamic_cast<EmptyField*>(game->getBoard()->getField(positionTo.first, positionTo.second)->getPiece()))
        return true;
    return false;
}
