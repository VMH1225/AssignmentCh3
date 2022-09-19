// Rings class
#pragma once
#ifndef PEG_H
#define PEG_H

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Peg
{
private:
    int* ringDiameter;  // Pointer to the stack array
    int pegSize;        // The stack size
    int top;            // Indicates the top of the stack
public:
    // Default Constructor
    Peg()
    {
        ringDiameter = new int[64];
        pegSize = 64;
        top = -1;
    }
    // Constructor
    Peg(int size);

    //Destructor
    ~Peg();

    // Stack operations    
    void push(int element);             // Pushes the element onto the stack
    void pop(int& element);             // Pops the element at the top of the stack off
    bool isFull() const;                // Return true if the array is full or false otherwise
    bool isEmpty() const;               // Return true if the array is empty or false otherwise
    int getElement(int index) const;    // Get an specific element in the array
    int getTop() const;                 // Get the top element in the array
    int getNumRings() const;

    void printArray(int max, int n);    // Display the values in the array. 

};
#endif // !PEG_H
