#include "game.hpp"

Game::Game()
    : turns(0), currentTurn(0)
{
}

Game::Game(int numTurns)
    : turns(numTurns), currentTurn(0)
{
}

Game::~Game()
{
}

void Game::playRound(Board ***b)
{

}
