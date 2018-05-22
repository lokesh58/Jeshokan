#include "position.h"
#include "hash.h"
#include "debug.h"

Position::Position() {
    Hash::init();
}

Position::~Position() {
    //dtor
}

Key Position::__generatePosKey() const {
    Key k = 0;

    for (int sq = 0; sq < _numBoardSq; ++sq) {
        int piece = board[sq];
        if (piece != EMPTY) {
            assert(0 <= piece && piece < EMPTY);
            k ^= Hash::getHashKey(piece, sq);
        }
    }

    assert(0 <= _enPassSq && _enPassSq < _numSquares);
    k ^= Hash::getHashKey(EMPTY, sq);

    assert(_side == WHITE || _side == BLACK);
    if (_side == WHITE) {
        k ^= Hash::getSideKey();
    }

    return k;
}
