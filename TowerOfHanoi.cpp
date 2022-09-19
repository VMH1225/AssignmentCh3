#include "TowerOfHanoi.h"

// Constructor
TowerOfHanoi::TowerOfHanoi(int max) : numMoves(0), startPeg(0), endPeg(0)
{
	maxRings = max;

	for (int i = maxRings; i >= 1; i--)
	{
		peg[0].push(i);
	}
}

// Main Process
void TowerOfHanoi::mainProcess()
{
	do
	{
		cout << "\n\tTower of Hanoi\n";
		displayTowers();

		/*cout << "\tNumber of rings: " << manyRings(1) << '\n';
		cout << "\tNumber of rings: " << manyRings(2) << '\n';
		cout << "\tNumber of rings: " << manyRings(3) << '\n';
		cout << "\tDiameter of topmost ring: " << topDiameter(1) << '\n';
		cout << "\tDiameter of topmost ring: " << topDiameter(2) << '\n';
		cout << "\tDiameter of topmost ring: " << topDiameter(3) << '\n';*/

		startPeg = (int)(inputChar("\n\tSelect the top disk from the start peg (1, 2, 3, or Q to quit): ")) - 48;
		cout << startPeg << endl;
		if (startPeg == 33) {
			break;
		}
		endPeg = (int)(inputChar("\tSelect the end peg (1, 2, 3 or Q-quit) to move the selected disk: ")) - 48;
		move(startPeg, endPeg);
		numMoves++;

		if (peg[2].getNumRings() == maxRings)
		{
			displayTowers();
			cout << "\n\tCongratulation! You have solved the game in " << numMoves << " move" << (numMoves == 1 ? "" : "s") << ".\n";
			break;
		}
	} while (true);


}

// Precondition: pegNumber is 1, 2, 3
// Postcondition: The return value is the number of rings on the specified peg
int TowerOfHanoi::manyRings(int pegNumber) const
{
	return peg[pegNumber - 1].getNumRings();
}

// Precondition: pegNumber is 1, 2, 3
// Postcondition: If manyRings(pegNumber) > 0, then the return value is the diameter of the 
//                top ring on the specified peg; otherwhise the return value us zero
int TowerOfHanoi::topDiameter(int pegNumber) const
{
	return peg[pegNumber - 1].getTop();
}

// Precondition: startPeg is a peg number (1, 2, or 3), and manyRings(startPeg) > 0;
//				 endPeg is a different peg number (not equal to startPeg),
//				 and topDiameter(endPeg) is either 0 or more than topDiameter(startPeg)
// Postcondition: The top ring has been moved from startPeg to endPeg
void TowerOfHanoi::move(int startPeg, int endPeg)
{
	if (startPeg != endPeg)
	{
		if (startPeg == 1 || startPeg == 2 || startPeg == 3)
		{
			// Quit a ring if the endPeg is 33('Q')
			if (endPeg == 33)
			{
				int catchElem; //To hold values popped off the stack
				peg[startPeg - 1].pop(catchElem);
				maxRings--;
				cout << "\n\tTop disk from peg-" << startPeg << " has removed.\n";
			}
			else
			{
				if (manyRings(startPeg) > 0)
				{
					if (topDiameter(endPeg) > topDiameter(startPeg) || topDiameter(endPeg) == 0)
					{
						peg[endPeg - 1].push(topDiameter(startPeg));

						int catchElem; //To hold values popped off the stack
						peg[startPeg - 1].pop(catchElem);

						cout << "\n\tTop disk from peg-" << startPeg << " has moved to peg-" << endPeg << ".\n";
					}
					else
					{
						cout << "\tERROR: Cannot make the move. Top disk (" << topDiameter(startPeg) << ") of peg-" << startPeg;
						cout << ", is larger than top disk(" << topDiameter(endPeg) << ") of peg-" << endPeg << ".\n";
						cout << "\tPlease choose again.\n";
					}
				}
				else
				{
					cout << "\tERROR: Cannot make the move. There is no disk in the selected peg-" << startPeg << ".\n";
					cout << "\t       Please chooser again.\n";
				}
			}
		}
		else
			cout << "\tERROR: Invalid input. Must be '1','2','3', or 'Q'\n";
	}
	else
	{
		cout << "\tERROR: Cannot make the move. The selected end peg cannot be the same as the selected start peg.\n";
		cout << "\t       Please choose again.\n";
	}
}

void TowerOfHanoi::displayTowers()
{
	cout << '\n';
	for (int i = maxRings + 1; i >= 0; i--)
	{
		if (i == maxRings + 1)
		{
			cout << '\t' << setw(10) << "    |    " << setw(10) << "    |    " << setw(10) << "    |    " << endl;
		}
		else if (i < 1)
		{
			cout << '\t' << setw(10) << "=========" << setw(10) << "=========" << setw(10) << "=========" << endl;
			cout << '\t' << setw(10) << "   #1    " << setw(10) << "   #2    " << setw(10) << "   #3    " << endl;
		}
		else
		{
			cout << '\t';
			for (int j = 0; j < MAX_PEG; j++)
			{
				if (peg[j].getNumRings() > 0 && i - 1 <= peg[j].getNumRings() - 1)
					cout << setw(10) << "    " + to_string(peg[j].getElement(i - 1)) + "    ";
				else
					cout << setw(10) << "    |    ";
			}
			cout << endl;
		}
	}
}