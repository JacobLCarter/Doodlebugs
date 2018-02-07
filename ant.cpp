#include "ant.hpp"

Ant::Ant()
{
	setCritType('O');
}

Ant::~Ant()
{
}

void Ant::antMove() {
	int direction = rand() % 4 + 1;
	switch (direction) {
	case 1: if (board->getSpace(getRowPosition--, getColPosition) == ' ') {		//up
		setRowPosition(getRowPosition() - 1);
	}
			break;
	case 2: if (board->getSpace(getRowPosition, getColPosition++) == ' ') {		//right
		setColPosition(getColPosition() + 1);
	}
	case 3: if (board->getSpace(getRowPosition++, getColPosition) == ' ') {		//down
		setRowPosition(getRowPosition() + 1);
	}
			break;
	case 4: if (board->getSpace(getRowPosition, getColPosition--) == ' ') {		//left
		setColPosition(getColPosition() - 1);
	}
			break;
	}
	setCritAge(getCritAge() + 1);
}

