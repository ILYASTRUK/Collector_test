#include <iostream>
#include <ctime>
#include <iomanip>
#include"Pet.h"
#include"Character.h" // добавил, так как из-за того что в pet.h сделал "class character" вместо инклюда

using namespace std;

void Pet::pet_step(int _param)
{
	if (static_cast<int>(param::play) == _param)
	{
		hunger -= 8;
		cheerfulness -= 8;
	}
	if (static_cast<int>(param::eat) == _param)
	{
		cheerfulness -= 8;
		fun -= 8;
	}
	if (static_cast<int>(param::sleep) == _param)
	{
		fun -= 8;
		hunger -= 8;
	}
	if (static_cast<int>(param::inactivity) == _param)
	{
		fun -= 8;
		hunger -= 8;
		cheerfulness -= 8;
	}
	if (static_cast<int>(param::none) == _param)
	{

	}

	timer += 25;

	if (timer >= 100)
	{
		age++;
		int buf = timer;  //остаток после взросления(>100)
		timer = buf - 100;
	}

	pet_dead();
}

Pet::Pet() : hunger(100), fun(100), cheerfulness(100), name("Ron"), gender("boy"), age(0), status(true), number(+1)
{
#ifdef _DEBUG
	cout << "Pet constructor" << endl;
#endif
}

Pet::~Pet()
{
#ifdef _DEBUG
	cout << "Pet destructor" << endl;
#endif
}

bool Pet::pet_dead() //проверка на смерть питомца
{
	if (hunger <= 10)
	{
		srand(time(0));
		int rand_num = 1 + rand() % 100;
		int deadChance = (10 - hunger) * 100;
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

	if (fun <= 10)
	{
		srand(time(0));
		int rand_num = 1 + rand() % 100;
		int deadChance = (10 - fun) * 100;
		if (rand_num <= deadChance)
		{
			status = false;
			cout << "Pet is dead" << endl;
			return false;
		}
		else
		{
			return true;
		}
	}

	if (cheerfulness <= 10)
	{
		srand(time(0));
		int rand_num = 1 + rand() % 100;
		int deadChance = (10 - cheerfulness) * 100;
		if (rand_num <= deadChance)
		{
			status = false;
			cout << "Pet is dead" << endl;
			return false;
		}
		else
		{
			return true;
		}
	}
}

void Pet::play()
{
	cout << setw(17) << name << setw(9) << "fun:" << setw(5) << fun << "->";
	srand(time(0));
	fun += 1 + rand() % 25;

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

void Pet::eat()
{
	cout << setw(17) << name << setw(9) << "hunger:" << setw(5) << hunger << "->";
	srand(time(0));
	hunger += 1 + rand() % 25;
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

void Pet::sleep()
{
	cout << setw(17) << name << setw(9) << "cheerfulness:" << setw(5) << cheerfulness << "->";
	srand(time(0));
	cheerfulness += 1 + rand() % 25;
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

int Pet::getHunger()
{
	return hunger;
}

int Pet::getFun()
{
	return fun;
}

int Pet::getCheerfulness()
{
	return cheerfulness;
}
std::string Pet::getName()
{
	return name;
}
void Pet::setName()
{

		cout << "\n1 - Set a name\n2 - Generate a name" << endl;
		int num = 0;
		cin >> num;
		switch (num)
		{
		case 1:
			cout << "\nName a pet: ";
			cin >> name;
			//randName[--number] = name; не  могу так как констуркторы все создатутся сразу и счетчик будет большой, а не по порядку
			cout << "New pet name is: " << name << endl;
			break;
		case 2:
			//реализация генерации
			randName[0] = "Victor";
			randName[1] = "Torvic";

			if (randName[1] == "0")
			{
				cout << "Blocked";
			}
			else //рандомайзер из заполненных ячеек массива добавить
			{
				string sBuf;
				int iBuf;
				iBuf = randName[0].length() / 2;
				sBuf.insert(0, randName[0], 0, iBuf);
				iBuf = randName[1].length() / 2;
				sBuf.insert(sBuf.length(), randName[1], 0, iBuf);
				randName[2] = sBuf;
				name = randName[2];
				cout << "New pet name is: " << name << endl;
			}
			cout <<"\n" << randName[0] << "__" << randName[1] << "__" << randName[2];
			//----------------------------------------------------------
			break;
		default:
			break;
		}
	}
	

void Pet::show()
{
	
	cout << "\tPet's characteristics" << endl;
	cout << "Name: " << name << endl << "Gender: " << gender << endl << "Number:" << number << endl << "Age: " << age << endl << "Status: " << status << endl << "Hunger: " << hunger << endl << "Fun: " << fun << endl << "Cheerfulness: " << cheerfulness << endl;
	cout << "--------------------------------------" << endl;
}
void Pet::finalResult()
{
	cout << setw(9) << "Pet count:" << setw(4) << number << setw(5) << endl;
}

void step(Pet& pet, Character& men, int pet_check, int men_check)
{
	pet.pet_step(pet_check);
	men.character_step(men_check);
}