#pragma once
//#include"Character.h"
class Character;

class Pet
{
private:
	int hunger;  //0-100
	int fun;	//0-100
	int cheerfulness;	//0-100
	std::string name;
	std::string randName[100] = {"0", "0"}; //для массива имен
	std::string gender;
	int age;
	bool status; //true-live, fouls - dead
	int number = 0;  //global iterator?????
	int timer = 0;

	void pet_step(int);
public:
	Pet();
	~Pet();
	bool pet_dead(); //проверка на смерть питомца
	void play();
	void eat();
	void sleep();
	void show();
	void finalResult();

	int getHunger();
	int getFun();
	int getCheerfulness();
	void setName();
	std::string getName();

	friend void step(Pet& pet, Character& men, int pet_check, int men_check);
};
