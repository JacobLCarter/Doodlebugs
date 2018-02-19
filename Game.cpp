/***********************************************************************
This is the Game.cpp file. It contains the implementation for the game.
************************************************************************/
#include "Game.hpp"
#include<iostream>
/*constructor takes an integer parameter and sets the
number of times the play game function will loop for. */
Game::Game(int numTurns)
{
	this->turns = numTurns;
}


/*This function implements the game.*/
void Game::playGame()
{

   Board boardObj;

   //for the number of time steps specified by the user, play the game
   for (int index = 0; index < this->turns; index++)
   {
	//loop through the whole board. 

      for (int i = 0; i < boardObj.getRows(); i++)
      {
        for (int j = 0; j < boardObj.getCols(); j++)
        {
          if (boardObj.getBoard()[i][j] != NULL)
          {
            //get a pointer to the current critter on the board
            Critter* doodleBugPtr = (boardObj.getBoard()[i][j]);

            /*If critter is an doodleBug and the critter did not just move to new square
            /proceed with the calculations  */
            if (doodleBugPtr->getCritType() == 'X' && !doodleBugPtr->getJustMoved())
            {
              //call the critMove() function to make the doodleBug do its thing
              doodleBugPtr->critMove(boardObj.getBoard(), boardObj.getRows() - 1, boardObj.getCols() - 1);

              //Set moved to true so the critter is not selected during the next loop
              doodleBugPtr->setJustMoved(true);

              //call the critBreed() function on the critter
	      doodleBugPtr->critBreed(boardObj.getBoard(), boardObj.getRows() - 1, boardObj.getCols() - 1);
	

		//if the critter has not eaten in 3 time steps it dies (ie nullptr)
	//	if (doodleBugPtr->getLastEaten() >= 3)
 	//  	{    
        //                std::cout << doodleBugPtr->getLastEaten() << std::endl;
//			boardObj.removeCritter(i, j);
//		}
             }
            }
          }
        }

     //loop through the board again and remove all doodlebugs that are have not eated in 3 days
     for(int i = 0; i < boardObj.getRows(); i++)
     {
       for(int j = 0; j < boardObj.getCols(); j++)
       {
         if(boardObj.getBoard()[i][j] != NULL && boardObj.getBoard()[i][j]->getCritType() == 'X'
            && boardObj.getBoard()[i][j]->getLastEaten() >= 3)
          {
            boardObj.removeCritter(i, j);
          }
           
       } 
     }

   //loop through the whole board again. This time for the Ants to do their thing 
    for (int i = 0; i < boardObj.getRows(); i++)
    {
     for (int j = 0; j < boardObj.getCols(); j++)
     {
	if (boardObj.getBoard()[i][j] != NULL)
	{
		//get a pointer to the current critter on the board
		Critter* antPtr = (boardObj.getBoard()[i][j]);

		//call critter is an Ant, and has not moved on this turn
		if (antPtr->getCritType() == 'O' && !antPtr->getJustMoved())
		{
			//call the crit move function to make the critter move
			antPtr->critMove(boardObj.getBoard(), boardObj.getRows() - 1, boardObj.getCols() - 1);

			//set justMoved to true. (Once again, we need this in the critter class)
			antPtr->setJustMoved(true);

			//call the breed function on the critter
			antPtr->critBreed(boardObj.getBoard(), boardObj.getRows() - 1, boardObj.getCols() - 1);
                       
		}
         }
      }
    }
		//reset all of the critters so that they have not just moved

    for (int i = 0; i < boardObj.getRows(); i++)
    {
	for (int j = 0; j < boardObj.getCols(); j++)
	{
		//get a pointer to the current critter on the board
			
		Critter* antOrDoodleBugPtr = (boardObj.getBoard()[i][j]);

		//if not null it must point to an ant or a doodlebug
		if (antOrDoodleBugPtr != NULL)
		{
	 	      	antOrDoodleBugPtr->setJustMoved(false);
		}
	}
    }
        
      boardObj.printBoard();

    }

    boardObj.deleteBoard();

}


