#pragma once
#include "PetInterface.h"

class MyClass : public PetInterface, public Character, public Pet
{
private:

public:
	MyClass ();
	~MyClass ();

	// Унаследовано через PetInterface
	virtual void play() override;

	virtual void passiveStep() override;

};