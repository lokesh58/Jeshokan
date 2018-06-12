#include "position.h"
#include <string>

using namespace std;

int main()
{
    Position pos;
    string fen = startFEN;
    pos.parseFEN(fen);
    pos.dispBoard();
    fen = "rnbqkbnr/pppppppp/8/8/4P3/8/PPPP1PPP/RNBQKBNR b KQkq e3 0 1";
    pos.parseFEN(fen);
    pos.dispBoard();
    fen = "rnbqkbnr/pp1ppppp/8/2p5/4P3/8/PPPP1PPP/RNBQKBNR w KQkq c6 0 2";
    pos.parseFEN(fen);
    pos.dispBoard();
    fen = "rnbqkbnr/pp1ppppp/8/2p5/4P3/5N2/PPPP1PPP/RNBQKB1R b KQkq - 1 2";
    pos.parseFEN(fen);
    pos.dispBoard();
    return 0;
}
