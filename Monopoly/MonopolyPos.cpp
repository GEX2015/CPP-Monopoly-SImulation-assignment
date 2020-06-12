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


#include "MonopolyPos.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <iomanip>

MonopolyPos::MonopolyPos()
{
	_pos = Place::GO;
	srand(unsigned(time(NULL)));
}

MonopolyPos::~MonopolyPos()
{
}
 // fill the map to have a string for eache Place enum
const std::map<Place, std::string> MonopolyPos::_placeNames{
	{Place::GO, "Go"},
	{Place::MEDITERRANNEAN_AVENUE, "Mediterrannean Avenue"},
	{Place::COMMUNITY_CHEST_1, "Community chest 1"}, 
	{Place::BALTIC_AVENUE, "Baltic Avenue"},
	{Place::INCOME_TAX, "Icome Tax"},
	{Place::READING_RAILROAD, "Reading Railroad"},
	{Place::ORIENTAL_AVENUE, "Oriental Avenue"},
	{Place::CHANCE_1, "Chance 1"},
	{Place::VERMONT_AVENUE, "Vermont Avenue"},
	{Place::CONNECTICUT_AVENUE, "Connecticut Avenue"},
	{Place::JAIL, "Jail"},
	{Place::ST_CHARLES_PLACE, "St-Charles Place"},
	{Place::ELECTRIC_COMPANY, "Electric Compagny"},
	{Place::STATE_AVENUE, "State Avenue"},
	{Place::VIRGINIA_AVENUE, "Virginial Avenue"},
	{Place::PENNSYLVANIA_RAILROAD, "Pennsylvania Railroad"},
	{Place::ST_JAMES_PLACE,"St-James Place"},
	{Place::COMMUNITY_CHEST_2,"Community Chest 2"},
	{Place::TENNESSE_AVENUE,"Tennesse Avenue"},
	{Place::NEW_YORK_AVENUE,"New-york Avenue"},
	{Place::FREE_PARKING, "Free Parcking"},
	{Place::KENTUCKY_AVENUE,"Kentucky Avenue"},
	{Place::CHANCE_2, "Chance 2"},
	{Place::INDIANA_AVENUE,"Indiana Avenue"},
	{Place::ILLINOIS_AVENUE,"Ilinois Avenue"},
	{Place::B_AND_O_RAILROAD, "B&O Railroad"},
	{Place::ATLANTIC_AVENUE,"Atlantic Avenue"},
	{Place::VENTNOR_AVENUE, "Ventnor Avenue"},
	{Place::WATER_WORKS, "Water Work"},
	{Place::MARVIN_GARDEN, "Marvin Garden"},
	{Place::GOTO_JAIL, "Go To Jail"},
	{Place::PACIFIC_AVENUE, "Pacific Avenue"},
	{Place::NORTH_CAROLINA_AVENUE,"North Carolina Avenue"},
	{Place::COMMUNITY_CHEST_3, "Community Chest 3"},
	{Place::PENNSYLVANIA_AVENUE,"Pennsylvanie Avenue"},
	{Place::SHORT_LINE_RAILROAD, "Short Line RailRoad"},
	{Place::CHANCE_3,"Chance 3"},
	{Place::PARK_PLACE,"Park Place"},
	{Place::LUXURY_TAX, "Luxary Tax"},
	{Place::BOARDWALK,"Boardwalk"},
	{Place::COUNT,"Count"}
};

// make the player move and insert the new possition to the map _placeTouches
void MonopolyPos::goTo(Place p)
{
	_pos = p;
	_placeTouches[_pos]++;
}

// move the player forward
void MonopolyPos::moveForward(int i)
{
	int currentposition  = static_cast<int>(getPos());
	int nextPosition = currentposition + i;

	if (nextPosition > 39)
		nextPosition -= 40;
	goTo(static_cast<Place>(nextPosition));
}
// move the player backward the only thing that move backward is a card from Chance
void MonopolyPos::moveBackward(int i)
{
	int currentposition = static_cast<int>(getPos());
	int nextPosition = currentposition - i;

	goTo(static_cast<Place>(nextPosition));
}

// find the nearest Railroad and move the player to it
Place MonopolyPos::nearestRailroad()
{
	int currentPosition = static_cast<int>(getPos());

	if (currentPosition >= 0 && currentPosition <= 4)
		goTo(Place::READING_RAILROAD);
	else if (currentPosition >=6 && currentPosition <= 14)
		goTo(Place::PENNSYLVANIA_RAILROAD);
	else if (currentPosition >= 16 && currentPosition <= 24)
		goTo(Place::B_AND_O_RAILROAD);
	else if (currentPosition >= 26 && currentPosition <= 34)
		goTo(Place::B_AND_O_RAILROAD);
	else
		goTo(Place::READING_RAILROAD);

	return _pos;
}

// find the nearest utility and move the player to it
Place MonopolyPos::nearestUtility()
{
	int currentPosition = static_cast<int>(getPos());

	if (currentPosition >= 13 && currentPosition <= 27)
		goTo(Place::WATER_WORKS);
	else
		goTo(Place::ELECTRIC_COMPANY);
	return _pos;
}

// get the current position
Place MonopolyPos::getPos()
{
	return _pos;
}

// randomly pick a card from the enum CommunityChest
CommunityChest MonopolyPos::drawCommunityChest()
{
	int randNumber = rand() % 15;
	CommunityChest randCard = static_cast<CommunityChest> (randNumber);

	return randCard;
}

// randomly pick a card from the enum Chance
Chance MonopolyPos::drawChance()
{
	int randNumber = rand() % 15;
	Chance randCard = static_cast<Chance> (randNumber);

	return randCard;
}

// return a string for the Place that is pass to it
std::string MonopolyPos::placeToString(Place p)
{	
	return _placeNames.at(p);
}

// print the result of % off landing on each place
void MonopolyPos::andResultPlaceLand()
{
	std::string result = "";
	for (auto itr : _placeTouches)
	{
		double pourcentage = (static_cast<double>(itr.second) * 100) / 1000000;
		std::cout << std::setw(24)<< placeToString(itr.first) << "   " << std::setprecision(3) << pourcentage<<"%" << std::endl;
	}
	
}
