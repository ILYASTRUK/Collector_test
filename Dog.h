#pragma once
#include "PetInterface.h";

class Dog : public PetInterface, public Character, public Pet
{
private:

public:
	Dog();
	~Dog();

	// Унаследовано через PetInterface
	virtual void play() override;

	virtual void passiveStep() override;

};