#pragma once
#include "PetInterface.h";

class Dog : public PetInterface, public Character, public Pet
{
private:

public:
	Dog();
	~Dog();

	// ������������ ����� PetInterface
	virtual void play() override;

	virtual void passiveStep() override;

};