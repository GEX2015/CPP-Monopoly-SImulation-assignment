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
	_die1 = (rand() % 6 + 1);
	_die2 = (rand() % 6 + 1);

	isDouble();

	return _die1 + _die2;
}

bool PairOfDice::isDouble()
{
	if (_die1 == _die1)
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

bool PairOfDice::isThreeDoubles()
{
	if (_doublesInARow == 3)
		return true;
	else
		return false;
}
