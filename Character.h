#pragma once
#include"Pet.h"
//class Pet;

enum class param : unsigned short 
{
	play = 0x00001, eat = 0x00010, sleep = 0x00011, inactivity = 0x00100, work = 0x00101, none = 0x00111
};

enum class SwitchChoice
{
	Exit, Play_pet, Eat_pet, Sleep_pet, Eat_character, Sleep_character, Work_character, Parameters, Buy
};

class Character
{
private:
	int hunger;  //0-100
	int fun;	//0-100
	int cheerfulness;	//0-100
	int money = 0;
	std::string name;
	int age;
	bool status; //true-live, fouls - dead
	int timer = 0; //character life time
	int livePets = 0;	
	int petsCount = 0; //total per game
	void character_step(int);
	

public:
	Pet p[5];
	Character();
	~Character();
	int spend_money();
	void eat();
	void sleep();
	void work();
	void character_fun(); //both with Pet's method play() 
	void show(); //current info
	bool character_dead(); //death check
	void finalResult(); //info at the end of game (after character death)
	void setName();
	int getpetsCount();
	int getlivePetsCount();
	void buyPet();
	void deathCheckPets(); 
	void softStart();
	void printStatOfPet(Pet::petAttribute attr);
	void funUp();
	
	//A method to interact with both character and pets
	void actionStep(param petAction, param charAction, int selectedPet);
	
	//A method to interact only with character
	void actionStep(param charAction);

	friend void step(Pet& pet, Character& men, int pet_check, int men_check);

	Pet& operator[](int i);
};