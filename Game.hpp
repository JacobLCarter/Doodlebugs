#ifndef GAME_HPP
#define GAME_HPP

#include "board.hpp"

class Game
{
    public:
        Game();
        Game(int);
        ~Game();
        void playGame();
    private:
        int turns;
};
#endif
