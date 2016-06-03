//
//  dice.h
//   
//
//  Created by Chris Arsenault on 2016-06-01.
//  Copyright © 2016 Chris Arsenault. All rights reserved.
//


#pragma once
#include <ctime>
#include <cstdlib>
class Dice
{
public:
	Dice();
	~Dice();

	int roll();
	bool isDouble(int roll1, int roll2);
	int getDoubleCount() const;
	void resetDoubleCount();
private:
	int _doubleCount=0;
};

