#ifndef POSITION_H
#define POSITION_H

#include "types.h"

class Position {
    public:
        Position();
        ~Position();

        int getPiece(int sq) const;
        int getSide() const;
        int getEnPassSq() const;
        Key getPosKey() const;

    private:
        Key __generatePosKey() const;

        int _board[_numBoardSq];
        int _side;
        int _enPassSq;
        Key _posKey;
};

#endif // POSITION_H
