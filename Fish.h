#pragma once
#include "PetInterface.h"

class Fish : public PetInterface, public Character, public Pet
{
private:

public:
	Fish();
	~Fish();


	// ������������ ����� PetInterface
	virtual void play() override;

	virtual void passiveStep() override;

};