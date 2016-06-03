#include "MonopolyPos.h"
#include <iomanip>

std::map<Place, int> _placeTouches // fills place touches map
{
	{ Place::ATLANTIC_AVENUE, 0 },
	{ Place::BALTIC_AVENUE, 0 },
	{ Place::BOARDWALK, 0 },
	{ Place::B_AND_O_RAILROAD, 0 },
	{ Place::CHANCE_1, 0 },
	{ Place::CHANCE_2, 0 },
	{ Place::CHANCE_3, 0 },
	{ Place::COMMUNITY_CHEST_1, 0 },
	{ Place::COMMUNITY_CHEST_2, 0 },
	{ Place::COMMUNITY_CHEST_3, 0 },
	{ Place::CONNECTICUT_AVENUE, 0 },
	{ Place::ELECTRIC_COMPANY, 0 },
	{ Place::FREE_PARKING, 0 },
	{ Place::GO, 0 },
	{ Place::GOTO_JAIL, 0 },
	{ Place::ILLINOIS_AVENUE, 0 },
	{ Place::INCOME_TAX, 0 },
	{ Place::INDIANA_AVENUE, 0 },
	{ Place::JAIL, 0 },
	{ Place::KENTUCKY_AVENUE, 0 },
	{ Place::LUXURY_TAX, 0 },
	{ Place::MARVIN_GARDEN, 0 },
	{ Place::MEDITERRANNEAN_AVENUE, 0 },
	{ Place::NEW_YORK_AVENUE, 0 },
	{ Place::NORTH_CAROLINA_AVENUE, 0 },
	{ Place::ORIENTAL_AVENUE, 0 },
	{ Place::PACIFIC_AVENUE, 0 },
	{ Place::PARK_PLACE, 0 },
	{ Place::PENNSYLVANIA_AVENUE, 0 },
	{ Place::PENNSYLVANIA_RAILROAD, 0 },
	{ Place::READING_RAILROAD, 0 },
	{ Place::SHORT_LINE_RAILROAD, 0 },
	{ Place::STATE_AVENUE, 0 },
	{ Place::ST_CHARLES_PLACE, 0 },
	{ Place::ST_JAMES_PLACE, 0 },
	{ Place::TENNESSE_AVENUE, 0 },
	{ Place::VENTNOR_AVENUE, 0 },
	{ Place::VERMONT_AVENUE, 0 },
	{ Place::VIRGINIA_AVENUE, 0 },
	{ Place::WATER_WORKS, 0 }
};

std::map<Place, std::string> _placeNames // fills placenames map
{
	{Place::ATLANTIC_AVENUE, "Atlantic Avenue"},
	{Place::BALTIC_AVENUE, "Baltic Avenue"},
	{Place::BOARDWALK, "Boardwalk"},
	{Place::B_AND_O_RAILROAD, "B and O Railroad"},
	{Place::CHANCE_1, "Chance 1"},
	{Place::CHANCE_2, "Chance 2"},
	{Place::CHANCE_3, "Chance 3"},
	{Place::COMMUNITY_CHEST_1, "Community Chest 1"},
	{Place::COMMUNITY_CHEST_2, "Community Chest 2"},
	{Place::COMMUNITY_CHEST_3, "Community Chest 3"},
	{Place::CONNECTICUT_AVENUE, "Connecticut Avenue"},
	{Place::ELECTRIC_COMPANY, "Electric Company"},
	{Place::FREE_PARKING, "Free Parking"},
	{Place::GO, "Go"},
	{Place::GOTO_JAIL, "Go to Jail"},
	{Place::ILLINOIS_AVENUE, "Illinois Avenue"},
	{Place::INCOME_TAX, "Income Tax"},
	{Place::INDIANA_AVENUE, "Indiana Avenue"},
	{Place::JAIL, "Jail"},
	{Place::KENTUCKY_AVENUE, "Kentucky Avenue"},
	{Place::LUXURY_TAX, "Luxery Tax"},
	{Place::MARVIN_GARDEN, "Marvin Garden"},
	{Place::MEDITERRANNEAN_AVENUE, "Mediterrannean Avenue"},
	{Place::NEW_YORK_AVENUE, "New York Avenue"},
	{Place::NORTH_CAROLINA_AVENUE, "North Carolina Avenue"},
	{Place::ORIENTAL_AVENUE, "Oriental Avenue"},
	{Place::PACIFIC_AVENUE, "Pacific Avenue"},
	{Place::PARK_PLACE, "Park Place"},
	{Place::PENNSYLVANIA_AVENUE, "Pennsylvania Avenue"},
	{Place::PENNSYLVANIA_RAILROAD, "Pennsylvania RailRoad"},
	{Place::READING_RAILROAD, "Reading RailRoad"},
	{Place::SHORT_LINE_RAILROAD, "Short Line RailRoad"},
	{Place::STATE_AVENUE, "State Avenue"},
	{Place::ST_CHARLES_PLACE, "St. Charles Place"},
	{Place::ST_JAMES_PLACE, "St. James Place"},
	{Place::TENNESSE_AVENUE, "Tennesse Avenue"},
	{Place::VENTNOR_AVENUE, "Ventnor Avenue"},
	{Place::VERMONT_AVENUE, "Vermont Avenue"},
	{Place::VIRGINIA_AVENUE, "Virgina Avenue"},
	{Place::WATER_WORKS, "Water Works"}
};

