#include "position.h"
#include "hash.h"
#include "debug.h"

Position::Position() : _side(NONE), _enPassSq(NO_SQ), _fiftyMoveCounter(0),
                        _castleRights(0), _posKey(0), _historyCnt(0) {
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

inline int Position::fiftyMoveCounter() const {
    return _fiftyMoveCounter;
}

inline int Position::castleRights() const {
    return _castleRights;
}

inline bool Position::canCastle(int right) const {
    return _castleRights&right;
}

inline Key Position::posKey() const {
    return _posKey;
}

void Position::addCastleRights(int right) {
    _castleRights |= right;
}

void Position::removeCastleRights(int right) {
    _castleRights &= (~right);
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

    assert(0 <= castleRights() && castleRights() <= ALL_CASTLING);
    k ^= Hash::castleKey(castleRights());

    assert(side() == WHITE || side() == BLACK);
    if (side() == WHITE) {
        k ^= Hash::sideKey();
    }

    return k;
}
