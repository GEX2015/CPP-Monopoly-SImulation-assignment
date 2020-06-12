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
#include "MonopolyPos.h"
#include <iostream>

int main()
{
	PairOfDice dice;
	MonopolyPos monoGame;

	int countForDouble = 0;

	// game loop
	for (int long i = 0; i < 1000000; ++i)
	{
		// roll the two dice
		int roll = dice.roll();
		// check if the roll was a double if yes add one to the countForDouble
		if (dice.isDouble())
			countForDouble += 1;
		else
			countForDouble = 0;
		// if the player roll 3 double in a row move to jail and reset the counterForDouble
		if (countForDouble == 3)
		{
			monoGame.goTo(Place::JAIL);
			countForDouble = 0;
		}

		if (countForDouble != 3)
		{
			monoGame.moveForward(roll);
			// check if the player land on a chance Place
			if (monoGame.getPos() == Place::CHANCE_1 || monoGame.getPos() == Place::CHANCE_2 || monoGame.getPos() == Place::CHANCE_3)
			{
				// find if the card from Chance is a card that make the player move
				Chance chance = monoGame.drawChance();
				if (chance == Chance::GOTO_NEAREST_RAILROAD_1 || chance == Chance::GOTO_NEAREST_RAILROAD_2)
					monoGame.nearestRailroad();
				else if (chance == Chance::GOTO_BOARDWALK)
					monoGame.goTo(Place::BOARDWALK);
				else if (chance == Chance::GOTO_GO)
					monoGame.goTo(Place::GO);
				else if (chance == Chance::GOTO_JAIL)
					monoGame.goTo(Place::JAIL);
				else if (chance == Chance::GOTO_NEAREST_UTILITY)
					monoGame.nearestUtility();
				else if (chance == Chance::GOTO_READING)
					monoGame.goTo(Place::READING_RAILROAD);
				else if (chance == Chance::GOTO_ST_CHARLES)
					monoGame.goTo(Place::ST_CHARLES_PLACE);
				else if (chance == Chance::GOTO_THREE_SPACES_BACK)
					monoGame.moveBackward(3);
				else if (chance == Chance::GOTO_TO_ILLINOIS)
					monoGame.goTo(Place::ILLINOIS_AVENUE);
			}

			// check if the player land on a community chest
			else if (monoGame.getPos() == Place::COMMUNITY_CHEST_1 || monoGame.getPos() == Place::COMMUNITY_CHEST_2 || monoGame.getPos() == Place::COMMUNITY_CHEST_3)
			{
				// find the the card from community chest is a card that make the player move
				CommunityChest commChest = monoGame.drawCommunityChest();

				if (commChest == CommunityChest::GOTO_GO)
					monoGame.goTo(Place::GO);
				if (commChest == CommunityChest::GOTO_JAIL)
					monoGame.goTo(Place::JAIL);
			}
			// if the player land on the Place go to jail move the plauyer to jail
			else if (monoGame.getPos() == Place::GOTO_JAIL)
				monoGame.goTo(Place::JAIL);
		}

	}
	// print the final result
	monoGame.andResultPlaceLand();
	system("pause");
	
}