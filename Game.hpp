#ifndef GAME_HPP
#define GAME_HPP

#include "board.hpp"

class Game
{
public:
	void playGame();
	Game();
	Game(int);
    ~Game();
private:
	int turns;
};
#endif
