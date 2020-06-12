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


#pragma once
class PairOfDice
{
public:
	PairOfDice();
	~PairOfDice();

	int roll();
	bool isDouble();

private:
	bool _double;
};

