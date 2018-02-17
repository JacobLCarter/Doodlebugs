#ifndef CRITTER_HPP
#define CRITTER_HPP

class Critter
{
public:
	int getColPosition();
	void setColPosition(int);
	
	int getRowPosition();
	void setRowPosition(int);
	
	int getCritAge();
	void setCritAge(int);

	char getCritType();
	void setCritType(char);

    bool getJustMoved();
    void setJustMoved(bool);

	bool getLastEaten();
    void setLastEaten(int);

    virtual void critMove(Critter***) = 0;
	virtual void critBreed(Critter***) = 0;
protected:
	int colPosition;
	int rowPosition;
	int critAge;
	char critType;
    bool justMoved;
    bool lastEaten;
};
#endif
