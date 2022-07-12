#include <iostream>
#include <ctime>
#include <iomanip>
#include"Pet.h"
#include"Character.h" // added, because in pet.h do "class character" instead "include"

using namespace std;
//definition static variable, so that all exemplar of class can "use" them
int Pet::namesCount = 6;
string Pet::randName[100] = { "test" };

void Pet::pet_step(int _param)
{
	param action = static_cast<param>(_param);
	if (param::play == action)
	{
		hunger -= 8;
		cheerfulness -= 8;
		play();
	}
	if (param::eat == action)
	{
		cheerfulness -= 8;
		fun -= 8;
		eat();
	}
	if (param::sleep == action)
	{
		fun -= 8;
		hunger -= 8;
		sleep();
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
		int buf = timer;  //the balance after growing up(>100)
		timer = buf - 100;
	}
}

Pet::Pet() : hunger(100), fun(100), cheerfulness(100), name("test"), gender("boy"), age(0), status(true)
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

bool Pet::pet_dead()
{
	if (hunger < 10)
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

	if (fun < 10)
	{
		srand(time(0));
		int rand_num = 1 + rand() % 100;
		int deadChance = (10 - fun) * 100;
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

void Pet::play()
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

void Pet::eat()
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

void Pet::sleep()
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

bool Pet::getStatus()
{
	return status;
}

void Pet::setpetName()
{
	randName[0] = "victor";
	randName[1] = "ilya";
	randName[2] = "monitor";
	randName[3] = "lewis";
	randName[4] = "hamilton";
	randName[5] = "valteri";

	string sBuf; //buffer line
	int iBuf; //buffer number of letters
	int name1; //the first name to create
	int name2; //the second name to create

		cout << "\n1 - Set a name\n2 - Generate a name" << endl;
		int num = 0;
		cout << "Your choice: ";
		cin >> num;
		switch (num)
		{
		case 1:
			cout << "\nName a pet: ";
			cin >> name;
			cout << "\nNew pet's name is: " << name << endl;
			break;
		case 2:

			//select random names (index number) from the range of pet names in the array to generate a new name
			srand(time(0));
			name1 =rand() % namesCount;
			name2 =rand() % namesCount;
			iBuf = randName[name1].length() / 2;
			sBuf.insert(0, randName[name1], 0, iBuf);
			iBuf = randName[name2].length() / 2;
			sBuf.insert(sBuf.length(), randName[name2], 0, iBuf);
			name = sBuf;			
			if (namesCount <= 100)
			{
				randName[namesCount] = sBuf;
				namesCount++;
			}

			cout << "\nNew pet's name is: " << name << endl;
			cout << "\nCOUNT: " << namesCount << endl;
			break;
		default:
			break;
		}
	}
	

void Pet::show()
{
	cout << "\tPet's characteristics" << endl;
	cout << "Name: " << name << endl << "Gender: " << gender << endl << "Age: " << age << endl << "Status: " << status << endl << "Hunger: " << hunger << endl << "Fun: " << fun << endl << "Cheerfulness: " << cheerfulness << endl;
	cout << "--------------------------------------" << endl;
	
}

void step(Pet& pet, Character& men, int pet_check, int men_check)
{
	pet.pet_step(pet_check);
	men.character_step(men_check);
}

bool Pet::operator<(Pet& p2)
{
	int petParam1 = fun + cheerfulness + hunger;
	int petParam2 = p2.fun + p2.cheerfulness + p2.hunger;
	if (petParam1 < petParam2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Pet::operator>(Pet& p2)
{
	int petParam1 = fun + cheerfulness + hunger;
	int petParam2 = p2.fun + p2.cheerfulness + p2.hunger;
	if (petParam1 > petParam2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int Pet::operator[](std::string const& attr)
{
	int _attr;
	if (attr == "FUN")
	{
		_attr = 0;
	}

	if (attr == "CHEERFULNESS")
	{
		_attr = 1;
	}

	if (attr == "HUNGER")
	{
		_attr = 2;
	}


	if (_attr == static_cast<int>(petAttribute::FUN))
	{
		return _attr;
	}
	
	if (_attr == static_cast<int>(petAttribute::CHEERFULNESS))
	{
		return _attr;
	}
	
	if (_attr == static_cast<int>(petAttribute::HUNGER))
	{
		return _attr;
	}
}