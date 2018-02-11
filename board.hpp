#ifndef BOARD_HPP
#define BOARD_HHP

#include "Critter.hpp"
#include <iostream>

class Board
{
public:
    Board();
    Board(int, int);
    ~Board();
    void createBoard();
    void initializeBoard();
    void addAnt(int, int);
    void addDoodlebug(int, int);
    void removeCritter(Critter*);
    void printBoard();
    void avoidEdge(Critter*);
    void deleteBoard();
private:
    Critter ***theBoard;
    int rows;
    int columns;
};
#endif
