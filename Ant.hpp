#ifndef ANT_HPP
#define ANT_HPP

#include "Critter.hpp"

class Ant : public Critter 
{
public:
	Ant();
	Ant(int, int);
	~Ant();
	virtual void critMove(Critter*** );
	virtual void critBreed(Critter***);

private:

};
#endif