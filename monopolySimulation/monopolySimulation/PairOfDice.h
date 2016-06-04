/////////////////////////////////////////////////////////////////////
// File:  PairOfDice.h
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
#pragma once
class PairOfDice
{
public:
	PairOfDice();
	~PairOfDice();
	int roll();//rolls 2 dice
	bool isDouble();// returns a true if both dice have de same value after a roll
private:
	bool _double;
};