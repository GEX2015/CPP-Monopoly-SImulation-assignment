/////////////////////////////////////////////////////////////////////
// File:  Source.cpp
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
#include "PairOfDice.h"
#include "MonopolyPos.h"
#include <iostream>

int main()
{
	PairOfDice dice;
	MonopolyPos game;

	int countForDouble = 0;

	// game loop
	for (int long i = 0; i < 1000000; ++i)
	{
		// roll two dice
		int roll = dice.roll();
		// check if it was double and add to count for double
		if (dice.isDouble())
			countForDouble += 1;
		else
			countForDouble = 0;
		// if the player rolls 3 doubles in a row go to jail and reset the count for double
		if (countForDouble == 3)
		{
			game.goTo(Place::JAIL);
			countForDouble = 0;
		}

		if (countForDouble != 3)
		{
			game.moveForward(roll);
			// check if the player lands on chance 
			if (game.getPos() == Place::CHANCE_1 || game.getPos() == Place::CHANCE_2 || game.getPos() == Place::CHANCE_3)
			{
				// check if chance card makes player move
				Chance chance = game.drawChance();
				if (chance == Chance::GOTO_NEAREST_RAILROAD_1 || chance == Chance::GOTO_NEAREST_RAILROAD_2)
					game.nearestRailroad();
				else if (chance == Chance::GOTO_BOARDWALK)
					game.goTo(Place::BOARDWALK);
				else if (chance == Chance::GOTO_GO)
					game.goTo(Place::GO);
				else if (chance == Chance::GOTO_JAIL)
					game.goTo(Place::JAIL);
				else if (chance == Chance::GOTO_NEAREST_UTILITY)
					game.nearestUtility();
				else if (chance == Chance::GOTO_READING)
					game.goTo(Place::READING_RAILROAD);
				else if (chance == Chance::GOTO_ST_CHARLES)
					game.goTo(Place::ST_CHARLES_PLACE);
				else if (chance == Chance::GOTO_THREE_SPACES_BACK)
					game.moveBackward(3);
				else if (chance == Chance::GOTO_TO_ILLINOIS)
					game.goTo(Place::ILLINOIS_AVENUE);
			}

			// check if the player lands on community chest
			else if (game.getPos() == Place::COMMUNITY_CHEST_1 || game.getPos() == Place::COMMUNITY_CHEST_2 || game.getPos() == Place::COMMUNITY_CHEST_3)
			{
				// check if community chest makes player move
				CommunityChest commChest = game.drawCommunityChest();

				if (commChest == CommunityChest::GOTO_GO)
					game.goTo(Place::GO);
				if (commChest == CommunityChest::GOTO_JAIL)
					game.goTo(Place::JAIL);
			}
			// if the player lands on go to jail move plauyer to jail
			else if (game.getPos() == Place::GOTO_JAIL)
				game.goTo(Place::JAIL);
		}

	}
	// print results
	game.results();
	system("pause");

}