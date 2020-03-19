#include "game.h"

Game::Game() {
    fields = new Field**[8];
    for(int i = 0; i < 8; i++ ) {
        fields[i] = new Field*[8];
        for(int j = 0; j < 8; j++) {
            fields[i][j] = new Field();
            if(i == 0) {
                if(j==0 || j==7)
                    fields[i][j]->setPiece(new Rook(), BLACK, ROOK,":/img/rook.png");
                if(j==1 || j==6)
                    fields[i][j]->setPiece(new Knight(), BLACK, KNIGHT, ":/img/knight.png");
                if(j==2 || j==5)
                    fields[i][j]->setPiece(new Bishop(), BLACK, BISHOP,":/img/bishop.png");
                if(j==3)
                    fields[i][j]->setPiece(new Queen(), BLACK, QUEEN, ":/img/queen.png");
                if(j==4)
                    fields[i][j]->setPiece(new King(), BLACK, KING, ":/img/king.png");
             }

             if(i == 7) {
                if(j==0 || j==7)
                    fields[i][j]->setPiece(new Rook(), WHITE, ROOK, ":/img/rook_white.png");
                if(j==1 || j==6)
                    fields[i][j]->setPiece(new Knight(), WHITE, KNIGHT, ":/img/knight_white.png");
                if(j==2 || j==5)
                    fields[i][j]->setPiece(new Bishop(), WHITE, BISHOP, ":/img/bishop_white.png");
                if(j==3)
                    fields[i][j]->setPiece(new Queen(), WHITE, QUEEN, ":/img/queen_white.png");
                if(j==4)
                    fields[i][j]->setPiece(new King(), WHITE, KING, ":/img/king_white.png");
             }

             if (i == 1)
                 fields[i][j]->setPiece(new Pawn(), BLACK, PAWN, ":/img/pawn.png");
             if(i == 6)
                 fields[i][j]->setPiece(new Pawn(), WHITE, PAWN, ":/img/pawn_white.png");
             if(i > 1 && i < 6)
                 fields[i][j]->setPiece(new EmptyField(), INVISIBLE, EMPTY_FIELD, "");

        }
    }
    currentMove = BLACK;
}

Game::~Game() {
    for (int i=0; i<8; i++) {
        delete[] fields[i];
    }
    delete[] fields;
}

Field* Game::getField(int x, int y) {
    return fields[x][y];
}

Color Game::getCurrentMove() {
    return currentMove;
}

void Game::setCurrentMove() {
    currentMove = currentMove == BLACK ? WHITE : BLACK;
}

void Game::swapPiece(pair<int,int> previousPosition, pair<int,int> newPosition) {
    int x0 = previousPosition.first;
    int y0 = previousPosition.second;

    int x = newPosition.first;
    int y = newPosition.second;

    PieceType pieceType = fields[x0][y0]->getPiece()->getPieceType();
    Color color = fields[x0][y0]->getPiece()->getColor();
    string _white = color == WHITE ? "_white.png" : ".png";

    switch(pieceType) {
        case EMPTY_FIELD:
            fields[x][y]->setPiece(new EmptyField(), INVISIBLE, EMPTY_FIELD, ""); break;
        case PAWN:
            fields[x][y]->setPiece(new Pawn(), color, PAWN, ":/img/pawn" + _white); break;
        case KNIGHT:
            fields[x][y]->setPiece(new Knight(), color, KNIGHT, ":/img/knight" + _white); break;
        case BISHOP:
            fields[x][y]->setPiece(new Bishop(), color, BISHOP, ":/img/bishop" + _white); break;
        case KING:
            fields[x][y]->setPiece(new King(), color, KING, ":/img/king" + _white); break;
        case QUEEN:
            fields[x][y]->setPiece(new Queen(), color, QUEEN, ":/img/queen" + _white); break;
        case ROOK:
            fields[x][y]->setPiece(new Rook(), color, ROOK, ":/img/rook" + _white); break;
    }

   setGameOver();
   fields[x0][y0]->setPiece(new EmptyField(), INVISIBLE, EMPTY_FIELD, "");
}

bool Game::getGameOver() {
    return isGameOver;
}

void Game::setGameOver() {
    int kings = 0;
    for(int i = 0; i < 8 ;i++) {
        for(int j = 0; j < 8 ;j++){
            if(getField(i,j)->getPiece()->getPieceType() == KING) {
                kings++;
            }
            if(kings == 2) {
                this->isGameOver = false;
                break;
            }
        }
    }
    if(kings < 2)
        this->isGameOver = true;
}

void Game::endGame() {
    for(int i = 0; i < 8 ;i++)
        for(int j = 0; j < 8 ;j++)
            getField(i,j)->setPiece(new EmptyField(), INVISIBLE, EMPTY_FIELD, "");
}
