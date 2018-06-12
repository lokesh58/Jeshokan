#ifndef TYPES_H
#define TYPES_H

#include <string>

using Key = unsigned long long;

constexpr int MAX_DEPTH = 127;

constexpr int _numPieces = 13;
enum Pieces {
    wP, wR, wN, wB, wQ, wK,
    bP, bR, bN, bB, bQ, bK,
    EMPTY
};

const std::string _piece = "PRNBQKprnbqk.";

constexpr int _numSquares = 65;
constexpr int _numBoardSq = 64;
enum Squares {
    A1, B1, C1, D1, E1, F1, G1, H1,
    A2, B2, C2, D2, E2, F2, G2, H2,
    A3, B3, C3, D3, E3, F3, G3, H3,
    A4, B4, C4, D4, E4, F4, G4, H4,
    A5, B5, C5, D5, E5, F5, G5, H5,
    A6, B6, C6, D6, E6, F6, G6, H6,
    A7, B7, C7, D7, E7, F7, G7, H7,
    A8, B8, C8, D8, E8, F8, G8, H8,
    NO_SQ
};

const std::string _square[_numSquares] = {
    "A1", "B1", "C1", "D1", "E1", "F1", "G1", "H1",
    "A2", "B2", "C2", "D2", "E2", "F2", "G2", "H2",
    "A3", "B3", "C3", "D3", "E3", "F3", "G3", "H3",
    "A4", "B4", "C4", "D4", "E4", "F4", "G4", "H4",
    "A5", "B5", "C5", "D5", "E5", "F5", "G5", "H5",
    "A6", "B6", "C6", "D6", "E6", "F6", "G6", "H6",
    "A7", "B7", "C7", "D7", "E7", "F7", "G7", "H7",
    "A8", "B8", "C8", "D8", "E8", "F8", "G8", "H8",
    "-"
};

enum Side {
    WHITE, BLACK, NONE
};

const std::string _cside[3] = {
    "WHITE", "BLACK", "NONE"
};

enum CastlingRights {
    NO_CASTLING = 0,
    WHITE_OO = 1, WHITE_OOO = 2, BLACK_OO = 4, BLACK_OOO = 8,
    WHITE_ALL = (WHITE_OO|WHITE_OOO),
    BLACK_ALL = (BLACK_OO|BLACK_OOO),
    ALL_CASTLING = (WHITE_ALL|BLACK_ALL)
};

const std::string _castle[16] = {
    "----", "K---", "-Q--", "KQ--", "--k-", "K-k-", "-Qk-", "KQk-",
    "---q", "K--q", "-Q-q", "KQ-q", "--kq", "K-kq", "-Qkq", "KQkq"
};

#endif // TYPES_H
