#ifndef DOODLEBUG_HPP
#define DOODLEBUG_HPP

#include "Critter.hpp"

class Doodlebug : public Critter 
{
public:
	Doodlebug();
	Doodlebug(int, int);
	~Doodlebug();
	virtual void critMove(Critter***, int, int);
	virtual void critBreed(Critter***, int, int);
};
#endif
