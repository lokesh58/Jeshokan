#ifndef HASH_H
#define HASH_H

#include "types.h"

namespace Hash {
    void init();
    Key hashKey(int piece, int sq);
    Key castleKey(int rights);
    Key sideKey();
}

#endif // HASH_H
