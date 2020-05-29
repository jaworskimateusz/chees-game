#include "game.h"

Game::Game() {
    board = new Board();
    currentMove = BLACK;
}

Game::~Game() {

}

Color Game::getCurrentMove() {
    return currentMove;
}

void Game::setCurrentMove() {
    currentMove = currentMove == BLACK ? WHITE : BLACK;
}

bool Game::getGameOver() {
    return isGameOver;
}

void Game::setGameOver() {
    this->isGameOver = board->isKingMatted();
}

void Game::endGame() {
    for(int i = 0; i < 8 ;i++)
        for(int j = 0; j < 8 ;j++)
            board->getField(i,j)->setPiece(new EmptyField(), INVISIBLE, "");
}

Board* Game::getBoard() {
    return this->board;
}
