#include "board.hpp"
#include <cstdlib>
#include <ctime>
#include <typeinfo>

Board::Board()
    : rows(20), columns(20)
{
}

Board::Board(int r, int c)
    : rows(r), columns(c)
{
}

Board::~Board()
{
}

void Board::createBoard()
{
    unsigned seed = time(NULL);
    srand(seed);

    theBoard = new Critter**[rows];
    for (int i = 0; i < rows; i++)
    {
        theBoard[i] = new Critter*[columns];
    
        for (int j = 0; j < columns; j++)
        {
            theBoard[i][j] = new Critter();
        }
    }
}

void Board::initializeBoard()
{
    int tempX, tempY;

    for (int i = 0; i < 5; i++)
    {
        do
        {
            tempX = rand() % 20;
            tempY = rand() % 20;
        }
        while (theBoard[tempX][tempY] != NULL);

        theBoard[tempX][tempY] = new Ant;
    }

    for (int i = 0; i < 100; i++)
    {
        do
        {
            tempX = rand() % 20;
            tempY = rand() % 20;
        }
        while (theBoard[tempX][tempY] != NULL);
    
        theBoard[tempX][tempY] = new Doodlebug;
    }
}

void Board::addAnt(int x, int y)
{
    while (theBoard[x][y] != NULL)
    {
        theBoard[x][y] = new Ant;
    }
}

void Board::addDoodlebug(int x, int y)
{
    while (theBoard[x][y] != NULL)
    {
        theBoard[x][y] = new Doodlebug;
    }
}
void Board::removeCritter(Critter *crit)
{
    delete theBoard[crit->getX()][crit->getY()];
}

void Board::printBoard()
{
    std::cout << std::string((columns), '-') << std::endl;
    for (int i = 0; i < rows; i++)
    {
        std::cout << "| ";
        for (int j = 0; j < columns; j++)
        {
            std::cout << theBoard[i][j]->printChar();
        }
        std::cout << " |" << std::endl;
    }
    std::cout << std::string((columns), '-') << std::endl;
}

void Board::avoidEdge(Critter *crit)
{
    if (crit->getX() < 0)
    {
        crit->setX(rows - 1);
    }
    
    if (crit->getX() > (rows - 1))
    {
        crit->setX(0);
    }
    
    if (crit->getY() < 0)
    {
        crit->setY(columns - 1);
    }
    
    if (crit->getY() > (columns - 1))
    {
        crit->setY(0);
    }
}

void Board::deleteBoard()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            delete theBoard[i][j];
        }
        delete [] theBoard[i];
    }
    delete [] theBoard;
    theBoard = NULL;
}
