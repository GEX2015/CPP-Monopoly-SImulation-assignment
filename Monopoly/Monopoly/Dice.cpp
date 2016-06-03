//
//  dice.cpp
//   
//
//  Created by Chris Arsenault on 2016-06-01.
//  Copyright © 2016 Chris Arsenault. All rights reserved.
//


#include "Dice.h"



Dice::Dice()
{

}


Dice::~Dice()
{
}

int Dice::roll()
{
	int roll1 = (rand() % 6 + 1);//rolls the 2 dice
	int roll2 = (rand() % 6 + 1);

	isDouble(roll1, roll2); //checks to see if the dice are doubles

	return roll1 + roll2; //returns the total

}

bool Dice::isDouble(int roll1, int roll2)
{

	if (roll1 == roll2)
	{
		_doubleCount++;
		return true;
	}
	else
	{
		_doubleCount = 0;
		return false;
	}
}

int Dice::getDoubleCount() const // keeps count of the doubles that have been rolled in a row 
{
	return _doubleCount;
}

void Dice::resetDoubleCount()
{
	_doubleCount = 0;
}


