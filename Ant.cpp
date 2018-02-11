#include "Ant.hpp"
#include "Test.hpp"
#include <stdlib.h>

Ant::Ant()
{
	
}

Ant::Ant(int row, int col) {
	setCritType('O');
	setRowPosition(row);
	setColPosition(col);
	setCritAge(0);
}

Ant::~Ant()
{
}

void Ant::critMove(Critter*** boardPtr) {
	int direction = rand() % 4 + 1;
	switch (direction) {
	case 1: if (boardPtr[this->getRowPosition()-1][this->getColPosition()] == NULL) {		//up
		this->setRowPosition(this->getRowPosition() - 1);
	}
			break;
	case 2: if (boardPtr[this->getRowPosition()][this->getColPosition()+1] == NULL) {		//right
		this->setColPosition(this->getColPosition() + 1);
	}
			break;
	case 3: if (boardPtr[this->getRowPosition()+1][this->getColPosition()] == NULL) {		//down
		this->setRowPosition(this->getRowPosition() + 1);
	}
			break;
	case 4: if (boardPtr[this->getRowPosition()][this->getColPosition()-1] == NULL) {		//left
		this->setColPosition(this->getColPosition() - 1);
	}
			break;
	}
	this->setCritAge(getCritAge() + 1);
}

void Ant::critBreed(Critter*** boardPtr) {
	if (this->getCritAge() >= 3) {	

		bool antBreed = true;				//Bool to check loop conditions
		int randArr[] = { 0, 0, 0, 0 };		//Array to track if all available directions have been checked for breeding
		while (antBreed) {
			int direction = rand() % 4 + 1;
			switch (direction) {	
			case 1: if (boardPtr[this->getRowPosition() - 1][this->getColPosition()] == NULL) {		//up
				boardPtr[this->getRowPosition() - 1][this->getColPosition()] = new Ant((this->getRowPosition() - 1), this->getColPosition());
				antBreed = false;
			}
					randArr[0] = 1;
					break;
			case 2: if (boardPtr[this->getRowPosition()][this->getColPosition() + 1] == NULL) {		//right
				boardPtr[this->getRowPosition()][this->getColPosition() + 1] = new Ant(this->getRowPosition(), (this->getColPosition() + 1));
				antBreed = false;
			}
					randArr[1] = 1;
					break;
			case 3: if (boardPtr[this->getRowPosition() + 1][this->getColPosition()] == NULL) {		//down
				boardPtr[this->getRowPosition() + 1][this->getColPosition()] = new Ant((this->getRowPosition() + 1), this->getColPosition());
				antBreed = false;
			}
					randArr[2] = 1;
					break;
			case 4: if (boardPtr[this->getRowPosition()][this->getColPosition() - 1] == NULL) {		//left
				boardPtr[this->getRowPosition()][(this->getColPosition() - 1)] = new Ant(this->getRowPosition(), (this->getColPosition() - 1));
				antBreed = false;
			}
					randArr[3] = 1;
					break;
			}
			int count = 0;
			while (count < 5) {				//loop to check if direction has been looped through
				if (randArr[count] == 0) {
					antBreed = true;
					break;
				}
				else {
					antBreed = false;
					count++;
				}

			}
		}
		this->setCritAge(0);
	}
}