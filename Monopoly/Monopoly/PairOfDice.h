#include <cstdlib>
#include <ctime>

#pragma once
class PairOfDice
{
public:
	PairOfDice();
	~PairOfDice();

	int roll(); // rolls two dice
	bool isDouble(); // tests to see if rolled doubles
	bool isThreeDoubles(); // tests if three doubles were rolled in a row

private:
	bool _double;
	int _doublesInARow;
	int _die1;
	int _die2;
};

