//
//  source.cpp
//   
//
//  Created by Chris Arsenault on 2016-06-01.
//  Copyright © 2016 Chris Arsenault. All rights reserved.
//


#include "MonopolyPos.h"
#include "Dice.h"

int main() {

	MonopolyPos game;
	Dice dice;
	srand(static_cast<unsigned int>(time(0)));
	for (int i = 0; i < 10000000; i++)
	{
		if (dice.getDoubleCount() == 3) //if they get 3 doubles in a row
		{
			game.goTo(Place::JAIL);
			dice.resetDoubleCount();
		}
		else
		{
			game.moveForward(dice.roll());
			switch ((int)game.getPos()) //if the roll lands onto one of the spaces that could change where the position marker is
			{
			case 3:
				game.drawCommunityChest();	
				break;
			case 7:
				game.drawChance();			
				break;
			case 17:
				game.drawCommunityChest();	
				break;
			case 22:
				game.drawChance();			
				break;
			case 30:
				game.goTo(Place::JAIL);
				break;
			case 33:
				game.drawCommunityChest();				
				break;
			case 36:
				game.drawChance();			
				break;
			default:
				break;
			}
		}
	}

	game.results();
	system("pause");
}