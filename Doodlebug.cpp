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

void Doodlebug::critMove(Critter*** boardPtr) {
	int direction = rand() % 4 + 1;
	switch (direction) {
	case 1: if (boardPtr[this->getRowPosition()-1][this->getColPosition()] == NULL) {		//up
		boardPtr[this->getRowPosition() - 1][this->getColPosition()] = this;			//move doodlebug in the array
		boardPtr[this->getRowPosition()][this->getColPosition()] = NULL;				//set old position to null
		this->setRowPosition(this->getRowPosition() - 1);								//change position in doodlebug object
	}
			break;
	case 2: if (boardPtr[this->getRowPosition()][this->getColPosition()+1] == NULL) {		//right
		boardPtr[this->getRowPosition()][this->getColPosition() + 1] = this;
		boardPtr[this->getRowPosition()][this->getColPosition()] = NULL;
		this->setColPosition(this->getColPosition() + 1);
	}
			break;
	case 3: if (boardPtr[this->getRowPosition()+1][this->getColPosition()] == NULL) {		//down
		boardPtr[this->getRowPosition() + 1][this->getColPosition()] = this;
		boardPtr[this->getRowPosition()][this->getColPosition()] = NULL;
		this->setRowPosition(this->getRowPosition() + 1);
	}
			break;
	case 4: if (boardPtr[this->getRowPosition()][this->getColPosition()-1] == NULL) {		//left
		boardPtr[this->getRowPosition()][this->getColPosition() + 1] = this;
		boardPtr[this->getRowPosition()][this->getColPosition()] = NULL;
		this->setColPosition(this->getColPosition() - 1);
	}
			break;
	}
	this->setCritAge(getCritAge() + 1);
}

void Doodlebug::critBreed(Critter*** boardPtr) {
	if (this->getCritAge() >= 8) {	

		bool doodlebugBreed = true;				//Bool to check loop conditions
		int randArr[] = { 0, 0, 0, 0 };		//Array to track if all available directions have been checked for breeding
		while (doodlebugBreed) {
			int direction = rand() % 4 + 1;
			switch (direction) {	
			case 1: if (boardPtr[this->getRowPosition() - 1][this->getColPosition()] == NULL) {		//up
				boardPtr[this->getRowPosition() - 1][this->getColPosition()] = new Doodlebug((this->getRowPosition() - 1), this->getColPosition());
				doodlebugBreed = false;
			}
					randArr[0] = 1;
					break;
			case 2: if (boardPtr[this->getRowPosition()][this->getColPosition() + 1] == NULL) {		//right
				boardPtr[this->getRowPosition()][this->getColPosition() + 1] = new Doodlebug(this->getRowPosition(), (this->getColPosition() + 1));
				doodlebugBreed = false;
			}
					randArr[1] = 1;
					break;
			case 3: if (boardPtr[this->getRowPosition() + 1][this->getColPosition()] == NULL) {		//down
				boardPtr[this->getRowPosition() + 1][this->getColPosition()] = new Doodlebug((this->getRowPosition() + 1), this->getColPosition());
				doodlebugBreed = false;
			}
					randArr[2] = 1;
					break;
			case 4: if (boardPtr[this->getRowPosition()][this->getColPosition() - 1] == NULL) {		//left
				boardPtr[this->getRowPosition()][(this->getColPosition() - 1)] = new Doodlebug(this->getRowPosition(), (this->getColPosition() - 1));
				doodlebugBreed = false;
			}
					randArr[3] = 1;
					break;
			}
			int count = 0;
			while (count < 5) {				//loop to check if direction has been looped through
				if (randArr[count] == 0) {
					doodlebugBreed = true;
					break;
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
