///////////////////////////////////////////////////////////////////////
// File: MonopolyPos.cpp
// Author: Robert Carll
// This assignment represents my own work and is in accordance with the College Academic Policy
// Copyright (c) 2015 All Right Reserved by Robert Carll
// Contributors:
// Description:
// Date: June 2016
// Revisions:
//////////////////////////////////////////////////////////////////////

#include "MonopolyPos.h"

MonopolyPos::MonopolyPos()
{
	fillMap();
}

MonopolyPos::~MonopolyPos()
{
}

void MonopolyPos::fillMap() // Fills the map _placeNames with the place and the string value 
{
	
	_placeNames.insert(std::pair<Place, std::string>(Place::GO, "Go"));
	_placeNames.insert(std::pair<Place, std::string>(Place::MEDITERRANNEAN_AVENUE, "Mediterrannean Avenue"));
	_placeNames.insert(std::pair<Place, std::string>(Place::COMMUNITY_CHEST_1, "Community Chest 1"));
	_placeNames.insert(std::pair<Place, std::string>(Place::BALTIC_AVENUE, "Baltic Avenue"));
	_placeNames.insert(std::pair<Place, std::string>(Place::INCOME_TAX, "Income Tax"));
	_placeNames.insert(std::pair<Place, std::string>(Place::READING_RAILROAD, "Reading Railroad"));
	_placeNames.insert(std::pair<Place, std::string>(Place::ORIENTAL_AVENUE, "Oriental Avenue"));
	_placeNames.insert(std::pair<Place, std::string>(Place::CHANCE_1, "Chance 1"));
	_placeNames.insert(std::pair<Place, std::string>(Place::VERMONT_AVENUE, "Vermont Avenue"));
	_placeNames.insert(std::pair<Place, std::string>(Place::CONNECTICUT_AVENUE, "Connecticut Avenue"));
	_placeNames.insert(std::pair<Place, std::string>(Place::JAIL, "Jail"));
	_placeNames.insert(std::pair<Place, std::string>(Place::ST_CHARLES_PLACE, "St Charles Place"));
	_placeNames.insert(std::pair<Place, std::string>(Place::ELECTRIC_COMPANY, "Electric Avenue"));
	_placeNames.insert(std::pair<Place, std::string>(Place::STATE_AVENUE, "State Avenue"));
	_placeNames.insert(std::pair<Place, std::string>(Place::VIRGINIA_AVENUE, "Virginia Avenue"));
	_placeNames.insert(std::pair<Place, std::string>(Place::PENNSYLVANIA_RAILROAD, "Pennsylvania Railroad"));
	_placeNames.insert(std::pair<Place, std::string>(Place::ST_JAMES_PLACE, "St James Place"));
	_placeNames.insert(std::pair<Place, std::string>(Place::COMMUNITY_CHEST_2, "Community Chest 2"));
	_placeNames.insert(std::pair<Place, std::string>(Place::TENNESSE_AVENUE, "Tennesse Avenue"));
	_placeNames.insert(std::pair<Place, std::string>(Place::NEW_YORK_AVENUE, "New York Avenue"));
	_placeNames.insert(std::pair<Place, std::string>(Place::FREE_PARKING, "Free Parking"));
	_placeNames.insert(std::pair<Place, std::string>(Place::KENTUCKY_AVENUE, "Kentucky Avenue"));
	_placeNames.insert(std::pair<Place, std::string>(Place::CHANCE_2, "Chance 2"));
	_placeNames.insert(std::pair<Place, std::string>(Place::INDIANA_AVENUE, "Indiana Avenue"));
	_placeNames.insert(std::pair<Place, std::string>(Place::ILLINOIS_AVENUE, "Illinois Avenue"));
	_placeNames.insert(std::pair<Place, std::string>(Place::B_AND_O_RAILROAD, "B and O Railroad"));
	_placeNames.insert(std::pair<Place, std::string>(Place::ATLANTIC_AVENUE, "Atlantic Avenue"));
	_placeNames.insert(std::pair<Place, std::string>(Place::VENTNOR_AVENUE, "Ventnor Avenue"));
	_placeNames.insert(std::pair<Place, std::string>(Place::WATER_WORKS, "Water Works"));
	_placeNames.insert(std::pair<Place, std::string>(Place::MARVIN_GARDEN, "Marvin Garden"));
	_placeNames.insert(std::pair<Place, std::string>(Place::GOTO_JAIL, "Go to Jail"));
	_placeNames.insert(std::pair<Place, std::string>(Place::PACIFIC_AVENUE, "Pacific Avenue"));
	_placeNames.insert(std::pair<Place, std::string>(Place::NORTH_CAROLINA_AVENUE, "North Carolina Avenue"));
	_placeNames.insert(std::pair<Place, std::string>(Place::COMMUNITY_CHEST_3, "Comunity Chest 3"));
	_placeNames.insert(std::pair<Place, std::string>(Place::PENNSYLVANIA_AVENUE, "Pennsylvania Avenue"));
	_placeNames.insert(std::pair<Place, std::string>(Place::SHORT_LINE_RAILROAD, "Short Line Railroad"));
	_placeNames.insert(std::pair<Place, std::string>(Place::CHANCE_3, "Chance 3"));
	_placeNames.insert(std::pair<Place, std::string>(Place::PARK_PLACE, "Park Place"));
	_placeNames.insert(std::pair<Place, std::string>(Place::LUXURY_TAX, "Luxury Tax"));
	_placeNames.insert(std::pair<Place, std::string>(Place::BOARDWALK, "Boardwalk"));
}

