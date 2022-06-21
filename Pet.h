#pragma once
//#include"Character.h"
class Character;

class Pet
{
private:	
	int fun;	//0-100
	int cheerfulness;	//0-100
	int hunger;  //0-100
	std::string name;
	static int namesCount; //������� ��� ���� � �������
	static std::string randName[100]; //��� ������� ����
	std::string gender;
	int age;
	bool status; //true-live, fouls - dead
	int timer = 0; //����� �����

	void pet_step(int);
public:
	Pet();
	~Pet();
	bool pet_dead(); //�������� �� ������ �������
	void play();
	void eat();
	void sleep();
	void show();
	int getHunger();
	int getFun();
	int getCheerfulness();
	bool getStatus();
	void setpetName();
	std::string getName();

	friend void step(Pet& pet, Character& men, int pet_check, int men_check);
};