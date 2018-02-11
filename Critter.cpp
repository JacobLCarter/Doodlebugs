#include "Critter.hpp"



int Critter::getColPosition() {
	return colPosition;
}
void Critter::setColPosition(int col) {
	colPosition = col;
}

int Critter::getRowPosition() {
	return rowPosition;
}
void Critter::setRowPosition(int row) {
	rowPosition = row;
}

int Critter::getCritAge() {
	return critAge;
}
void Critter::setCritAge(int age) {
	critAge = age;
}

char Critter::getCritType() {
	return critType;
}
void Critter::setCritType(char type) {
	critType = type;
}

