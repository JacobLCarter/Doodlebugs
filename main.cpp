/*******************************************************************************
 * Program Name: main.cpp 
 * Author: Matt Dienhart
 * Date: 2/10/2018
 * Description: (Group Project) This is the main client code for the predator
 * and prey simulation.
 ******************************************************************************/

#include "game.hpp"
#include <iostream>
#include <string>

int main()
{
   //control variables
   int menuSelect = 0;

   //display welcome screen
   std::cout << "---------------------------------------------------" << std::endl;
   std::cout << "|    Welcome to the predator-prey simulation!     |" << std::endl;
   std::cout << "|                                                 |" << std::endl;
   std::cout << "|  CS 162, Group 7                    2.18.2018   |" << std::endl;
   std::cout << "---------------------------------------------------" << std::endl;

   //select start simulation or quit
   std::cout << " 1. Play Simulation    2. Quit " << std::endl;
   
   //get input from user
   std::cin >> menuSelect;

   //loop until valid input is given
   while (std::cin.fail() || menuSelect < 1 || menuSelect > 2) {
      std::cout << "Invalid entry, please try again." << std::endl;
      std::cin.clear();
      std::cin.ignore(999, '\n');
      std::cin >> menuSelect;
   }

   //clear input buffer
   std::cin.ignore(999, '\n');

   //loop as long as user wants to keep starting new simulations
   while(menuSelect == 1) {
      //start a new simulation
      Game newGame;
      newGame.playRound();

      //ask if user wants to play again
      std::cout << "Would you like to run another simulation?" << std::endl;
      std::cout << " 1. Play Again      2. Quit  " << std::endl;
      std::cin >> menuSelect;

      //loop until valid input is given
      while (std::cin.fail() || menuSelect < 1 || menuSelect > 2) {
         std::cout << "Invalid entry, please try again." << std::endl;
         std::cin.clear();
         std::cin.ignore(999, '\n');
         std::cin >> menuSelect;
      }

      //clear input buffer
      std::cin.ignore(999, '\n');
   }

   return 0;
}
