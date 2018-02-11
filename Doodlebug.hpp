#ifndef DOODLEBUG_HPP
#define DOODLEBUG_HPP

#include "Critter.hpp"

class Doodlebug : public Critter 
{
private:
public:
	Doodlebug();
	Doodlebug(int, int);
	~Doodlebug();
	virtual void move(Critter*[], int );
	virtual void breed(Critter*[], int );
};
#endif
