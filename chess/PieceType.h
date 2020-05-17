#ifndef PIECETYPE_H
#define PIECETYPE_H

/**
 *  @file   PieceType.h
 *  @brief  Enumeration which represents piece types
 *  @author Mateusz Jaworski
 *  @date   14-05-2020
 ***********************************************/
enum PieceType {
    BISHOP, ///< this is bishop piece type
    KING, ///< this is king piece type
    KNIGHT, ///< this is knight piece type
    PAWN, ///< this is pawn piece type
    QUEEN, ///< this is queen piece type
    ROOK, ///< this is rook piece type
    EMPTY_FIELD ///< this is empty field
};

#endif // PIECETYPE_H
