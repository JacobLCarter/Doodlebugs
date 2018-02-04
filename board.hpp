#ifndef BOARD_HPP
#define BOARD_HHP

#include "critter.hpp"
#include <iostream>

class Board
{
public:
    Board();
    Board(int, int);
    ~Board();
    void setRows(int);
    void setColumns(int);
    int getRows();
    int getColumns();
    void initBoard();
    void printBoard();
    void avoidEdge(Critter*);
    void deleteBoard();
private:
    char **theBoard;
    int rows;
    int columns;
    int currentRow;
    int currentColumn;
};
#endif
