///////////////////////////////////////////////////////////////////////
// File: PairOfDice.h
// Author: Robert Carll
// This assignment represents my own work and is in accordance with the College Academic Policy
// Copyright (c) 2015 All Right Reserved by Robert Carll
// Contributors:
// Description:
// Date: June 2016
// Revisions:
//////////////////////////////////////////////////////////////////////

#pragma once
#include <ctime>
#include <cstdlib>

class PairOfDice
{
public:
	PairOfDice();
	~PairOfDice();

	int roll(); // rolls two dice and increments double count if it is a double
	bool isDouble(); // return true if double
	int getDoubleCount(); // returns the doublecount
	void resetDoubleCount(); // resets the double count

private:
	bool _double;
	int _doubleCount = 0;
};

