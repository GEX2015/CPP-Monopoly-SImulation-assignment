#include "PairOfDice.h"
/////////////////////////////////////////////////////////////////////
// File:  PairOfDice.cpp
//
// Author: Ricky Bastarache 
// This assignment represents my own work and is in accordance with the College Academic Policy
//
// Copyright (c) 2016 All Right Reserved by Dave Burchill
// Contributors: 
// Description:  
//
// Date: May 2016
//
// Revisions:
//
/////////////////////////////////////////////////////////////////////
#include  <cstdlib>

PairOfDice::PairOfDice()
{
}


PairOfDice::~PairOfDice()
{
}

//roll 2 dice and gives the total and if they are doubles
int PairOfDice::roll()
{
	int dice1 = rand() % 6 + 1;
	int dice2 = rand() % 6 + 1;
	if (dice1 == dice2)
		_double = true;
	else _double = false;
	int totalOfDice = dice1 + dice2;
	return totalOfDice;
}

bool PairOfDice::isDouble()
{
	if (_double)
		return true;
	return false;
}
