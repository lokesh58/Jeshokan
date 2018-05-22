#include "position.h"
#include "hash.h"
#include "debug.h"

Position::Position() : _side(NONE), _enPassSq(NO_SQ), _posKey(0) {
    Hash::init();
    for (int sq = 0; sq < _numBoardSq; ++sq) {
        _board[sq] = EMPTY;
    }
}

Position::~Position() {
    //dtor
}

inline int Position::getPiece(int sq) const {
    assert(0 <= sq && sq < _numBoardSq);
    return _board[sq];
}

inline int Position::getSide() const {
    return _side;
}

inline int Position::getEnPassSq() const {
    return _enPassSq;
}

inline Key Position::getPosKey() const {
    return _posKey;
}

Key Position::__generatePosKey() const {
    Key k = 0;

    for (int sq = 0; sq < _numBoardSq; ++sq) {
        int piece = getPiece(sq);
        if (piece != EMPTY) {
            assert(0 <= piece && piece < EMPTY);
            k ^= Hash::getHashKey(piece, sq);
        }
    }

    assert(0 <= getEnPassSq() && getEnPassSq() < _numSquares);
    k ^= Hash::getHashKey(EMPTY, getEnPassSq());

    assert(getSide() == WHITE || getSide() == BLACK);
    if (getSide() == WHITE) {
        k ^= Hash::getSideKey();
    }

    return k;
}
