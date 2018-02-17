/*******************************************************************************
 * Name: Utils
 * Description: A set of utilities for checking user input and printing menus
 ******************************************************************************/

#include "utils.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

/***********************************************************************
 * Name: getString
 * Description: Promts the user to input a std::string 
 **********************************************************************/
std::string getString()
{
    std::string input;
   
    std::cout << "Enter a string: ";

    //remprompt if input is empty std::string
    while (input == "")
    {
        std::cout << "Empty string -- enter at least one character: "
            << std::endl;
        std::getline(std::cin, input);
    }
    
    return input;
}

/***********************************************************************
 * Name: getInt 
 * Description: Prompts the user to input an int and validates it
 **********************************************************************/
int getInt(bool prompt)
{
    std::string input;

    //causes the function to output a generic prompt
    if (prompt == true)
    {
        std::cout << "Enter an integer: ";
    }

    //get the users input
    std::getline(std::cin, input);

    //reprompt if the input is blank or not made up of int values 
    while (input.find_first_not_of("0123456789-") != std::string::npos ||
            input == "")
    {
        std::cout << "Not an integer -- please enter an int: " 
            << std::endl;
        std::getline(std::cin, input);
    }
       
    //convert the input to an integer
    int i = std::atoi(input.c_str());
    
    return i;
}

/***********************************************************************
 * Name: getDouble
 * Description: Prompts the user to input a double and validates it
 **********************************************************************/
double getDouble()
{
    std::string input;
  
    std::cout << "Enter a double :";
    std::getline(std::cin, input);

    while (input.find_first_not_of("0123456789.-") != std::string::npos ||
            input == "")
    {
        std::cout << "Not a double -- enter a double: " << std::endl;
        std::getline(std::cin, input);
    }
        
    double d = std::atof(input.c_str());
    
    return d;
}

/************************************************************************
 * Name: getChar
 * Description: Prompts the user for a char and validates it 
 ***********************************************************************/
char getChar()
{
    
    std::string input;
  
    std::getline(std::cin, input);

    while (input.length() == 0 || input.length() > 1 || !std::isalpha(input[0]))
    {
        std::cout << "Not a single alpha character -- enter another char" 
            << std::endl;
        std::getline(std::cin, input);
    }
    input[0] = toupper(input[0]);

    return input[0];
}

/************************************************************************
 * Name: setRange
 * Description: used to limit user input to a specific range
 ***********************************************************************/
int setRange(int size, int lowerRange, int upperRange)
{
    int status = -1;

    //if the input is within the desired range and 0 is
    //allowed, set status to 0
    if (size >= lowerRange && size <= upperRange)
    {
        status = 0;
    }

    return status;
}


/************************************************************************
 * Name: fillArray
 * Description: Fills an array with integers specified by the user
 ***********************************************************************/
void fillArray(int *array, int s)
{
    for (int i = 0; i < s; i++)
    {
        std::cout << "Enter an integer for element " << i+1 << std::endl;
        array[i] = getInt(false);
    }
}

/*************************************************************************
 * Name: mainMenu
 * Description: Prints the main  menu to the screen, allows the user to make
 * one of the choices listed, and returns the choice to main.
 ************************************************************************/
int mainMenu()
{
    int choice;
    std::string mainPrompt = "Enter the number of your selection ";
    
    do
    {
        std::cout << std::endl;
        std::cout << std::string(mainPrompt.length(), '-') << std::endl;
        std::cout << mainPrompt << std::endl << std::endl;
        std::cout << "1. Play Simulation" << std::endl;
        std::cout << "2. Exit" << std::endl;
        std::cout << std::string(mainPrompt.length(), '-')
            << std::endl << std::endl;
        std::cout << "Please enter a choice 1-2: ";
        
        choice = getInt(false);

        std::cout << std::endl;
    }
    while (setRange(choice, 1, 2) != 0);

    return choice;
}

/*************************************************************************
 * Name: replay
 * Description: Prompts the user for a replay 
 ************************************************************************/
char replay()
{
    char choice;

    do
    {
        std::cout << std::endl;
        std::cout << "Would you like to play again? (y/n)" << std::endl;
        choice = getChar();
    }
    while (choice != 'Y' && choice != 'N');

    return choice;
}

/*************************************************************************
 * Name: selectionYN
 * Description: Allows the user to enter 'y' or 'n' for choicek 
 ************************************************************************/
char selectionYN()
{
    char choice;

    do
    {
        std::cout << std::endl;
        std::cout << "Please enter yes or no? (y/n)" << std::endl;
        choice = getChar();
    }
    while (choice != 'Y' && choice != 'N');

    return choice;
}
