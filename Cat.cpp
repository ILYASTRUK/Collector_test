#include "Cat.h"
#include "Character.h"
#include <iostream>
#include <ctime>
//class Character;

void Cat::play()
{
	srand(time(0));
	int rand_num = 1 + rand() % 100;
	int bonusChance = (1+ rand() % 30);
	if (rand_num <= bonusChance)
	{
		Pet::cheerfulness += Pet::age * 2.5;
		Character::fun += (Pet::age * 2.5) / 2;		
	}	
}

void Cat::passiveStep()
{
	switch (1 + rand() % 4)
	{
	case 1:
		Character::fun += Pet::age;
	case 2:
		Character::cheerfulness += Pet::age;
	case 3:
		Character::hunger += Pet::age;
	case 4:
		Character::money += Pet::age;
	default:
		break;
	}
}
