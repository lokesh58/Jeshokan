#ifndef HASH_H
#define HASH_H

#include "types.h"

namespace Hash {
    void init();
    inline Key getHashKey(int piece, int sq);
    inline Key getSideKey();
}

#endif // HASH_H
