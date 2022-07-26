#include "Cat.h"
#include <iostream>
#include <ctime>
#include"Character.h"
#include "Pet.h"


//Cat::Cat() : Pet::Pet() {}
//void Cat::play()
//{
//	srand(time(0));
//	int rand_num = 1 + rand() % 100;
//	int bonusChance = (1+ rand() % 30);
//	if (rand_num <= bonusChance)
//	{
//		Pet::cheerfulness += Pet::age * 2.5;
//		Character::fun += (Pet::age * 2.5) / 2;		
//	}	
//}

void Cat::passiveStep()
{
	Character a;
	switch (1 + rand() % 4)
	{
	case 1:
		a.funUp();
	case 2:
		a.funUp();
	case 3:
		a.funUp();
	case 4:
		a.funUp();
	default:
		break;
	}
}
