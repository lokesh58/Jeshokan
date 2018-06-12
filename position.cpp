#include "position.h"
#include "hash.h"
#include "debug.h"
#include <iostream>
using namespace std;

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

Position& Position::parseFEN(const string &fen) {
    //SET PIECES
    int currSq = H8;
    auto it = fen.cbegin();
    while (*it != ' ') {
        char c = *it;
        if (c >= '1' && c <= '8') {
            int numEmpty = c-'0';
            while (numEmpty--) {
                _board[currSq--] = EMPTY;
            }
        } else {
            switch (c) {
                case 'r' :
                    _board[currSq--] = bR;
                    break;
                case 'n' :
                    _board[currSq--] = bN;
                    break;
                case 'b' :
                    _board[currSq--] = bB;
                    break;
                case 'q' :
                    _board[currSq--] = bQ;
                    break;
                case 'k' :
                    _board[currSq--] = bK;
                    break;
                case 'p' :
                    _board[currSq--] = bP;
                    break;
                case 'R' :
                    _board[currSq--] = wR;
                    break;
                case 'N' :
                    _board[currSq--] = wN;
                    break;
                case 'B' :
                    _board[currSq--] = wB;
                    break;
                case 'Q' :
                    _board[currSq--] = wQ;
                    break;
                case 'K' :
                    _board[currSq--] = wK;
                    break;
                case 'P' :
                    _board[currSq--] = wP;
                    break;
                case '/' :
                    assert(((currSq+1)&7) == 0);
                    break;
                default :
                    assert(false);
                    break;
            }
        }
        ++it;
    }
    assert(currSq == -1);
    ++it;
    //SET SIDE TO MOVE
    assert(*it == 'w' || *it == 'b');
    if (*it == 'w') {
        _side = WHITE;
    } else {
        _side = BLACK;
    }
    ++it;
    assert(*it == ' ');
    ++it;
    //SET CASTLING RIGHTS
    _castleRights = NO_CASTLING;
    while (*it != ' ') {
        switch (*it) {
            case 'K' :
                addCastleRights(WHITE_OO);
                break;
            case 'Q' :
                addCastleRights(WHITE_OOO);
                break;
            case 'k' :
                addCastleRights(BLACK_OO);
                break;
            case 'q' :
                addCastleRights(BLACK_OOO);
                break;
            case '-' :
                break;
            default :
                assert(false);
                break;
        }
        ++it;
    }
    ++it;
    //SET EN-PASSANT SQUARE
    if (*it == '-') {
        _enPassSq = NO_SQ;
    } else {
        int file = (*it) - 'a';
        ++it;
        int rank = (*it) - '1';
        _enPassSq = 8*rank+file;
    }
    ++it;
    assert(*it == ' ');
    ++it;
    //SET FIFTY MOVE COUNTER
    int cnt = 0;
    while (*it != ' ') {
        cnt = cnt*10 + (*it) - '0';
        ++it;
    }
    _fiftyMoveCounter = cnt;
    //WE DO NOT NEED FULL MOVE COUNTER

    _posKey = __generatePosKey();
    _historyCnt = 0;

    return *this;
}

const Position& Position::dispBoard() const {
    for (int sq = H8; sq >= A1; --sq) {
        cout << _piece[pieceAt(sq)] << ' ';
        if (((sq)&7) == 0) cout << endl; //if sq is divisible by 8
    }
    cout << endl;
    cout << "PosKey : " << hex << posKey() << dec << '\n'
         << "EnPassantSq : " << _square[enPassSq()] << '\n'
         << "Castling Rights : " << _castle[castleRights()] << '\n'
         << "Side to move : " << _cside[side()] << '\n'
         << "Fifty Move Counter : " << fiftyMoveCounter() << endl;

    return *this;
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
