#include "Critter.hpp"

Critter::~Critter()
{
}

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

bool Critter::getJustMoved() {
    return justMoved;
}

void Critter::setJustMoved(bool move) {
    justMoved = move;
}

int Critter::getLastEaten()
{
    return lastEaten;
}

void Critter::setLastEaten(int days)
{
    lastEaten = days;
}

