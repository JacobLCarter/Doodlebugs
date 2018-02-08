#include "utils.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
using std::cout;
using std::cin;
using std::endl;
using std::string;

/***********************************************************************
 * Name: getString
 * Description: Promts the user to input a string 
 **********************************************************************/
string getString()
{
    string input;
    std::getline(cin, input);
    
    return input;
}

/***********************************************************************
 * Name: getInt 
 * Description: Prompts the user to input an int and validates it
 **********************************************************************/
int getInt()
{
    string input;
   
    std::getline(cin, input);

    while (input.find_first_not_of("0123456789") != string::npos || input == "")
    {
        cout << "Not a positive integer -- please enter an int: " << endl;
        std::getline(cin, input);
    }
        
    int i = std::atoi(input.c_str());
    
    return i;
}

/***********************************************************************
 * Name: getDouble
 * Description: Prompts the user to input a double and validates it
 **********************************************************************/
double getDouble()
{
    string input;
   
    std::getline(cin, input);

    while (input.find_first_not_of("0123456789.") != string::npos)
    {
        cout << "Not a positive integer -- enter an int: " << endl;

        if (input.find_first_not_of("0123456789.") == string::npos)
        {
            cin.clear();
            cin.ignore(256, '\n');
        }

        std::getline(cin, input);
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
    
    string input;
   
    std::getline(cin, input);

    while (input.length() == 0 || input.length() > 1 || !std::isalpha(input[0]))
    {
        cout << "Not a single alpha character -- enter another char" << endl;
        std::getline(cin, input);
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
        cout << "Please enter an integer for element " << i+1 << std::endl;
        array[i] = getInt();
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

    //display the menu with a title, choices, and a user prompt
    do
    {
        cout << endl;
        cout << "Fantasy Combat 2018 Main Menu" << endl << endl;
        cout << "1. Character Selection" << endl;
        cout << "2. Exit the Program" << endl << endl;
        cout << "Please enter a choice 1-2: ";
        choice = getInt();
    }
    while (setRange(choice, 1, 2) != 0);

    return choice;
}

int charSelection(int p)
{
    int choice;

    do
    {
        std::cout << std::endl;
        std::cout << "Please select the number corresponding to the "
            << "character you would like to use for player " << p << ": " 
            << std::endl << std::endl;
        std::cout << "1. Vampire" << std::endl;
        std::cout << "2. Barbarian" << std::endl;
        std::cout << "3. Blue Men" << std::endl;
        std::cout << "4. Medusa" << std::endl;
        std::cout << "5. Harry Potter" << std::endl;
        std::cout << "Please enter a choice 1-5: ";
        choice = getInt();
    }
    while (setRange(choice, 1, 5) != 0);

    return choice;
}

char replay()
{
    char choice;

    do
    {
        cout << endl;
        cout << "Would you like to play again? (y/n)" << cout;
        choice = getChar();
    }
    while (choice != 'Y' && choice != 'N');

    return choice;
}









































