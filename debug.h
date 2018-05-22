#ifndef DEBUG_H
#define DEBUG_H

#define DEBUG

#ifdef DEBUG
#include <cassert>
#else
#define assert(e)
#endif // DEBUG

#endif // DEBUG_H
