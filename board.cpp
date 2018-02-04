#include "board.hpp"

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

void Board::setRows(int r);
{
    this->rows = r;
}

void Board::setColumns(int c)
{
    this->columns = c;
}

void Board::setCurrentRow(int cr)
{
    this->currentRow = cr;
}

void Board::setCurrentColumn(int cc)
{
    this->currentColumn = cc;
}

int Board::getRows()
{
    return this->rows;
}

int Board::getColumns()
{
    return this->columns;
}

int Board::getCurrentRow()
{
    return this->currentRow;
}

int Board::getCurrentColumn()
{
    return this->currentColumn;
}

void Board::initBoard()
{
    theBoard = new char*[rows];
    for (int i = 0; i < rows; i++)
    {
        theBoard[i] = new char[columns];
    }
}

void Board::printBoard()
{
    std::cout << string((columns), '-') << std::endl;
    for (int i = 0; i < rows; i++)
    {
        std::cout << "| ";
        for (int j = 0; j < columns; j++)
        {
            std::cout << theBoard[i][j];
        }
        std::cout << " |" << endl;
    }
    std::cout << string((columns), '-') << std::endl;
}

void Board::avoidEdge(Critter *crit)
{
    //will be uncommented (and potentially reworked) upon confirmation
    //of get and set functions in the critter class
    
    /*
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
    */
}

void Board::deleteBoard()
{
    for (int i = 0; i < rows; i++)
    {
        delete [] theBoard[i];
    }
    delete [] array;
}
