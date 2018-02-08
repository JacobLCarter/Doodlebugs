#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
using std::string;

string getString();
int getInt();
double getDouble();
char getChar();
int setRange(int size, int lowerRange, int upperRange);
void fillArray(int*, int); 
int mainMenu();
int charSelection(int);
char replay();

#endif
