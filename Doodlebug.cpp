#include "Doodlebug.hpp"
#include <stdlib.h>

Doodlebug::Doodlebug()
{
	
}

Doodlebug::Doodlebug(int row, int col) {
   setCritType('X');
   setRowPosition(row);
   setColPosition(col);
   setCritAge(0);
   setJustMoved(false);
   setLastEaten(0);
}

Doodlebug::~Doodlebug()
{
}

void Doodlebug::critMove(Critter*** boardPtr, int rowEdge, int colEdge) {
   //check each adjacent space to see if there is an Ant in it
   int adjacentArr[] = {0, 0, 0, 0};
   int numAdjacentAnts = 0;
   if (this->getRowPosition() != 0 && boardPtr[this->getRowPosition()-1][this->getColPosition()]->getCritType() == 'O') {
      adjacentArr[0] = 1;  //there is an ant to the north
      numAdjacentAnts ++;
   }
   if (this->getColPosition() != colEdge && boardPtr[this->getRowPosition()][this->getColPosition()+1]->getCritType() == 'O') {
      adjacentArr[1] = 1;  //there is an ant to the east
      numAdjacentAnts ++;
   }
   if (this->getRowPosition() != rowEdge && boardPtr[this->getRowPosition()+1][this->getColPosition()]->getCritType() == 'O') {
      adjacentArr[2] = 1;  //there is an ant to the south
      numAdjacentAnts ++;
   }
   if (this->getColPosition() != 0 && boardPtr[this->getRowPosition()][this->getColPosition()-1]->getCritType() == 'O') {
      adjacentArr[3] = 1;  //there is an ant to the west
      numAdjacentAnts ++;
   }

   if (numAdjacentAnts > 0) {
      //determine which ant to eat randomly
      bool antSearch = true;
      while (antSearch) {
         int direction = (rand()%4)+1;
         switch (direction) {
         case 1: 
            if (adjacentArr[0] == 1) {
               delete boardPtr[this->getRowPosition()-1][this->getColPosition()]; //destroy the ant
               boardPtr[this->getRowPosition() -1][this->getColPosition()] = this;  //move doodlebug to the ant's position
               boardPtr[this->getRowPosition()][this->getColPosition()] = NULL;  //set old position to null
               this->setRowPosition(this->getRowPosition() -1);  //change position in the doodlebug object
               antSearch = false;
            }
            break;
         case 2:
            if (adjacentArr[1] == 1) {
               delete boardPtr[this->getRowPosition()][this->getColPosition()+1];  //destroy the ant
               boardPtr[this->getRowPosition()][this->getColPosition()+1] = this;  //move to the ant's location
               boardPtr[this->getRowPosition()][this->getColPosition()] = NULL;  //set old position to NULL
               this->setColPosition(this->getColPosition()+1);  //change position in the doodlebug object
               antSearch = false;
            }
            break;
         case 3:
            if (adjacentArr[2] == 1) {
               delete boardPtr[this->getRowPosition()+1][this->getColPosition()];  //destroy the ant
               boardPtr[this->getRowPosition()+1][this->getColPosition()] = this;  //move to the ant's location
               boardPtr[this->getRowPosition()][this->getColPosition()] = NULL;  //set old position to NULL
               this->setRowPosition(this->getRowPosition()+1);  //change position in the doodlebug object
               antSearch = false;
            }
            break;
         case 4:
            if (adjacentArr[3] == 1) {
               delete boardPtr[this->getRowPosition()][this->getColPosition()-1];  //destroy the ant
               boardPtr[this->getRowPosition()][this->getColPosition()-1] = this;  //move to the ant's location
               boardPtr[this->getRowPosition()][this->getColPosition()] = NULL;  //set old position to NULL
               this->setColPosition(this->getColPosition()-1);  //change position in the doodlebug object
               antSearch = false;
            }
            break;
         }
      }
      //reset doodlebug's starvation counter
      this->setLastEaten(0);
   }
   else { 
      //determine which direction to move
      int direction = rand() % 4 + 1;
      switch (direction) {
      case 1: 
         if (this->getRowPosition() != 0 && boardPtr[this->getRowPosition()-1][this->getColPosition()] == NULL) {		//up
            boardPtr[this->getRowPosition() - 1][this->getColPosition()] = this;			//move doodlebug in the array
            boardPtr[this->getRowPosition()][this->getColPosition()] = NULL;			//set old position to null
            this->setRowPosition(this->getRowPosition() - 1);					//change position in doodlebug object
         }
         break;
      case 2: 
         if (this->getColPosition() != colEdge && boardPtr[this->getRowPosition()][this->getColPosition()+1] == NULL) {		//right
            boardPtr[this->getRowPosition()][this->getColPosition() + 1] = this;
            boardPtr[this->getRowPosition()][this->getColPosition()] = NULL;
            this->setColPosition(this->getColPosition() + 1);
         }
         break;
      case 3: 
         if (this->getRowPosition() != rowEdge && boardPtr[this->getRowPosition()+1][this->getColPosition()] == NULL) {		//down
            boardPtr[this->getRowPosition() + 1][this->getColPosition()] = this;
            boardPtr[this->getRowPosition()][this->getColPosition()] = NULL;
            this->setRowPosition(this->getRowPosition() + 1);
         }
         break;
      case 4: 
         if (this->getColPosition() != 0 && boardPtr[this->getRowPosition()][this->getColPosition()-1] == NULL) {		//left
            boardPtr[this->getRowPosition()][this->getColPosition() - 1] = this;
            boardPtr[this->getRowPosition()][this->getColPosition()] = NULL;
            this->setColPosition(this->getColPosition() - 1);
         }
         break;
      }
      this->incrementLastEaten();
   }
   this->setCritAge(getCritAge() + 1);
}

