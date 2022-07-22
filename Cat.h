#pragma once
//class PetInterface;
#include "PetInterface.h"
#include "Character.h"
#include "Pet.h"

class Cat : public PetInterface, public Character, public Pet
{
private:

public:
	Cat();
	~Cat();

	// Унаследовано через PetInterface
	virtual void play() override;

	virtual void passiveStep() override;

};