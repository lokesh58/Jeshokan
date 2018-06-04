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

inline int Position::pieceAt(int sq) const {
    assert(0 <= sq && sq < _numBoardSq);
    return _board[sq];
}

inline int Position::side() const {
    return _side;
}

inline int Position::enPassSq() const {
    return _enPassSq;
}

inline Key Position::posKey() const {
    return _posKey;
}

Key Position::__generatePosKey() const {
    Key k = 0;

    for (int sq = 0; sq < _numBoardSq; ++sq) {
        int piece = pieceAt(sq);
        if (piece != EMPTY) {
            assert(0 <= piece && piece < EMPTY);
            k ^= Hash::hashKey(piece, sq);
        }
    }

    assert(0 <= enPassSq() && enPassSq() < _numSquares);
    k ^= Hash::hashKey(EMPTY, enPassSq());

    assert(side() == WHITE || side() == BLACK);
    if (side() == WHITE) {
        k ^= Hash::sideKey();
    }

    return k;
}
