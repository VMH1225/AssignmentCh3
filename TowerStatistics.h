#pragma once
#ifndef TOWERSTATISTICS_H
#define TOWERSTATISTICS_H

class TowerStatistics
{
private:
	int gameID;
	int numRingsUsed;
	int movesMade;
	int time;
public:
	// Default Constructor
	TowerStatistics() : gameID(0), numRingsUsed(0), movesMade(0), time(0) {};

	// Accessors
	int getGameID() const
	{
		return gameID;
	}
	int getNumRingsUsed() const
	{
		return numRingsUsed;
	}
	int getMovesMade() const
	{
		return movesMade;
	}
	int getTime() const
	{
		return time;
	}

	// Mutators
	void setGameID(int id)
	{
		gameID = id;
	}
	void setNumRingsUsed(int numRU)
	{
		numRingsUsed = numRU;
	}
	void setMovesMade(int mm)
	{
		movesMade = mm;
	}
	void setTime(int t)
	{
		time = t;
	}

};

#endif // !TOWERSTATISTICS_H