void Doodlebug::critBreed(Critter*** boardPtr, int rowEdge, int colEdge) {
	if (this->getCritAge() >= 8) {	

		bool doodlebugBreed = true;				//Bool to check loop conditions
		int randArr[] = { 0, 0, 0, 0 };		//Array to track if all available directions have been checked for breeding
		while (doodlebugBreed) {
			int direction = rand() % 4 + 1;
			switch (direction) {	
			case 1: if (this->getRowPosition() != 0 && boardPtr[this->getRowPosition() - 1][this->getColPosition()] == NULL) {		//up
				boardPtr[this->getRowPosition() - 1][this->getColPosition()] = new Doodlebug((this->getRowPosition() - 1), this->getColPosition());
				doodlebugBreed = false;
			}
					randArr[0] = 1;
					break;
			case 2: if (this->getColPosition() != colEdge && boardPtr[this->getRowPosition()][this->getColPosition() + 1] == NULL) {		//right
				boardPtr[this->getRowPosition()][this->getColPosition() + 1] = new Doodlebug(this->getRowPosition(), (this->getColPosition() + 1));
				doodlebugBreed = false;
			}
					randArr[1] = 1;
					break;
			case 3: if (this->getRowPosition() != rowEdge && boardPtr[this->getRowPosition() + 1][this->getColPosition()] == NULL) {		//down
				boardPtr[this->getRowPosition() + 1][this->getColPosition()] = new Doodlebug((this->getRowPosition() + 1), this->getColPosition());
				doodlebugBreed = false;
			}
					randArr[2] = 1;
					break;
			case 4: if (this->getColPosition() != 0 && boardPtr[this->getRowPosition()][this->getColPosition() - 1] == NULL) {		//left
				boardPtr[this->getRowPosition()][(this->getColPosition() - 1)] = new Doodlebug(this->getRowPosition(), (this->getColPosition() - 1));
				doodlebugBreed = false;
			}
					randArr[3] = 1;
					break;
			}
			int count = 0;
			while (count < 4) {				//loop to check if direction has been looped through
				if (randArr[count] == 0) {
					doodlebugBreed = true;
					count++;
				}
				else {
					doodlebugBreed = false;
					count++;
				}

			}
		}
		this->setCritAge(0);
	}
}