MonopolyPos::MonopolyPos()
{
	srand(static_cast<unsigned int>(time(0)));
	_pos = Place::GO;
}


MonopolyPos::~MonopolyPos()
{
}

Place MonopolyPos::goTo(Place p)
{
	_pos = p;
	placeTouched();
	return _pos;
}

void MonopolyPos::moveForward(int i) 
{
	int newPos = static_cast<int>(_pos);
	for (int j = 0; j < i; j++)
	{
		newPos++;
		if (newPos > 39) // if _pos is greater than go sets _pos to go
		{
			newPos -= 40;
		}
		_pos = static_cast<Place>(newPos);
	}

	placeTouched();

	if (isChance())
		drawChance();
	else if (isCommChest())
		drawCommunityChest();

	goToJail();
}

void MonopolyPos::moveBackward(int i)
{

	int newPos = static_cast<int>(_pos);
	for (int j = 0; j < i; j++)
	{
		newPos--;
		if (newPos > 39) // if _pos is greater than go sets _pos to go
		{
			newPos -= 40;
		}
		_pos = static_cast<Place>(newPos);
	}

	placeTouched();

	if (isChance())
		drawChance();
	else if (isCommChest())
		drawCommunityChest();

	goToJail();
}

Place MonopolyPos::nearestRailroad() // finds nearest railroad to _pos
{
	int reading = distanceTo(Place::READING_RAILROAD);
	int pennsyl = distanceTo(Place::PENNSYLVANIA_RAILROAD);
	int bAndO = distanceTo(Place::B_AND_O_RAILROAD);
	int shortLine = distanceTo(Place::SHORT_LINE_RAILROAD);

	if (reading < pennsyl && reading < bAndO && reading < shortLine)
		return Place::READING_RAILROAD;
	else if (pennsyl < reading && pennsyl < bAndO && pennsyl < shortLine)
		return Place::PENNSYLVANIA_RAILROAD;
	else if (bAndO < reading && bAndO < pennsyl && bAndO < shortLine)
		return Place::B_AND_O_RAILROAD;
	else if (shortLine < reading && shortLine < pennsyl && shortLine < bAndO)
		return Place::SHORT_LINE_RAILROAD;
}

Place MonopolyPos::nearestUtility() // finds nearest ultility to _pos
{
	int waterWorks = distanceTo(Place::WATER_WORKS);
	int electricCompany = distanceTo(Place::ELECTRIC_COMPANY);

	if (waterWorks < electricCompany)
		return Place::WATER_WORKS;
	else
		return Place::ELECTRIC_COMPANY;
}

Place MonopolyPos::getPos()
{
	return _pos;
}

CommunityChest MonopolyPos::drawCommunityChest()
{
	CommunityChest cc = static_cast<CommunityChest> (rand() % 16 + 1);

	if (cc == CommunityChest::GOTO_GO)
		goTo(Place::GO);
	if (cc == CommunityChest::GOTO_JAIL)
		goTo(Place::JAIL);
	return cc;
}

Chance MonopolyPos::drawChance()
{
	Chance chance = static_cast<Chance> (rand() % 16 + 1);

	if (chance == Chance::GOTO_GO)
		goTo(Place::GO);
	if (chance == Chance::GOTO_JAIL)
		goTo(Place::JAIL);
	if (chance == Chance::GOTO_BOARDWALK)
		goTo(Place::BOARDWALK);
	if (chance == Chance::GOTO_NEAREST_RAILROAD_1 || chance == Chance::GOTO_NEAREST_RAILROAD_2)
		goTo(nearestRailroad());
	if (chance == Chance::GOTO_NEAREST_UTILITY)
		goTo(nearestUtility());
	if (chance == Chance::GOTO_READING)
		goTo(Place::READING_RAILROAD);
	if (chance == Chance::GOTO_ST_CHARLES)
		goTo(Place::ST_CHARLES_PLACE);
	if (chance == Chance::GOTO_THREE_SPACES_BACK)
		moveBackward(3);
	if (chance == Chance::GOTO_TO_ILLINOIS)
		goTo(Place::ILLINOIS_AVENUE);
	return chance;
}

std::string MonopolyPos::placeToString(Place p)
{
	return _placeNames.at(p);
}

void MonopolyPos::placeTouched()
{
	_placeTouches[_pos]++;
}

int MonopolyPos::distanceTo(Place p)
{
	int pos = static_cast<int>(_pos);
	int place = static_cast<int>(p);

	if (pos > place)
		return pos - place;
	else
		return place - pos;
}

bool MonopolyPos::isChance()
{
	if (_pos == Place::CHANCE_1 || _pos == Place::CHANCE_2 || _pos == Place::CHANCE_3)
		return true;
	else
		return false;
}

bool MonopolyPos::isCommChest()
{
	if (_pos == Place::COMMUNITY_CHEST_1 || _pos == Place::COMMUNITY_CHEST_2 || _pos == Place::COMMUNITY_CHEST_3)
		return true;
	else
		return false;
}

void MonopolyPos::results() // displays results
{
	for (auto e : _placeTouches)
		std::cout << std::setw(25) << placeToString(e.first) << ": " << ((double)e.second / 10000) << "%" << std::endl;
}

void MonopolyPos::fillMaps()
{
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

void MonopolyPos::goToJail() // tests to see if _pos == goToJail
{
	if (_pos == Place::GOTO_JAIL)
		_pos = Place::JAIL;
}
