#include <iostream>
#include <ctime>
#include <iomanip>
#include"character.h"

using namespace std;

bool Character::character_dead() //проверка на смерть персонажа
{
	if (hunger < 10)
	{
		srand(time(0));
		int rand_num = 1 + rand() % 100;
		int deadChance = (10 - hunger) * 100;
		if (rand_num <= deadChance)
		{
			status = false;
			cout << "Character is dead" << endl;
			return false;
		}
		else
		{
			return true;
		}
	}

	if (fun < 10)
	{
		srand(time(0));
		int rand_num = 1 + rand() % 100;
		int deadChance = (10 - fun) * 100;
		if (rand_num <= deadChance)
		{
			status = false;
			cout << "Character is dead" << endl;
			return false;
		}
		else
		{
			return true;
		}
	}

	if (cheerfulness < 10)
	{
		srand(time(0));
		int rand_num = 1 + rand() % 100;
		int deadChance = (10 - cheerfulness) * 100;
		if (rand_num <= deadChance)
		{
			status = false;

			return false;
		}
		else
		{
			return true;
		}
	}
	return true;
}

void Character::character_step(int _param)
{
	param action = static_cast<param>(_param);
	if (param::play == action)
	{
		hunger -= 8;
		cheerfulness -= 8;
	}
	if (param::eat == action)
	{
		cheerfulness -= 8;
		fun -= 8;
	}
	if (param::sleep == action)
	{
		fun -= 8;
		hunger -= 8;
	}
	if (param::work == action)
	{
		fun -= 8;
		hunger -= 8;
		cheerfulness -= 8;
	}
	if (param::inactivity == action)
	{
		fun -= 8;
		hunger -= 8;
		cheerfulness -= 8;
	}
	if (param::none == action)
	{
		//nothing
	}

	srand(time(0));
	timer += 1 + rand() % 25;
	if (timer >= 100)
	{
		age++;
		int buf = timer;  //остаток после взросления(>100)
		timer = buf - 100;
	}
}

Character::Character() : hunger(100), fun(100), cheerfulness(100), name("Lewis Hamilton"), age(0), status(true), money(50), petsCount(1), livePets(1)
{
#ifdef _DEBUG
	cout << " Character constructor" << endl;
#endif
}
Character::~Character()
{
#ifdef _DEBUG
	cout << "Character destructor" << endl;
#endif
}

int Character::spend_money()
{
	cout << setw(17) << name << setw(9) << "money:" << setw(5) << money << "->";
	if (money >= 5)
	{
		money -= 5;
		cout << money << endl;
		return 0;
	}
	else
	{
		cout << "Not enough money" << endl;
		return 1;
	}
}

void Character::eat()
{
	cout << setw(17) << name << setw(9) << "hunger:" << setw(5) << hunger << "->";

	srand(time(0));
	hunger += (1 + rand() % 25);
	if (hunger >= 100)
	{
		hunger = 100;
	}

	if (hunger <= 0)
	{
		hunger = 0;
	}
	cout << hunger << endl;
}

void Character::sleep()
{
	cout << setw(17) << name << setw(9) << "cheerfulness:" << setw(5) << cheerfulness << "->";
	srand(time(0));
	cheerfulness += (1 + rand() % 25);
	if (cheerfulness >= 100)
	{
		cheerfulness = 100;
	}

	if (cheerfulness <= 0)
	{
		cheerfulness = 0;
	}
	cout << cheerfulness << endl;
}

void Character::work()
{
	cout << setw(17) << name << setw(9) << "money:" << setw(5) << money << "->";

	srand(time(0));
	money += (1 + rand() % 25);

	if (money >= 100)
	{
		money = 100;
	}

	if (money <= 0)
	{
		money = 0;
	}
	cout << money << endl;
}

void Character::character_fun() //одновременно с методом play() питомца
{
	cout << setw(17) << name << setw(9) << "fun:" << setw(5) << fun << "->";

	srand(time(0));
	fun += (1 + rand() % 25);

	if (fun >= 100)
	{
		fun = 100;
	}

	if (fun <= 0)
	{
		fun = 0;
	}
	cout << fun << endl;
}

void Character::setName()
{
	cout << "\nName a character: ";
	cin >> name;
	cout << "New character name is: " << name << endl;
}

void Character::show()
{
	cout << "\tCharacters's characteristics" << endl;
	cout << "Name: " << name << endl << "Age: " << age << endl << "Status: " << status << endl << "Hunger: " << hunger << endl << "Fun: " << fun << endl << "Cheerfulness: " << cheerfulness << endl << "Money: " << money;
}

void Character::finalResult()
{
	cout << "Final result" << endl;
	cout << setw(9) << "Character age: " << setw(4) << age << setw(5) << endl;
	cout << setw(9) << "Amount of pets: " << setw(4) << petsCount << setw(5) << endl;
}

int Character::getpetsCount()
{
	return petsCount;

}

int Character::getlivePetsCount()
{
	return livePets;
}

void Character::buyPet()
{
	if (money >= 25 && livePets <5)
	{
		cout << setw(17) << money << setw(9) << "money:" << setw(5) << money << "->";
		money -= 25;
		cout << money << endl;
		p[livePets] = Pet();
		p[livePets].setpetName();
		petsCount++;
		livePets++;
	}
	else
	{
		cout << "Not enough money or FULL pets";
		return;
	}
}

void Character::deathCheckPets()
{
	int move = 0; //шаг смещения питомцев после смерти 1-го из
	int _livepets = livePets; //только для цикла снизу(так как в цикле кол-во живых питомцев уменьшается)
	for (int i = 0; i < _livepets; i++) 
	{
		if (p[i].pet_dead() == false)
		{
			livePets--;
			cout << "\nPet " << i + 1 << " is dead" << endl;
			move++;

		}
		else //смещение живого питомца, если перед ним умер питомец
		{
			p[i - move] = p[i];
		}
	}

	if (livePets == 0) //если все питомцы мертвы, создаем нового автоматически
	{
		cout << "Create a new pet" << endl;
		p[0] = Pet();
		p[0].setpetName();
	}
}

void Character::softStart()
{
	setName(); //имя персонажа при начале игры
	p[0].setpetName(); //имя 1 питомца при начале игры
}