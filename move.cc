#include "move.h"

using namespace std;

Move::Move(int fromSq, int toSq, int promPiece) : _move((fromSq)|(toSq<<7)|(promPiece<<14)) {
    //ctor
}

Move::~Move() {
    //dtor
}

int Move::getFromSq() const {
    //127 in base 2 is 1111111
    return _move&127;
}

int Move::getToSq() const {
    return (_move>>7)&127;
}

int Move::getPromotionPiece() const {
    //15 in base 2 is 1111
    return (_move>>14)&15;
}

string Move::getMove() const {
    string mv = _square[getFromSq()]+_square[getToSq()];
    if (getPromotionPiece() != EMPTY) {
        mv += _piece[getPromotionPiece()];
    }
    return mv;
}
