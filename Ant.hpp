
#ifndef ANT_HPP
#define ANT_HPP

#include "Critter.hpp"

class Ant : public Critter 
{
private:
public:
	Ant();
	Ant(int, int);
	~Ant();
	virtual void critMove(Critter*[], int );
	virtual void critBreed(Critter*[], int );
};
#endif