Place MonopolyPos::goTo(Place p) // Sets the player at the position given and increments _placeTouches
{
	_placeTouches[p]++;
	return _pos = p;
}

void MonopolyPos::moveForward(int roll) // moves character forward and increments _placeTouches
{
	int newPos = (int)_pos + roll;
	if (newPos > 39) {
		newPos -= 40;
	}
	_placeTouches[Place(newPos)]++;
	_pos = Place(newPos);
}

void MonopolyPos::moveBackward(int roll) // moves character backwards and increments _placeTouches
{
	int newPos = (int)_pos - roll;
	if (newPos < 0)
		newPos += 40;
	_placeTouches[Place(newPos)]++;
	_pos = Place(newPos);
}

Place MonopolyPos::nearestRailroad() // returns the nearest railroad
{
	if ((int)_pos < 5)
		return Place::READING_RAILROAD;
	else if ((int)_pos < 15)
		return Place::PENNSYLVANIA_RAILROAD;
	else if ((int)_pos < 25)
		return Place::B_AND_O_RAILROAD;
	else 
		return Place::SHORT_LINE_RAILROAD;	
}

Place MonopolyPos::nearestUtility() // returns the nearest utility
{
	if ((int)_pos < 12)
		return Place::ELECTRIC_COMPANY;
	else
		return Place::WATER_WORKS;
}

Place MonopolyPos::getPos() // gets the current position
{
	return _pos;
}

CommunityChest MonopolyPos::drawCommunityChest() // Draws a community chest card if it is one of the move cards does movement
{
	int card = rand() % 16;
	if (card == 0)
		goTo(Place::JAIL);
		
	if (card == 1)
		goTo(Place::GO);

	return (CommunityChest)card;
}

Chance MonopolyPos::drawChance() // draw chance if it is one of the move cards does movement
{
	int card = rand() % 16;
	switch (card) {
	case 0:
		goTo(nearestRailroad());
		return (Chance)card;
	case 1:
		goTo(nearestRailroad());
		return (Chance)card;
	case 2:
		goTo(Place::READING_RAILROAD);
		return (Chance)card;
	case 3:
		goTo(Place::ILLINOIS_AVENUE);
		return (Chance)card;
	case 4:
		goTo(Place::ST_CHARLES_PLACE);
		return (Chance)card;
	case 5:
		goTo(Place::GO);
		return (Chance)card;
	case 6:
		goTo(Place::BOARDWALK);
		return (Chance)card;
	case 7:
		goTo(Place::GOTO_JAIL);
		return (Chance)card;
	case 8:
		moveBackward(3);
		return (Chance)card;
	case 9:
		goTo(nearestUtility());
		return (Chance)card;

	default:
		return (Chance)card;
	}
}

std::string MonopolyPos::placeToString(Place p) // returns the place name
{
	return _placeNames[p];
}

void MonopolyPos::showStats() // shows the percentage stats of landing on each spot
{
	for (auto e : _placeTouches) {
		std::cout << placeToString(e.first) << " " << ((double)e.second / 100) << "%" << std::endl;
	}
}
