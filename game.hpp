#ifndef GAME_HPP
#define GAME_HPP

#include "board.hpp"
#include "utils.hpp"

class Game
{
    public:
        void playRound(Board***);
        Game();
        Game(int);
        ~Game();
    private:
        int turns;
        int currentTurn;
};
#endif

