#ifndef GAME_HPP
#define GAME_HPP
class Game
{
public:
	void playGame();
	Game();
	Game(int);

private:
	int turns;
	int currentTurns;
};

#endif