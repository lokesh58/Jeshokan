#ifndef HASH_H
#define HASH_H

#include "types.h"

namespace Hash {
    void init();
    Key getHashKey(int piece, int sq);
    Key getSideKey();
}

#endif // HASH_H
