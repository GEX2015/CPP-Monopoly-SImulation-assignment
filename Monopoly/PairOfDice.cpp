///////////////////////////////////////////////////////////////////////
// File:  Monopoly Simulation
//
// Author: Michael Landry
// This assignment represents my own work and is in accordance with the College Academic Policy
//
// Copyright (c) 2016 All Right Reserved by Michael Landry
// Contributors: 
// Description:  This simulation is a 1,000,000 dice role on monopoly to calculate the % of landing on each place
// chance and community chest card are there and could move the player to a new place
//
// Date: june 3 2016
// Revisions:
//
/////////////////////////////////////////////////////////////////////


#include "PairOfDice.h"
#include <time.h>
#include <stdlib.h>



PairOfDice::PairOfDice()
{
	srand(unsigned(time(NULL)));
}


PairOfDice::~PairOfDice()
{
}


// roll 2 dice 
int PairOfDice::roll()
{
	// roll two differente dice
	int dice1 = rand() % 6 + 1;
	int dice2 = rand() % 6 + 1;

	// if the 2 dice are equal set _double to true.
	if (dice1 == dice2)
		_double = true;
	else
		_double = false;

	int total = dice1 + dice2;
	// return the total of the two dice
	return total;
}

// return _double true or false
bool PairOfDice::isDouble()
{
	return _double;
}
