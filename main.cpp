// Victor Huerta Alejandro Mamani, Arturo Sanchez, Bryan Soto, and Tien Nguyen
// September 21, 2022
// Chapter 3 Project

#include <iostream>
#include <iomanip>
#include <chrono>

#include "input.h"
#include "Peg.h"
#include "TowerOfHanoi.h"
#include "TowerStatistics.h"
using namespace std;
int menuOption();

int main()
{
	do
	{
		switch (menuOption())
		{
		case 0: exit(1); break;
		case 2:
		{
			cout << "\n\tThe Tower of Hanoi also called the Tower of Brahma or Lucas' Tower is a mathematical game.\n";
			cout << "\tIt consists of three pegs and a number of rings of different sizes, which can slide onto\n";
			cout << "\tany peg. The game starts with the rings in a neat stack in ascending order of size on one\n";
			cout << "\tpeg, the smallest at the top, thus making a conical shape.\n";
			cout << "\n\tThe objective of the game is to move the entire stack from the starting peg-A to ending peg-B,\n";
			cout << "\t obeying the following simple rules:\n";
			cout << "\n\t\t1. Only one disk can be moved at a time.\n";
			cout << "\t\t2. Each move consists of taking the upper disk from one of the stacks and\n";
			cout << "\t\t   placing it on top of another stack or on an empty peg.\n";
			cout << "\t\t3. No larger disk may be placed on top of a smaller disk.\n";
			// games - rings - moves - time
			TowerStatistics statistics[100];
			int gameNumber = 1;
			const int MAX_DISKS = 64;
			do
			{
				statistics[gameNumber].setGameID(gameNumber);
				int maxRings = inputInteger("\n\tEnter the number of rings (1..64) to begin: ", 1, MAX_DISKS);
				statistics[gameNumber].setNumRingsUsed(maxRings);

				TowerOfHanoi towerGame(maxRings);
				chrono::steady_clock::time_point start = chrono::high_resolution_clock::now();          // Get the start time
				towerGame.mainProcess();
				chrono::steady_clock::time_point end = chrono::high_resolution_clock::now();            // Get the end time
				long long elapsedTime = chrono::duration_cast<chrono::seconds>(end - start).count();    // Total time = end time - start time
				statistics[gameNumber].setTime(elapsedTime); // Set time
				statistics[gameNumber].setMovesMade(towerGame.getNumMoves());
				gameNumber++;

			} while (inputChar("\n\tPlay again? (Y-yes or N-no) ", 'Y', 'N') == 'Y');

			system("cls");
			cout << "\n\tGame statistics: \n";
			//cout << gameNumber << "\n";

			for (int i = 0; i < MAX_DISKS; i++)
			{
				int games = 0, fastestID = 0, slowestID = 0;
				double averageT = 0.0;
				//cout << "Games number: " << gameNumber << "\n";


				for (int j = 1; j < gameNumber; j++)
				{
					if (statistics[j].getNumRingsUsed() == i)
					{
						if (fastestID == 0)
						{
							fastestID = statistics[j].getGameID();
						}
						else if (statistics[j].getTime() < statistics[fastestID].getTime())
						{
							fastestID = statistics[j].getGameID();
						}
						if (slowestID == 0)
						{
							slowestID = statistics[j].getGameID();
						}
						else if (statistics[j].getTime() > statistics[slowestID].getTime() && slowestID != 0)
						{
							slowestID = statistics[j].getGameID();
						}

						averageT = ((double)statistics[fastestID].getTime() + (double)statistics[slowestID].getTime()) / 2.0;
						games++;
						//cout << "Games: " << games << "\n";
					}
				}
				//cout << games << "\n";
				if (games != 0)
				{
					cout << "\t" << games << " games using " << i << " disk" << (i == 1 ? "" : "s") << " was played.\n";

					cout << "\t\tThe fastest time was " << statistics[fastestID].getTime() << " seconds in " << statistics[fastestID].getMovesMade() << " moves.\n";
					cout << "\t\tThe slowest time was " << statistics[slowestID].getTime() << " seconds in " << statistics[slowestID].getMovesMade() << " moves.\n";
					cout << setprecision(1) << fixed;
					cout << "\t\tThe average time was " << averageT << " second(s).\n";
				}

			}
		} break;
		break;


		default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
		}
		cout << "\n";
		system("pause");

	} while (true);

	return EXIT_SUCCESS;
}

int menuOption()
{
	system("cls");
	cout << "\nCMPR131 Chapter 3 - Games Applications using Container by Victor Huerta, Alejandro Mamani, Arturo Sanchez, Bryan Soto, and Tien Nguyen 9/21/2022)";
	cout << "\n\t" + string(100, char(205));
	cout << "\n\t\t1> Tic-Tac-Toe";
	cout << "\n\t\t2> Tower of Hanoi";
	cout << "\n\t\t3> n-Queens";
	cout << "\n\t" + string(100, char(196));
	cout << "\n\t\t0> Exit";
	cout << "\n\t" + string(100, char(205));
	cout << "\n";

	int option = inputInteger("\t\t  Option: ", 0, 3);
	system("cls");
	return option;
}
