// TowerOfHanoi Class
#pragma once
#ifndef TOWEROFHANOI_H
#define TOWEROFHANOI_H

#include <string>
#include "input.h"
#include "Peg.h"

using namespace std;

class TowerOfHanoi : public Peg
{
private:

	static const int MAX_PEG = 3;
	Peg peg[MAX_PEG];

	int startPeg;
	int endPeg;
	int numMoves;
	int maxRings;

public:
	// Constructor
	TowerOfHanoi(int max);

	// Accessors
	int getNumMoves() const
	{
		return numMoves;
	}

	// Main Process
	void mainProcess();

	// Precondition: pegNumber is 1, 2, 3
	// Postcondition: The return value is the number of rings on the specified peg
	int manyRings(int pegNumber) const;

	// Precondition: pegNumber is 1, 2, 3
	// Postcondition: If manyRings(pegNumber) > 0, then the return value is the diameter of the 
	//                top ring on the specified peg; otherwhise the return value us zero
	int topDiameter(int pegNumber) const;

	// Precondition: startPeg is a peg number (1, 2, or 3), and manyRings(startPeg) > 0;
	//				 endPeg is a different peg number (not equal to startPeg),
	//				 and topDiameter(endPeg) is either 0 or more than topDiameter(startPeg)
	// Postcondition: The top ring has been moved from startPeg to endPeg
	void move(int startPeg, int endPeg);
	void displayTowers();
};


#endif // !TOWEROFHANOI_H

