/*******************************************************************************
 * Class Name: Game
 * Description: Handles all functions related to the board that the simulation
 * takes place on. Functionality includes createBoard, initializeBoard, addAnt,
 * addDoodlebug, removeCritter, printBoard, avoidEdge, and deleteBoard
 ******************************************************************************/

#include "board.hpp"
#include <cstdlib>
#include <ctime>

Board::Board()
    : rows(20), columns(20)
{
    createBoard();
    initializeBoard();
}

Board::Board(int r, int c)
    : rows(r), columns(c)
{
    createBoard();
    initializeBoard();
}

Board::~Board()
{
}

Critter*** Board::getBoard()
{
    return theBoard;
}

int Board::getRows()
{
    return this->rows;
}

int Board::getCols()
{
    return this->columns;
}

/*******************************************************************************
 * Name: createBoard
 * Description: Creates a new board for the simulation
 ******************************************************************************/
void Board::createBoard()
{
    //seed all random number generation in the program
    unsigned seed = time(NULL);
    srand(seed);

    //create a new 2d board of pointers to Critters
    theBoard = new Critter**[rows];
    for (int i = 0; i < rows; i++)
    {
        theBoard[i] = new Critter*[columns];
    
        for (int j = 0; j < columns; j++)
        {
            theBoard[i][j] = NULL;
        }
    }
}

/*******************************************************************************
 * Name: initializeBoard
 * Description: Adds all Critters to the board for the start of the game 
 ******************************************************************************/
void Board::initializeBoard()
{
    //temporary variables to hold random coordinates
    int tempX, tempY;

    //add 5 Doodlebugs to the board to start the game
    for (int i = 0; i < 5; i++)
    {
        //loop until the randomly selected spot is not occupied
        do
        {
            tempX = rand() % 20;
            tempY = rand() % 20;
        }
        while (theBoard[tempX][tempY] != NULL);

        addDoodlebug(tempX, tempY);
    }

    //add 100 Ants to the board to start the game
    for (int i = 0; i < 100; i++)
    {
        do
        {
            tempX = rand() % 20;
            tempY = rand() % 20;
        }
        while (theBoard[tempX][tempY] != NULL);
    
        addAnt(tempX, tempY);
    }
}

/*******************************************************************************
 * Name: addAnt
 * Description: Creates a new board for the simulation
 ******************************************************************************/
void Board::addAnt(int x, int y)
{
    //if the space is not occupied, create an Ant
    if (theBoard[x][y] == NULL)
    {
        theBoard[x][y] = new Ant(x, y); 
    }
}

/*******************************************************************************
 * Name: addDoodlebug
 * Description: Creates a new Doodlebug at the specified location 
 ******************************************************************************/
void Board::addDoodlebug(int x, int y)
{
    //if the space is not occupied, create a Doodlebug
    if (theBoard[x][y] == NULL)
    {
        theBoard[x][y] = new Doodlebug(x, y);    
    }
}

/*******************************************************************************
 * Name: removeCritter
 * Description: Deletes a critter from the specified position on the board 
 ******************************************************************************/
void Board::removeCritter(int x, int y)
{
    delete theBoard[x][y];
    theBoard[x][y] = NULL;
}

/*******************************************************************************
 * Name: printBoard
 * Description: Prints the current board to the screen 
 ******************************************************************************/
void Board::printBoard()
{
    std::cout << std::string((columns), '-') << std::endl;
    //print each row from the outer array
    for (int i = 0; i < rows; i++)
    {
        std::cout << "| ";
        //print each column from the inner array
        for (int j = 0; j < columns; j++)
        {
            if (theBoard[i][j] == NULL)
            {
                std::cout << ' ';
            }
            else
            {
                //print the character associated with each critter type
                std::cout << theBoard[i][j]->getCritType();
            }
        }
        std::cout << " |" << std::endl;
    }
    std::cout << std::string((columns), '-') << std::endl;
}

/*******************************************************************************
 * Name: avoidEdge
 * Description: Checks if a critter is off the board and wraps it to the other
 * side if so
 ******************************************************************************/
void Board::avoidEdge(Critter *crit)
{
    if (crit->getRowPosition() < 0)
    {
        crit->setRowPosition(rows - 1);
    }
    
    if (crit->getRowPosition() > (rows - 1))
    {
        crit->setRowPosition(0);
    }
    
    if (crit->getColPosition() < 0)
    {
        crit->setColPosition(columns - 1);
    }
    
    if (crit->getColPosition() > (columns - 1))
    {
        crit->setColPosition(0);
    }
}

/*******************************************************************************
 * Name: deleteBoard
 * Description: Frees all dynamic memory allocated by the board 
 ******************************************************************************/
void Board::deleteBoard()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            //delete objects pointed to by Critter pointers
            delete theBoard[i][j];
        }
        //delete the array of columns
        delete [] theBoard[i];
    }
    //delete the array of rows
    delete [] theBoard;
    theBoard = NULL;
}
