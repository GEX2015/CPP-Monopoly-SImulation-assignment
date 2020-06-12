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
#include <string>
#include <map>

// /////////////////////////////////////////
// ENUMS for Monopoly
// /////////////////////////////////////////
enum class Place {
	// list of Monopoly properties in the order they appear on the board.

	//street 1
	GO = 0, MEDITERRANNEAN_AVENUE, COMMUNITY_CHEST_1, BALTIC_AVENUE, INCOME_TAX,
	READING_RAILROAD, ORIENTAL_AVENUE, CHANCE_1, VERMONT_AVENUE, CONNECTICUT_AVENUE,

	//street 2
	JAIL, ST_CHARLES_PLACE,
	ELECTRIC_COMPANY, STATE_AVENUE, VIRGINIA_AVENUE,
	PENNSYLVANIA_RAILROAD, ST_JAMES_PLACE, COMMUNITY_CHEST_2, TENNESSE_AVENUE,
	NEW_YORK_AVENUE,

	//street 3
	FREE_PARKING, KENTUCKY_AVENUE, CHANCE_2, INDIANA_AVENUE, ILLINOIS_AVENUE,
	B_AND_O_RAILROAD, ATLANTIC_AVENUE, VENTNOR_AVENUE,
	WATER_WORKS, MARVIN_GARDEN,

	//street 4
	GOTO_JAIL, PACIFIC_AVENUE, NORTH_CAROLINA_AVENUE, COMMUNITY_CHEST_3,
	PENNSYLVANIA_AVENUE,
	SHORT_LINE_RAILROAD, CHANCE_3, PARK_PLACE, LUXURY_TAX, BOARDWALK,

	//Place count
	COUNT
};

// /////////////////////////////////////////
// ENUMS Chance Card
// /////////////////////////////////////////
enum class Chance {
	//MOVE CARDS
	GOTO_NEAREST_RAILROAD_1 = 0, GOTO_NEAREST_RAILROAD_2, GOTO_READING, GOTO_TO_ILLINOIS,
	GOTO_ST_CHARLES, GOTO_GO, GOTO_BOARDWALK, GOTO_JAIL,
	GOTO_THREE_SPACES_BACK, GOTO_NEAREST_UTILITY,

	//NON-MOVE CARDS
	PAY_POOR_TAX, ELECTED_CHAIRMAN, HOUSES_AND_HOTELS_RENOVATION, BANK_PAYS_DIVIDEND,
	LOAN_MATURES, GET_OUT_OF_JAIL,

	//card count
	COUNT
};

// /////////////////////////////////////////
// ENUMS Community Chest Card
// /////////////////////////////////////////
enum class CommunityChest
{
	//MOVE CARDS
	GOTO_JAIL = 0, GOTO_GO,

	//NON-MOVE CARDS
	PAY_SCHOOL_TAX, SERVICE_REWARD1, SERVICE_REWARD2, RECEIVE_FIFTY_FROM_EACH_PLAYER,
	XMAS_FUND, LIFE_INSURANCE,
	DOCTOR_FEE, INCOME_TAX_RETURN, BANK_ERROR, PROPERTY_TAX, HOSPITAL_TAX,
	GET_OUT_OF_JAIL, BEAUTY_CONTEST, INHERIT,

	//card count
	COUNT
};
class MonopolyPos
{
public:
	MonopolyPos();
	~MonopolyPos();

	void goTo(Place);
	void moveForward(int);
	void moveBackward(int);
	Place nearestRailroad();
	Place nearestUtility();
	Place getPos();
	CommunityChest drawCommunityChest();
	Chance drawChance();
	std::string placeToString(Place);
	void andResultPlaceLand();

private:
	Place _pos;
	//map for count the number of time the player land on a place
	std::map<Place, int>  _placeTouches;
	static const std::map<Place, std::string> _placeNames;
};

