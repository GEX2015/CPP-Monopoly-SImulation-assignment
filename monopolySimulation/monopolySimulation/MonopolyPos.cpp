/////////////////////////////////////////////////////////////////////
// File:  Monopoly.cpp
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
#include "MonopolyPos.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <iomanip>

// starts the player at go
MonopolyPos::MonopolyPos()
{
	_pos = Place::GO;
}

MonopolyPos::~MonopolyPos()
{
}
// a string for every place
const std::map<Place, std::string> MonopolyPos::_placeNames{
	{ Place::GO, "Go" },
	{ Place::MEDITERRANNEAN_AVENUE, "Mediterrannean Avenue" },
	{ Place::COMMUNITY_CHEST_1, "Community chest 1" },
	{ Place::BALTIC_AVENUE, "Baltic Avenue" },
	{ Place::INCOME_TAX, "Income Tax" },
	{ Place::READING_RAILROAD, "Reading Railroad" },
	{ Place::ORIENTAL_AVENUE, "Oriental Avenue" },
	{ Place::CHANCE_1, "Chance 1" },
	{ Place::VERMONT_AVENUE, "Vermont Avenue" },
	{ Place::CONNECTICUT_AVENUE, "Connecticut Avenue" },
	{ Place::JAIL, "Jail" },
	{ Place::ST_CHARLES_PLACE, "St Charles Place" },
	{ Place::ELECTRIC_COMPANY, "Electric Compagny" },
	{ Place::STATE_AVENUE, "State Avenue" },
	{ Place::VIRGINIA_AVENUE, "Virginia Avenue" },
	{ Place::PENNSYLVANIA_RAILROAD, "Pennsylvania Railroad" },
	{ Place::ST_JAMES_PLACE,"St James Place" },
	{ Place::COMMUNITY_CHEST_2,"Community Chest 2" },
	{ Place::TENNESSE_AVENUE,"Tennesse Avenue" },
	{ Place::NEW_YORK_AVENUE,"New york Avenue" },
	{ Place::FREE_PARKING, "Free Parking" },
	{ Place::KENTUCKY_AVENUE,"Kentucky Avenue" },
	{ Place::CHANCE_2, "Chance 2" },
	{ Place::INDIANA_AVENUE,"Indiana Avenue" },
	{ Place::ILLINOIS_AVENUE,"Illinois Avenue" },
	{ Place::B_AND_O_RAILROAD, "B and O Railroad" },
	{ Place::ATLANTIC_AVENUE,"Atlantic Avenue" },
	{ Place::VENTNOR_AVENUE, "Ventnor Avenue" },
	{ Place::WATER_WORKS, "Water Works" },
	{ Place::MARVIN_GARDEN, "Marvin Garden" },
	{ Place::GOTO_JAIL, "Go To Jail" },
	{ Place::PACIFIC_AVENUE, "Pacific Avenue" },
	{ Place::NORTH_CAROLINA_AVENUE,"North Carolina Avenue" },
	{ Place::COMMUNITY_CHEST_3, "Community Chest 3" },
	{ Place::PENNSYLVANIA_AVENUE,"Pennsylvania Avenue" },
	{ Place::SHORT_LINE_RAILROAD, "Short Line RailRoad" },
	{ Place::CHANCE_3,"Chance 3" },
	{ Place::PARK_PLACE,"Park Place" },
	{ Place::LUXURY_TAX, "Luxary Tax" },
	{ Place::BOARDWALK,"Boardwalk" },
	{ Place::COUNT,"Count" }
};


//moves player directly to position
void MonopolyPos::goTo(Place p)
{
	_pos = p;
	_placeTouches[_pos]++;
}

//moves player forward
void MonopolyPos::moveForward(int i)
{
	int currentposition = static_cast<int>(getPos());
	int nextPosition = currentposition + i;

	if (nextPosition > 39)
		nextPosition -= 40;
	goTo(static_cast<Place>(nextPosition));
}

//moves player backwards
void MonopolyPos::moveBackward(int i)
{
	int currentposition = static_cast<int>(getPos());
	int nextPosition = currentposition - i;
	goTo(static_cast<Place>(nextPosition));
}
//moves the player to the nearest railroad
Place MonopolyPos::nearestRailroad()
{
	int currentPosition = static_cast<int>(getPos());

	if (currentPosition >= 0 && currentPosition <= 4)
		goTo(Place::READING_RAILROAD);
	else if (currentPosition >= 6 && currentPosition <= 14)
		goTo(Place::PENNSYLVANIA_RAILROAD);
	else if (currentPosition >= 16 && currentPosition <= 24)
		goTo(Place::B_AND_O_RAILROAD);
	else if (currentPosition >= 26 && currentPosition <= 34)
		goTo(Place::B_AND_O_RAILROAD);
	else
		goTo(Place::READING_RAILROAD);

	return _pos;
}

//moves the player to the nearest utility
Place MonopolyPos::nearestUtility()
{
	int currentPosition = static_cast<int>(getPos());

	if (currentPosition >= 13 && currentPosition <= 27)
		goTo(Place::WATER_WORKS);
	else
		goTo(Place::ELECTRIC_COMPANY);
	return _pos;
}

// gts the current position of the player
Place MonopolyPos::getPos()
{
	return _pos;
}

// draws a random community chest card
CommunityChest MonopolyPos::drawCommunityChest()
{
	int randNumber = rand() % 15;
	CommunityChest randCard = static_cast<CommunityChest> (randNumber);

	return randCard;
}

// draws a random chance card
Chance MonopolyPos::drawChance()
{
	int randNum = rand() % 15;
	Chance randCard = static_cast<Chance> (randNum);

	return randCard;
}

//gives a string for every place
std::string MonopolyPos::placeToString(Place p)
{
	return _placeNames.at(p);
}

//calculates a percentage for every place 
void MonopolyPos::results()
{
	std::string result = "";
	for (auto itr : _placeTouches)
	{
		double pourcentage = (static_cast<double>(itr.second) * 100) / 1000000;
		std::cout << std::setw(24) << placeToString(itr.first) << "   " << std::setprecision(3) << pourcentage << "%" << std::endl;
	}

}