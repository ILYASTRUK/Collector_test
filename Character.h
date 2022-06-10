#pragma once
#include"Pet.h"
//class Pet;
int petsCount = 0;  //global iterator
enum class param : unsigned short 
{
	play = 0x00001, eat = 0x00010, sleep = 0x00011, inactivity = 0x00100, work = 0x00101, none = 0x00111
};

class Character
{
private:
	int hunger;  //0-100
	int fun;	//0-100
	int cheerfulness;	//0-100
	std::string name;
	int age;
	bool status; //true-live, fouls - dead
	int money = 0;
	int timer = 0;
	int livePets = 0;	

	void character_step(int);

public:
	Pet p[5];

	Character();
	~Character();
	int spend_money();
	void eat();
	void sleep();
	void work();
	void character_fun(); //одновременно с методом play() питомца
	void show();
	bool character_dead(); //проверка на смерть персонажа
	void finalResult();

	void setName();
	int getpetsCount();
	void buyPet();

	friend void step(Pet& pet, Character& men, int pet_check, int men_check);
};