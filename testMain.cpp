#include "board.hpp"
#include "Critter.hpp"
#include "Ant.hpp"

int main()
{
    Board theBoard;

    theBoard.createBoard();
    theBoard.initializeBoard();
    theBoard.printBoard();
    theBoard.deleteBoard();
}
