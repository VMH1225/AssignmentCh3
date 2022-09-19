#include "Peg.h"

// Constructor
Peg::Peg(int size)
{
    ringDiameter = new int[size];
    pegSize = size;
    top = -1;
}

//Destructor
Peg::~Peg()
{
    delete[] ringDiameter;
}

// Pushes the element onto the stack
void Peg::push(int element)
{
    if (isFull())
    {
        cout << "ERROR: Cannot push an element. Stack is full.\n";
    }
    else
    {
        top++;
        ringDiameter[top] = element;
    }
}

// Pops the element at the top of the stack off
void Peg::pop(int& element)
{
    if (isEmpty())
    {
        cout << "ERROR: Cannot pop an element. Stack is empty.\n";
    }
    else // Pop value off top of stack
    {
        element = ringDiameter[top];
        top--;
    }
}

// Return true if the array is full or false otherwise
bool Peg::isFull() const
{
    bool status;
    if (top == pegSize - 1)
        status = true;
    else
        status = false;

    return status;
}

// Return true if the array is empty or false otherwise
bool Peg::isEmpty() const
{
    bool status;
    if (top == -1)
        status = true;
    else
        status = false;

    return status;
}

// Display the values in the array. 
void Peg::printArray(int max, int numPeg)
{
    cout << "\tPeg #" << numPeg << ":\n";
    for (int i = max + 1; i >= 0; i--)
    {
        if (i == max + 1)
        {
            cout << '\t' << setw(10) << "    |    " << endl;
        }
        else if (i < 1)
        {
            cout << '\t' << setw(10) << "=========" << endl;
        }
        else
        {
            if (getNumRings() > 0 && i - 1 <= top)
                cout << '\t' << setw(10) << "    " + to_string(getElement(i - 1)) + "    " << endl;
            else
                cout << '\t' << setw(10) << "    |    " << endl;
        }
    }
    /*cout << "\tThese values are in the Peg:\n\t";
    for (int i = pegSize; i >= 0; i--)
        if (i <= top)
            cout << ringDiameter[i] << " ";
    cout << endl;*/
}

// Get an specific element in the array
int Peg::getElement(int index) const
{
    return ringDiameter[index];
}

// Get the top element in the array
int Peg::getTop() const
{
    if (isEmpty())
        return 0;

    return ringDiameter[top];

}
// Get the number of rings in peg
int Peg::getNumRings() const
{
    if (isEmpty())
        return 0;

    return top + 1;
}