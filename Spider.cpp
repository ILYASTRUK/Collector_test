#include "Spider.h"
#include "Character.h"
#include <iostream>
#include <ctime>
void MyClass::play()
{
	srand(time(0));
	int rand_num = 1 + rand() % 100;
	int bonusChance = (1 + rand() % 30);
	if (rand_num <= bonusChance)
	{
		Pet::cheerfulness += Pet::age * 2.5;
		Character::money += (Pet::age * 2.5) / 2;
	}
}

void MyClass::passiveStep()
{
	int rand_num = 1 + rand() % 4;
	switch (rand_num)
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
