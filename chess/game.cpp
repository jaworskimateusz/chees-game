#include "game.h"

Game::Game() {

    for(int i = 0; i < 8; i++ ) {
        for(int j = 0; j < 8; j++) {

            if(i == 0) {
                if(j==0 || j==7)
                    fields[i][j].setPiece(new class Rook(), BLACK, ROOK,":/img/rook.png");
                if(j==1 || j==6)
                    fields[i][j].setPiece(new class Knight(), BLACK, KNIGHT, ":/img/knight.png");
                if(j==2 || j==5)
                    fields[i][j].setPiece(new class Bishop(), BLACK, BISHOP,":/img/bishop.png");
                if(j==3)
                    fields[i][j].setPiece(new class Queen(), BLACK, QUEEN, ":/img/queen.png");
                if(j==4)
                    fields[i][j].setPiece(new class King(), BLACK, KING, ":/img/king.png");
             }

             if(i == 7) {
                if(j==0 || j==7)
                    fields[i][j].setPiece(new class Rook(), WHITE, ROOK, ":/img/rook_white.png");
                if(j==1 || j==6)
                    fields[i][j].setPiece(new class Knight(), WHITE, KNIGHT, ":/img/knight_white.png");
                if(j==2 || j==5)
                    fields[i][j].setPiece(new class Bishop(), WHITE, BISHOP, ":/img/bishop_white.png");
                if(j==3)
                    fields[i][j].setPiece(new class Queen(), WHITE, QUEEN, ":/img/queen_white.png");
                if(j==4)
                    fields[i][j].setPiece(new class King(), WHITE, KING, ":/img/king_white.png");
             }

             if (i == 1)
                 fields[i][j].setPiece(new class Pawn(), BLACK, PAWN, ":/img/pawn.png");
             if(i == 6)
                 fields[i][j].setPiece(new class Pawn(), WHITE, PAWN, ":/img/pawn_white.png");
             if(i > 1 && i < 6)
                 fields[i][j].setPiece(new class EmptyField(), INVISIBLE, EMPTY_FIELD, "");

        }
    }
    currentMove = (rand() % 2) == 1 ? WHITE : BLACK;
}

Game::~Game() {

}

Field Game::getField(int x, int y) {
    return fields[x][y];
}

Color Game::getCurrentMove() {
    return currentMove;
}

void Game::setCurrentMove() {
    currentMove = currentMove == BLACK ? WHITE : BLACK;
}

void Game::swapPiece(pair<int,int> previousPosition, pair<int,int> newPosition) {
//      Field  f = fields[previousPosition.first, previousPosition.second];  //it's not java -.-
    int x0 = previousPosition.first;
    int y0 = previousPosition.second;

    int x = newPosition.first;
    int y = newPosition.second;
    PieceType pieceType = fields[x0][y0].getPiece().getPieceType();
    Color color = fields[x0][y0].getPiece().getColor();

    string _white = color == WHITE ? "_white.png" : ".png";

    switch(pieceType) {
        case EMPTY_FIELD:
            fields[x][y].setPiece(new class EmptyField(), INVISIBLE, EMPTY_FIELD, ""); break;
        case PAWN:
            fields[x][y].setPiece(new class Pawn(), color, PAWN, ":/img/pawn" + _white); break;
        case KNIGHT:
            fields[x][y].setPiece(new class Knight(), color, KNIGHT, ":/img/knight" + _white); break;
        case BISHOP:
            fields[x][y].setPiece(new class Bishop(), color, BISHOP, ":/img/bishop" + _white); break;
        case KING:
            fields[x][y].setPiece(new class King(), color, KING, ":/img/king" + _white); break;
        case QUEEN:
            fields[x][y].setPiece(new class Queen(), color, QUEEN, ":/img/queen" + _white); break;
        case ROOK:
            fields[x][y].setPiece(new class Rook(), color, ROOK, ":/img/rook" + _white); break;
    }


   fields[x0][y0].setPiece(new class EmptyField(), INVISIBLE, EMPTY_FIELD, "");
}

vector<pair<int,int>> Game::getPieceMoves() {
    return pieceMoves;
}
