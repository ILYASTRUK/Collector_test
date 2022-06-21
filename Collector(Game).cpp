#include <iostream>
#include <ctime>
#include"Pet.h"
#include"Character.h"

using namespace std;


int main()
{
	Character men;
	int checkMoney;
	int choice; //выбор действия в switch
	enum class SwitchChoice
	{
		Exit, Play_pet, Eat_pet, Sleep_pet, Eat_character, Sleep_character, Work_character, Parameters, Buy
	};

	men.setName(); //имя персонажа при начале игры
	men.p[0].setpetName(); //имя 1 питомца при начале игры

	while (true)
	{
		int move = 0; //шаг смещения питомцев после смерти 1-го из
		int _livepets = men.getlivePetsCount(); //только для цикла снизу
		for (int i = 0; i < _livepets; i++)
		{
			if (men.p[i].pet_dead() == false)
			{
				men.minuslivePets();
				cout << "\nPet " << i+1 << " is dead" << endl;

				//смещение питомцев в массиве после смерти 1-го из них
				if (men.p[i].getStatus() == false)
				{
					move++;
					
				}
				else
				{
					men.p[i-move] = men.p[i];
				}
			}
		}

		if (men.character_dead() == false)
		{
			cout << "Character is dead" << endl;
			men.finalResult();
			return false;
		}

		if (men.getlivePetsCount() == 0) //если все питомцы мертвы, создаем нового автоматически
		{
			cout << "Create a new pet" << endl;
			men.p[0] = Pet();
			men.p[0].setpetName();
		}


		cout << "\n-----------------------------------------------------------------------------------------" << endl;
		cout << "1-Play(Pet)\n2-Eat(Pet)\n3-Sleep(Pet)\n4-Eat(Character)\n5-Sleep(Character)\n6-Work(Character)\n7-Parameters\n8-Buy a new pet\n0-Exit" << endl;
		cout << "-----------------------------------------------------------------------------------------" << endl;
		int number; // выбор номера питомца
		cin >> choice;
		system("cls");

		switch (static_cast<SwitchChoice>(choice))
		{
		case (SwitchChoice::Play_pet):
			for (int i = 0; i < men.getlivePetsCount(); i++)
			{
				cout << "Pet №" << i << ": " << men.p[i].getName() << ", " << "Fun -->" << men.p[i].getFun() << endl;
			}
			cout << "Choose a pet: ";
			cin >> number;
			men.p[number].play();
			men.character_fun();

			for (int i = 0; i < men.getlivePetsCount(); i++) //для "шагов"
			{
				if (i == (number)) //проверка чтобы повзаимодействовать с нужным питомцем
				{
					step(men.p[i], men, static_cast<int>(param::play), static_cast<int>(param::play));
				}
				else
				{
					step(men.p[i], men, static_cast<int>(param::inactivity), static_cast<int>(param::none));
				}
			}
			break;

		case (SwitchChoice::Eat_pet):
			for (int i = 0; i < men.getlivePetsCount(); i++)
			{
				cout << "Pet №" << i << ": " << men.p[i].getName() << ", " << "Hunger -->" << men.p[i].getHunger() << endl;
			}
			cout << "Choose a pet: ";
			cin >> number;
			men.p[number].eat();
			checkMoney = men.spend_money();
			if (checkMoney == 0)
			{
				for (int i = 0; i < men.getlivePetsCount(); i++) //для "шагов"
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

		case (SwitchChoice::Sleep_pet):
			for (int i = 0; i < men.getlivePetsCount(); i++)
			{
				cout << "Pet №" << i << ": " << men.p[i].getName() << ", " << "Cheerfulness -->" << men.p[i].getCheerfulness() << endl;
			}
			cout << "Choose a pet: ";
			cin >> number;
			men.p[number].sleep();
			for (int i = 0; i < men.getlivePetsCount(); i++) //для "шагов"
			{
				if (i == number)
				{
					step(men.p[i], men, static_cast<int>(param::sleep), static_cast<int>(param::inactivity));
				}
				else
				{
					step(men.p[i], men, static_cast<int>(param::inactivity), static_cast<int>(param::none));
				}
			}
			break;

		case (SwitchChoice::Eat_character):
			men.eat();
			checkMoney = men.spend_money();
			if (checkMoney == 0)
			{
				for (int i = 0; i < men.getlivePetsCount(); i++) //для "шагов"
				{
					if (i < 1)
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

		case (SwitchChoice::Sleep_character):
			men.sleep();
			for (int i = 0; i < men.getlivePetsCount(); i++) //для "шагов"
			{
				if (i < 1) //для того чтобы поработать 1 раз
				{
					step(men.p[i], men, static_cast<int>(param::inactivity), static_cast<int>(param::sleep));
				}
				else
				{
					step(men.p[i], men, static_cast<int>(param::inactivity), static_cast<int>(param::none));
				}
			}

			break;

		case (SwitchChoice::Work_character):
			men.work();
			for (int i = 0; i < men.getlivePetsCount(); i++) //для "шагов"
			{
				if (i < 1) //для того чтобы поработать 1 раз
				{
					step(men.p[i], men, static_cast<int>(param::inactivity), static_cast<int>(param::work));
				}
				else
				{
					step(men.p[i], men, static_cast<int>(param::inactivity), static_cast<int>(param::none));
				}
			}
			break;

		case (SwitchChoice::Parameters):
			for (int i = 0; i < men.getlivePetsCount(); i++)
			{
				men.p[i].show();
			}			
			men.show();
			break;

		case (SwitchChoice::Buy):
			men.buyPet();
			int temporaryint;
			temporaryint = men.getlivePetsCount();
			break;

		case (SwitchChoice::Exit):
			return false;

		default:
			break;
		}
	}
}