#ifndef FIELD_H
#define FIELD_H
#include "piece.h"

#include <QString>

class Field {

private:
    QString color;
    QString pieceType;
    QString iconName;
    Piece *piece;
public:
    Field();
    ~Field();
    void setPiece(Piece *piece, QString color, QString pieceType, QString iconName);
};

#endif // FIELD_H
