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
        int fiftyMoveCounter() const;
        int castleRights() const;
        bool canCastle(int right) const;
        Key posKey() const;

    private:
        void addCastleRights(int right);
        void removeCastleRights(int right);

        Key __generatePosKey() const;

        struct History {
            int _enPassSq = 0;
            int _fiftyMoveCounter = 0;
            int _castleRights = 0;
            Key _posKey = 0;
        };

        int _board[_numBoardSq];
        int _side;
        int _enPassSq;
        int _fiftyMoveCounter;
        int _castleRights;
        Key _posKey;

        int _historyCnt;
        History _history[MAX_DEPTH+1];
};

#endif // POSITION_H
