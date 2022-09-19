#pragma once
#ifndef INPUT_H
#define INPUT_H

#include <iostream>
using namespace std;

//PreCondition: spaces (boolean true or false)
//PostCondition: returns a string including space character(s) or without space character 
string inputString(string prompt, bool spaces);

//PreCondition: valid string of options
//PostCondition: returns an uppercase  of the option (char)
char inputChar(string prompt, string options);

//PreCondition: valid yes (char) or no (char)
//PostCondition: returns an uppercase  yes (char) or no (char) 
char inputChar(string prompt, char yes, char no);

//PreCondition: alphaOrDigit (boolean true or false)
//PostCondition: returns an alphabet or a digit character
char inputChar(string prompt, bool alphaOrDigit);

//PreCondition: NA
//PostCondition: returns any character
char inputChar(string prompt);

//PreCondition: NA
//PostCondition: returns any integer value
int inputInteger(string prompt);

//PreCondition: posNeg (boolean true or false)
//PostCondition: returns a positive integer value (posNeg = true) or a negative integer value (poseNeg = false)
int inputInteger(string prompt, bool posNeg);

//PreCondition: start (integer) and greater (boolean true or false)
//PostCondition: returns an integer value greater than start or lesser than start
int inputInteger(string prompt, int start, bool greater);

//PreCondition: startRange (integer) and endRange (integer)
//PostCondition: returns an integer value within range (startRannge and endRange)
int inputInteger(string prompt, int startRange, int endRange);

//PreCondition: NA
//PostCondition: returns any double value
double inputDouble(string prompt);

//PreCondition: posNeg (boolean true or false)
//PostCondition: returns a positive double value (posNeg = true) or a negative double value (poseNeg = false)
double inputDouble(string prompt, bool posNeg);

//PreCondition: start(integer) and greater(boolean true or false)
//PostCondition: returns an integer value greater than start or lesser than start
double inputDouble(string prompt, double start, bool posNeg);

//PreCondition: startRange (integer) and endRange (integer)
//PostCondition: returns an integer value within range (startRannge and endRange)
double inputDouble(string prompt, double startRange, double endRange);

//PreCondition: startRange (integer) and endRange (integer)
//PostCondition: returns an integer value from an interval of characters
int convertCharToInt(string cstring, int startRange, int endRange);

//PreCondition: current (boolean true or false)
//PostCondition: returns a string with a date from a C-string
string inputDate(string prompt, bool current);



#endif //!INPUT_H