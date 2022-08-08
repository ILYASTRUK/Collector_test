#include <iostream>
#include <ctime>
#include"Pet.h"
#include"Character.h"
#include"PetBase.h"

using namespace std;

int getPetNumber(Character& men)
{
	int number;

	while (true) //input check (number of a living pet)
	{
		cout << "Choose a pet: ";
		cin >> number;
		if (number >= 0 && number <= men.getlivePetsCount())
		{
			break;
		}
		else
		{
			cout << "Wrong input!!!" << endl;
			cout << "TRY AGAIN" << endl;
			cin.clear();
			cin.ignore(32767, '\n');
		}
	}
	
	return number;
}


int main()
{
	int va = 6;
	PetBase t(&va);

	Character men;
	
	int checkMoney;
	int choice; //action choice in switch

	men.softStart(); //initial data input

	while (true)
	{
		if (men.character_dead() == false)
		{
			cout << "Character is dead" << endl;
			men.finalResult();
			return false;
		}

		men.deathCheckPets();

		cout << "\n-----------------------------------------------------------------------------------------" << endl;
		cout << "1-Play(Pet)\n2-Eat(Pet)\n3-Sleep(Pet)\n4-Eat(Character)\n5-Sleep(Character)\n6-Work(Character)\n7-Parameters\n8-Buy a new pet\n0-Exit" << endl;
		cout << "-----------------------------------------------------------------------------------------" << endl;
		int number; //choice of pet number
		cin >> choice;
		system("cls");

		switch (static_cast<SwitchChoice>(choice))
		{
		case (SwitchChoice::Play_pet):
			men.printStatOfPet(Pet::petAttribute::FUN);

			number = getPetNumber(men);

			men.actionStep(param::play, param::play, number);

			break;

		case (SwitchChoice::Eat_pet):

			checkMoney = men.spend_money(); //check money "0" - have, "1" - haven't
			
			if (checkMoney == 0)
			{
				men.printStatOfPet(Pet::petAttribute::HUNGER);

				number = getPetNumber(men);

				men.actionStep(param::eat, param::inactivity, number);
			}
			
			break;

		case (SwitchChoice::Sleep_pet):

			men.printStatOfPet(Pet::petAttribute::CHEERFULNESS);

			number = getPetNumber(men);

			men.actionStep(param::sleep, param::inactivity, number);

			break;

		case (SwitchChoice::Eat_character):
			men.eat();
			checkMoney = men.spend_money();

			if (checkMoney == 0)
			{
				men.actionStep(param::eat);
			}

			break;

		case (SwitchChoice::Sleep_character):

			men.actionStep(param::sleep);

			break;

		case (SwitchChoice::Work_character):

			men.actionStep(param::work);

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