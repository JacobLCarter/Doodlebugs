
#include "Ant.hpp"
#include <cmath>
#include <stdlib.h>

Ant::Ant() {			//constuctor to place Ants in random locations on 20 by 20 grid, replace 20 with number of rows/columns
	setCritType('O');	// when determined(variable if user defined grid size)
	setColPosition(rand() % 20 + 1);
	setRowPosition(rand() % 20 + 1);
	setCritAge(0);
}

Ant::Ant(int row, int col) {
	setCritType('O');
	setRowPosition(row);
	setColPosition(col);
	setCritAge(0);
}

Ant::~Ant() {
}

void Ant::critMove(Critter* board1[], int size) {
	int direction = rand() % 4 + 1;
	switch (direction) {
	case 1:
		if ((this->getRowPosition() - 1) < 0) { //check if move would put critter in negative space of grid 
			break;
		}
		for (int i = 0; i < size; i++) {		//up, size is the size of the array, insert zero check ie no move off grid
			if (board1[i] == NULL) {
				i++;
			}
			else if (board1[i]->getRowPosition() == (this->getRowPosition() - 1) && board1[i]->getColPosition() == this->getColPosition()) { //Check if a critter occupies the move space
				break;
			}
		}
		this->setRowPosition(this->getRowPosition() - 1);	// if not occupied move ant
		break;

	case 2:
		if ((this->getColPosition() + 1) > (sqrt(size))) {	//check to see if ant goes out of bounds, only works with square grid size
			break;
		}
		for (int i = 0; i < size; i++) {		//right, 
			if (board1[i] == NULL) {
				i++;
			}
			else if (board1[i]->getRowPosition() == this->getRowPosition() && board1[i]->getColPosition() == (this->getColPosition() + 1)) {
				break;
			}
		}
		this->setColPosition(this->getColPosition() + 1);
		break;

	case 3:
		if ((this->getRowPosition() + 1) > (sqrt(size))) { //check to see if ant goes out of bounds, only works with square grid size
			break;
		}
		for (int i = 0; i < size; i++) {		//down
			if (board1[i] == NULL) {
				i++;
			}
			else if (board1[i]->getRowPosition() == (this->getRowPosition() + 1) && board1[i]->getColPosition() == this->getColPosition()) {
				break;
			}
		}
		this->setRowPosition(this->getRowPosition() + 1);
		break;

	case 4:
		if ((this->getColPosition() - 1) < 0) { //check if move would put critter in negative space of grid
			break;
		}
		for (int i = 0; i < size; i++) {		//left, 
		if (board1[i] == NULL) {
			i++;
		}
		else if (board1[i]->getRowPosition() == this->getRowPosition() && board1[i]->getColPosition() == (this->getColPosition() - 1)) {
			break;
		}
	}
		this->setColPosition(this->getColPosition() - 1);
		break;
	
	}
	this->setCritAge(getCritAge() + 1);
}

void Ant::critBreed(Critter* board1[], int size) {
	if (this->getCritAge() == 3) {


		int dirArry[] = { 1, 1, 1, 1 };		//array to track if directions are available to insert ants

		if ((this->getRowPosition() - 1) < 0) { //up, check if move would put critter in negative space of grid 
			dirArry[0] = 0;
		}
		if ((this->getColPosition() + 1) > (sqrt(size))) {	// right, check to see if ant goes out of bounds, only works with square grid size
			dirArry[1] = 0;
		}
		if ((this->getRowPosition() + 1) > (sqrt(size))) { //down, check to see if ant goes out of bounds, only works with square grid size
			dirArry[2] = 0;
		}
		if ((this->getColPosition() - 1) < 0) { //left, check if move would put critter in negative space of grid
			dirArry[3] = 0;
		}
		for (int i = 0; i < size; i++) {		//up, size is the size of the array, insert zero check ie no move off grid
			if (board1[i] == NULL) {
				i++;
			}
			else if (board1[i]->getRowPosition() == (this->getRowPosition() - 1) && board1[i]->getColPosition() == this->getColPosition()) { //up,
				dirArry[0] = 0;																				//Check if a critter occupies the breed space
			}
			else if (board1[i]->getRowPosition() == this->getRowPosition() && board1[i]->getColPosition() == (this->getColPosition() + 1)) { //right
				dirArry[1] = 0;
			}
			else if (board1[i]->getRowPosition() == (this->getRowPosition() + 1) && board1[i]->getColPosition() == this->getColPosition()) { //down
				dirArry[2] = 0;
			}
			else if (board1[i]->getRowPosition() == this->getRowPosition() && board1[i]->getColPosition() == (this->getColPosition() - 1)) { //left
				dirArry[3] = 0;
			}
		}
		
		bool noAntBreed = true;
		int count = 0;
		while (noAntBreed || count < 4) {	//check if there is any direction that an ant can breed
			if (dirArry[count] != 0) {
				noAntBreed = true;
				break;
			}
			else {
				noAntBreed = false;
			}
			count++;
		}
		int direction = rand() % 4 + 1;
		while (noAntBreed) {		// loop randomly until the ant breeds
			
			if (direction == 1 && dirArry[0] == 1) {
				for (int i = 0; i < size; i++) {		//find NULL pointer to convert to Ant
					if (board1[i] == NULL) {
						board1[i] = new Ant(this->getRowPosition() - 1, this->getColPosition());
						noAntBreed = false;
						break;
					}
				}
			}
			else if (direction == 2 && dirArry[1] == 1) {
				for (int i = 0; i < size; i++) {
					if (board1[i] == NULL) {
						board1[i] = new Ant(this->getRowPosition(), this->getColPosition() + 1);
						noAntBreed = false;
						break;
					}
				}
			}
			else if (direction == 3 && dirArry[2] == 1) {
				for (int i = 0; i < size; i++) {
					if (board1[i] == NULL) {
						board1[i] = new Ant(this->getRowPosition() + 1, this->getColPosition());
						noAntBreed = false;
						break;
					}
				}
			}
			else if (direction == 4 && dirArry[3] == 1) {
				for (int i = 0; i < size; i++) {
					if (board1[i] == NULL) {
						board1[i] = new Ant(this->getRowPosition(), this->getColPosition() - 1);
						noAntBreed = false;
						break;
					}
				}
			}
		
		}
	}
	this->setCritAge(0);
}
 
