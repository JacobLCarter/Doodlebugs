#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>

std::string getString();
int getInt(bool);
double getDouble();
char getChar();
int setRange(int size, int lowerRange, int upperRange);
void fillArray(int*, int); 
int mainMenu();
int charSelection(int);
char replay();

#endif
