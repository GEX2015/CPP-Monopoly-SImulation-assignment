///////////////////////////////////////////////////////////////////////
// File: Source.cpp
// Author: Robert Carll
// This assignment represents my own work and is in accordance with the College Academic Policy
// Copyright (c) 2015 All Right Reserved by Robert Carll
// Contributors:
// Description:
// Date: June 2016
// Revisions:
//////////////////////////////////////////////////////////////////////

#include "MonopolyPos.h"

int main() {

	PairOfDice dice; // instance of dice
	MonopolyPos game; // instance of game
	srand(static_cast<unsigned int>(time(0))); // gives the random number its randomness

	for (int i = 0; i < 10000; i++) // loop to test 10000 times
	{
		if (dice.getDoubleCount() == 3) // If you roll 3 doubles go to jail
		{
			game.goTo(Place::JAIL); 
			dice.resetDoubleCount(); // reset double count
		}
		else
		{
			game.moveForward(dice.roll()); // forward on roll
			switch ((int)game.getPos()) // gets position
			{
			case 3:
				game.drawCommunityChest(); // if lands on community chest draw community card
				break;
			case 7:
				game.drawChance(); // if lands on chance draw chance card
				break;
			case 17:
				game.drawCommunityChest(); // if lands on community chest draw community card
				break;
			case 22:
				game.drawChance(); // if lands on chance draw chance card
				break;
			case 30:
				game.goTo(Place::JAIL); // go to jail
				break;
			case 33:
				game.drawCommunityChest(); // if lands on community chest draw community card
				break;
			case 36:
				game.drawChance(); // if lands on chance draw chance card
				break;
			default:
				break;
			}
		}
	}
	
	game.showStats(); // this shows the percentage of spots landed on
	system("pause");
}