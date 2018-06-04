#include "hash.h"
#include <random>
#include "debug.h"

namespace Hash {
    bool _init = false;
    std::mt19937_64 _engine;
    std::uniform_int_distribution<Key> _rand64(0, 0XFFFFFFFFFFFFFFFFULL);

    Key _hashKeys[_numPieces][_numSquares];
    Key _sideKey;

    void init() {
        if (!_init) {
            _init = true;
            for (int piece = 0; piece < _numPieces; ++piece) {
                for (int sq = 0; sq < _numSquares; ++sq) {
                    _hashKeys[piece][sq] = _rand64(_engine);
                }
            }
            _sideKey = _rand64(_engine);
        }
    }

    Key hashKey(int piece, int sq) {
        assert(0 <= piece && piece < _numPieces);
        assert(0 <= sq && sq < _numSquares);
        return _hashKeys[piece][sq];
    }

    Key sideKey() {
        return _sideKey;
    }
}
