#include <iostream>
#include <ctime>
#include"Pet.h"
#include"Character.h"



using namespace std;


int main()
{
	Character men;
	int choice;
	int checkMoney;
	//enum class
	//битовые флаги для параметров,которые уменьшаются
	enum class SwitchChoice
	{
		Exit, Play_pet, Eat_pet, Sleep_pet, Eat_character, Sleep_character, Work_character, Parameters, Buy
	};

	cout << men.getpetsCount();
	men.setName(); //имя персонажа при начале игры
	men.p[0].setpetName(); //имя 1 питомца при начале игры

	while (true) //изменить проверку на смерть для каждого питомца
	{
		if (men.p[0].pet_dead() == false)
		{
			cout << "\nPet is dead" << endl;
			cout << "Create a new pet" << endl;
			men.p[0] = Pet();
		}
		if (men.character_dead() == false)
		{
			cout << "Character is dead" << endl;
			men.finalResult();
			men.p[0].finalResult();
			return false;
		}

		cout << "\n-----------------------------------------------------------------------------------------" << endl;
		cout << "1-Play(Pet)\n2-Eat(Pet)\n3-Sleep(Pet)\n4-Eat(Character)\n5-Sleep(Character)\n6-Work(Character)\n7-Parameters\n8-Buy a new pet\n0-Exit" << endl;
		cout << "-----------------------------------------------------------------------------------------" << endl;
		int number;
		cin >> choice;
		system("cls");

		switch (choice)
		{
		case static_cast<int>(SwitchChoice::Play_pet):
			for (int i = 0; i < size(men.p); i++)
			{
				cout << men.p[i].pet_dead() << endl;
				cout << i+1 << ": " << men.p[i].getName() << ", " << "Fun -->" << men.p[i].getFun() << endl;
				
			}
			cout << "Choose a pet: ";
			cin >> number;
			men.p[number].play();
			men.character_fun();

			for (int i = 0; i < size(men.p); i++) //для "шагов"
			{
				if (i == number)
				{
					step(men.p[i], men, static_cast<int>(param::play), static_cast<int>(param::play));
				}
				else
				{
					step(men.p[i], men, static_cast<int>(param::inactivity), static_cast<int>(param::none));
				}
			}

			break;

		case static_cast<int>(SwitchChoice::Eat_pet):
			for (int i = 0; i < size(men.p); i++)
			{
				cout << i + 1 << ": " << men.p[i].getName() << ", " << "Hunger -->" << men.p[i].getHunger() << endl;

			}
			cout << "Choose a pet: ";
			cin >> number;
			men.p[number].eat();
			checkMoney = men.spend_money();
			if (checkMoney == 0)
			{
				for (int i = 0; i < size(men.p); i++) //для "шагов"
				{
					if (i == number)
					{
						step(men.p[i], men, static_cast<int>(param::eat), static_cast<int>(param::inactivity));
					}
					else
					{
						step(men.p[i], men, static_cast<int>(param::inactivity), static_cast<int>(param::none));
					}
				}
			}
			break;

		case static_cast<int>(SwitchChoice::Sleep_pet):
			for (int i = 0; i < size(men.p); i++)
			{
				cout << i + 1 << ": " << men.p[i].getName() << ", " << "Cheerfulness -->" << men.p[i].getCheerfulness() << endl;

			}
			cout << "Choose a pet: ";
			cin >> number;
			men.p[number].sleep();
			for (int i = 0; i < size(men.p); i++) //для "шагов"
			{
				if (i == number)
				{
					step(men.p[i], men, static_cast<int>(param::sleep), static_cast<int>(param::play));
				}
				else
				{
					step(men.p[i], men, static_cast<int>(param::inactivity), static_cast<int>(param::none));
				}
			}
			break;

		case static_cast<int>(SwitchChoice::Eat_character):
			men.eat();
			checkMoney = men.spend_money();
			if (checkMoney == 0)
			{
				for (int i = 0; i < size(men.p); i++) //для "шагов"
				{
					if (i == number)
					{
						step(men.p[i], men, static_cast<int>(param::inactivity), static_cast<int>(param::eat));
					}
					else
					{
						step(men.p[i], men, static_cast<int>(param::inactivity), static_cast<int>(param::none));
					}
				}
			}
			break;

		case static_cast<int>(SwitchChoice::Sleep_character):
			step(men.p[0], men, static_cast<int>(param::inactivity), static_cast<int>(param::sleep));
			men.sleep();
			break;

		case static_cast<int>(SwitchChoice::Work_character):
			men.work();
			for (int i = 0; i < size(men.p); i++) //для "шагов"
			{
				if (i == number)
				{
					step(men.p[i], men, static_cast<int>(param::inactivity), static_cast<int>(param::work));
				}
				else
				{
					step(men.p[i], men, static_cast<int>(param::inactivity), static_cast<int>(param::none));
				}
			}
			break;

		case static_cast<int>(SwitchChoice::Parameters):
			for (int i = 0; i < size(men.p); i++)
			{
				men.p[i].show();
			}			
			men.show();
			break;

		case static_cast<int>(SwitchChoice::Buy):
			cout << "Coming soon" << endl;

			break;

		case static_cast<int>(SwitchChoice::Exit):
			return false;

		default:
			break;
		}
	}
}