#ifndef POSITION_H
#define POSITION_H

#include "types.h"

class Position {
    public:
        Position();
        ~Position();

        int pieceAt(int sq) const;
        int side() const;
        int enPassSq() const;
        Key posKey() const;

    private:
        Key __generatePosKey() const;

        int _board[_numBoardSq];
        int _side;
        int _enPassSq;
        Key _posKey;
};

#endif // POSITION_H
