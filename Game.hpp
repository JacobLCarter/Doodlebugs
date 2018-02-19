#ifndef GAME_HPP
#define GAME_HPP
#indlude<board.hpp>

class Game
{
public:
	void playGame();
	Game();
	Game(int);

private:
	int turns;
};

#endif