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

	int getLastEaten();
    void setLastEaten(int);
    void incrementLastEaten();

    virtual void critMove(Critter***, int, int) = 0;
	virtual void critBreed(Critter***, int, int) = 0;

    virtual ~Critter();
protected:
	int colPosition;
	int rowPosition;
	int critAge;
	char critType;
    bool justMoved;
    int lastEaten;
};
#endif
