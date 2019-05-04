#ifndef MOVE_H
#define MOVE_H

#include "types.h"

/** In a single integer all information is stored
  * From and To Squares can be 0 to 63, so 6 bits (2^6-1 = 63) are enough for each
  * If the pawn is promoted we need to store to which piece (0 to 12) -> 4 bits
  * 0000 0000000 0000000
  * So 18 bits are enough. Hence we use datatype long which guarantees atleast 32 bits
*/

class Move {
    public:
        Move();
        Move(int fromSq, int toSq, int promPiece = EMPTY);
        ~Move();

        int getFromSq() const;
        int getToSq() const;
        int getPromotionPiece() const;

        string getMove() const;

    private:
        long _move;
};

#endif // MOVE_H
