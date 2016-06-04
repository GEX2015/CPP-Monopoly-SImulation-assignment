///////////////////////////////////////////////////////////////////////
// File: PairOfDice.cpp
// Author: Robert Carll
// This assignment represents my own work and is in accordance with the College Academic Policy
// Copyright (c) 2015 All Right Reserved by Robert Carll
// Contributors:
// Description:
// Date: June 2016
// Revisions:
//////////////////////////////////////////////////////////////////////

#include "PairOfDice.h"

PairOfDice::PairOfDice()
{
}

PairOfDice::~PairOfDice()
{
}

int PairOfDice::roll() // rolls two dice and increments double count if it is a double
{
	int roll1 = rand() % 6 + 1;
	int roll2 = rand() % 6 + 1;
	if (roll1 == roll2) {
		_doubleCount++;
		_double = true;
	}
	return roll1 + roll2;
}

bool PairOfDice::isDouble() // return true if double
{
	_doubleCount++;
	return _double;
}

int PairOfDice::getDoubleCount() { // returns the doublecount
	return _doubleCount;
}

void PairOfDice::resetDoubleCount() // resets the double count
{
	_doubleCount = 0;
}
