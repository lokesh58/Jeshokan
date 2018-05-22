#ifndef POSITION_H
#define POSITION_H

#include "types.h"

class Position {
    public:
        Position();
        ~Position();

    private:
        Key __generatePosKey() const;

        int board[_numBoardSq];
        int _side;
        int _enPassSq;
        Key _posKey;
};

#endif // POSITION_H
