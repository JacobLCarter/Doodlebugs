#ifndef CRITTER_HPP
#define CRITTER_HPP

class Critter
{
public:
	Critter();
	~Critter();
	int getColPosition();
	void setColPosition(int);
	
	int getRowPosition();
	void setRowPosition(int);
	
	int getCritAge();
	void setCritAge(int);

	char getCritType();
	void setCritType(char);

private:
	int colPosition;
	int rowPosition;
	int critAge;
	char critType;
};