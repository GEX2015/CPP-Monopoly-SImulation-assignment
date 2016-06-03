#include <cstdlib>
#include <ctime>

#pragma once
class PairOfDice
{
public:
	PairOfDice();
	~PairOfDice();

	int roll();
	bool isDouble();
	bool isThreeDoubles();

private:
	bool _double;
	int _doublesInARow;
	int _die1;
	int _die2;
};

