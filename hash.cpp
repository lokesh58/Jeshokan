#include "hash.h"
#include <random>
#include "debug.h"

namespace Hash {
    bool _init = false;
    std::mt19937_64 engine;
    std::uniform_int_distribution<Key> rand64(0, 0XFFFFFFFFFFFFFFFFULL);

    Key hashKeys[_numPieces][_numSquares];
    Key _sideKey;

    void init() {
        if (!_init) {
            _init = true;
            for (int piece = 0; piece < _numPieces; ++piece) {
                for (int sq = 0; sq < _numSquares; ++sq) {
                    hashKeys[piece][sq] = rand64(engine);
                }
            }
            _sideKey = rand64(engine);
        }
    }

    Key getHashKey(int piece, int sq) {
        assert(0 <= piece && piece < _numPieces);
        assert(0 <= sq && sq < _numSquares);
        return hashKeys[piece][sq];
    }

    Key getSideKey() {
        return _sideKey;
    }
}
