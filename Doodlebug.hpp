#ifndef DOODLEBUG_HPP
#define DOODLEBUG_HPP

#include "Critter.hpp"

class Doodlebug : public Critter 
{
public:
	Doodlebug();
	Doodlebug(int, int);
	~Doodlebug();
	virtual void critMove(Critter***);
	virtual void critBreed(Critter***);
    bool getLastEaten();
    void setLastEaten(int);
private:
    bool lastEaten;
};
#endif
