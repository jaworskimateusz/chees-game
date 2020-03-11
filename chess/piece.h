#ifndef PIECE_H
#define PIECE_H
#include "position.h"

#include <QString>

class Piece {

private:
    QString color;
    QString pieceType;
    QString iconName;
public:
    Piece();
    ~Piece();
    void setColor(QString color);
    QString getColor();
    void setPieceType(QString pieceType);
    QString getPieceType();
    QString getIconName();
    void setIconName(QString iconName);
    void displayPiece();
    virtual QVector<Position> getAllPieceMoves();
    virtual QVector<Position> getPossiblePieceMoves();

};

#endif // PIECE_H
