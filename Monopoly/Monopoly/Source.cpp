#include <iostream>
#include "MonopolyPos.h"
#include "PairOfDice.h"
using std::cout;
using std::endl;

int main()
{
	MonopolyPos pos;
	PairOfDice dice;
	pos.fillMaps();
	for (int i = 0; i < 1000000; i++) // 1 000 000 rolls
	{
		pos.moveForward(dice.roll());
		if (dice.isThreeDoubles())
			pos.goTo(Place::JAIL);
	}

	pos.results();

	system("pause");
}