#include "rook.h"

Rook::Rook() {

}

vector<pair<int,int>> Rook::getPossiblePieceMoves(int x, int y) {
    moves.clear();

    for(int i = 0; i < 8; i++) {
        if(i != y) {
            pair<int,int> position(x, i);
            moves.push_back(position);
        }
        if(i != x) {
            pair<int,int> position(i, y);
            moves.push_back(position);
        }
    }

    return moves;
}
