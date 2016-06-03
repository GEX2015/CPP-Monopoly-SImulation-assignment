#include "PairOfDice.h"


PairOfDice::PairOfDice()
{
	srand(static_cast<unsigned int>(time(0)));
}

PairOfDice::~PairOfDice()
{
}

int PairOfDice::roll()
{
	_die1 = (rand() % 6 + 1); // rolls die 1
	_die2 = (rand() % 6 + 1); // rolls die 2

	isDouble();

	return _die1 + _die2;
}

bool PairOfDice::isDouble()
{
	if (_die1 == _die1) // tests if doubles rolled
	{
		_doublesInARow++;
		return true;
	}
	else
	{
		_doublesInARow = 0;
		return false;
	}
}

bool PairOfDice::isThreeDoubles() // returns true if doubles rolled three times in a row
{
	if (_doublesInARow == 3)
		return true;
	else
		return false;
}
