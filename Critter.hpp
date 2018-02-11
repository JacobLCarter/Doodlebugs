#ifndef CRITTER_HPP
#define CRITTER_HPP

class Critter {
private:
	int colPosition;
	int rowPosition;
	int critAge;
	char critType;
public:
	//Critter();
	//~Critter();
	int getColPosition();
	void setColPosition(int);
	int getRowPosition();
	void setRowPosition(int);
	int getCritAge();
	void setCritAge(int);
	char getCritType();
	void setCritType(char);
	virtual void move(Critter*[], int)=0;
	virtual void breed(Critter*[], int) = 0;
};
#endif
