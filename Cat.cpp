#include "Cat.h"
#include <iostream>
#include <ctime>

void Cat::play()
{
	srand(time(0));
	int rand_num = 1 + rand() % 100;
	int bonusChance = (1 * 2.5 + rand() % 30); // 1-> Pet::getAge()
	if (rand_num <= bonusChance)
	{
		//Pet::getCheerfulness() += 2.5;
		//Character::fun += (2.5 / 2);		
	}	
}

void Cat::passiveStep()
{
	switch (1 + rand() % 4)
	{
	case 1:

	case 2:

	case 3:

	case 4:

	default:
		break;
	}
}