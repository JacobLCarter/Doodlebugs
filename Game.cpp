#include "Game.hpp"
//#include"Critter.hpp"

/*constructor takes an integer parameter and sets the
number of times the play game function will loop for. */
Game::Game(int numTurns)
{
	this->turns = numTurns;
}

Game::~Game()
{
}

/*This function implements the game. Note that we may need some additional
functionality in the critter class and its subclasses for this to actully work. 
Please see the comments for details.*/
void Game::playGame()
{
    Board boardObj;

	//for the number of time steps specified by the user, play the game
	for (int index  = 0; index < this->turns; index++)
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
                    /proceed with the calculations. Note:(we need a function that I can get
                    /and set just moved so I dont loop through the same critter on a different
                    /square)  */
                    if (doodleBugPtr->getCritType() == 'X' && !doodleBugPtr->getJustMoved())
                    {
                        //call the critMove() function to make the doodleBug do its thing
                        doodleBugPtr->critMove(boardObj.getBoard());

                        /*Set moved to true so the critter is not selected during the next loop.
                        /This should probably a data member in the critter class with a get and
                        /set method. */
                        doodleBugPtr->setJustMoved(true);

                        /*if the doodleBug is old enough to breed and it has been 8
                         days since breeding. We need a member for timeSinceBreeding in
                         the doodleBug class that is set when a critter moves. */
                        if (doodleBugPtr->getCritAge() % 8 == 0)
                        {
                            doodleBugPtr->critBreed(boardObj.getBoard());
                        }

                        //if the critter has not eaten in 3 time steps it dies (ie nullptr)
                        if (doodleBugPtr->getCritAge() >= 8 && doodleBugPtr->getHasEaten() >= 8) 
                        {
                            boardObj.removeCritter(i, j);
                        }
                    }
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
                        antPtr->critMove(boardObj.getBoard());

                        //set justMoved to true. (Once again, we need this in the critter class)
                        antPtr->setJustMoved(true);

                        //if ant is older that 3 and has not bred in the last 3 days
                        if (antPtr->getCritAge() % 3 == 0)
                        {
                            antPtr->critBreed(boardObj.getBoard());
                        }
                    }
                }
			}

			//reset all of the critters so that they have not just moved
			//(In preperation for the next loop)
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
		}
        boardObj.printBoard();
	}
    
    boardObj.deleteBoard();
}
