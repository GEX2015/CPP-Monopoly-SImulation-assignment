//
//  MonopolyPos.cpp
//   
//
//  Created by Chris Arsenault on 2016-06-01.
//  Copyright © 2016 Chris Arsenault. All rights reserved.
//


#include "MonopolyPos.h"


MonopolyPos::MonopolyPos()
{
	fillMaps(); //fills the maps with the enum and the strings/ints
}

MonopolyPos::~MonopolyPos()
{
}

Place MonopolyPos::goTo(Place p)
{

	_placeTouches[p]++; //for when you land on a space in a way other than a dice roll (ex: go to jail card)
	return _pos = p; //sets _pos to the new position
}

void MonopolyPos::moveForward(int roll)
{
	int newPos = (int)_pos + roll;
	if (newPos > 39) //checks to see if you go past boardwalk  to reset your position
	{
		newPos -= 40;
	}
	_placeTouches[Place(newPos)]++; //adds to the counter each time it lands on a position
	_pos = Place(newPos); //sets the pos to the new pos



}

void MonopolyPos::moveBackward(int roll)
{
	int newPos = (int)_pos - roll; //checks to see if you go past go backwards
	if (newPos < 0)
	{
		newPos += 40;
	}
	_placeTouches[Place(newPos)]++; //adds to the counter each time it lands on a position
	_pos = Place(newPos); //sets the pos to the new pos

}

Place MonopolyPos::nearestRailroad() const//finds the nearest railroad by checking which railroads its between
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

Place MonopolyPos::nearestUtility() const //finds the nearest utility by checking which utility behind
{
	if ((int)_pos < 12)
		return Place::ELECTRIC_COMPANY;
	else
		return Place::WATER_WORKS;
}

const Place MonopolyPos::getPos()
{
	return _pos;
}

CommunityChest MonopolyPos::drawCommunityChest() const
{
	int card = (rand() % 16); 
	//checks to see if it's one of the cards that moves the player
	if (card == 0) 
	{
		goTo(Place::JAIL);
	}
	if (card == 1)
		goTo(Place::GO);

	return (CommunityChest)card;
}

Chance MonopolyPos::drawChance() const
{
	int card = (rand() % 16);
	switch (card) //checks to see if it's one of the cards that moves the player
	{
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
		goTo(Place::JAIL);
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

void MonopolyPos::results() //prints oout the results of the simulation
{
	for (auto e : _placeTouches)
		std::cout << placeToString(e.first) << ": " << ((double)e.second / 100000) << "%" << std::endl << std::endl;
}

std::string MonopolyPos::placeToString(Place p) const //to get the string version of the enum
{

	return _placeNames[p];
}

void MonopolyPos::fillMaps() //fills the maps with the values
{
	for (int i = 0; i < (int)Place::COUNT; i++)
	{
		std::pair<Place, int> pair((Place)i, 0);
		_placeTouches.insert(pair);
	}





	_placeNames.insert(std::pair<Place, std::string>(Place::GO, "GO"));
	_placeNames.insert(std::pair<Place, std::string>(Place::MEDITERRANNEAN_AVENUE, "Mediterrannean Avenue"));
	_placeNames.insert(std::pair<Place, std::string>(Place::COMMUNITY_CHEST_1, "Community Chest 1"));
	_placeNames.insert(std::pair<Place, std::string>(Place::BALTIC_AVENUE, "Baltic Avenue"));
	_placeNames.insert(std::pair<Place, std::string>(Place::INCOME_TAX, "Income Tax"));
	_placeNames.insert(std::pair<Place, std::string>(Place::READING_RAILROAD, "Reading Railroad"));
	_placeNames.insert(std::pair<Place, std::string>(Place::ORIENTAL_AVENUE, "Oriental Avenue"));
	_placeNames.insert(std::pair<Place, std::string>(Place::CHANCE_1, "Chance 1"));
	_placeNames.insert(std::pair<Place, std::string>(Place::VERMONT_AVENUE, "Vermont Avenue"));
	_placeNames.insert(std::pair<Place, std::string>(Place::CONNECTICUT_AVENUE, "Connecticut Avenue"));
	_placeNames.insert(std::pair<Place, std::string>(Place::JAIL, "JAIL"));
	_placeNames.insert(std::pair<Place, std::string>(Place::ST_CHARLES_PLACE, "St Charles Place"));
	_placeNames.insert(std::pair<Place, std::string>(Place::ELECTRIC_COMPANY, "Electric Company"));
	_placeNames.insert(std::pair<Place, std::string>(Place::STATE_AVENUE, "State Avenue"));
	_placeNames.insert(std::pair<Place, std::string>(Place::VIRGINIA_AVENUE, "Varginia Avenue"));
	_placeNames.insert(std::pair<Place, std::string>(Place::PENNSYLVANIA_RAILROAD, "Pennsylvania Railroad"));
	_placeNames.insert(std::pair<Place, std::string>(Place::ST_JAMES_PLACE, "St James Place"));
	_placeNames.insert(std::pair<Place, std::string>(Place::COMMUNITY_CHEST_2, "Community Chest 2"));
	_placeNames.insert(std::pair<Place, std::string>(Place::TENNESSE_AVENUE, "Tennesee Avenue"));
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
	_placeNames.insert(std::pair<Place, std::string>(Place::GOTO_JAIL, "Go To Jail"));
	_placeNames.insert(std::pair<Place, std::string>(Place::PACIFIC_AVENUE, "Pacific Avenue"));
	_placeNames.insert(std::pair<Place, std::string>(Place::NORTH_CAROLINA_AVENUE, "North Carolina Avenue"));
	_placeNames.insert(std::pair<Place, std::string>(Place::COMMUNITY_CHEST_3, "Community Chest 3"));
	_placeNames.insert(std::pair<Place, std::string>(Place::PENNSYLVANIA_AVENUE, "Pennsylvania Avenue"));
	_placeNames.insert(std::pair<Place, std::string>(Place::SHORT_LINE_RAILROAD, "Short Line Railroad"));
	_placeNames.insert(std::pair<Place, std::string>(Place::CHANCE_3, "CHANCE_3"));
	_placeNames.insert(std::pair<Place, std::string>(Place::PARK_PLACE, "Park Place"));
	_placeNames.insert(std::pair<Place, std::string>(Place::LUXURY_TAX, "Luxury Tax"));
	_placeNames.insert(std::pair<Place, std::string>(Place::BOARDWALK, "BoardWalk"));
}

