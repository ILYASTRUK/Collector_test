#pragma once
#include "PetInterface.h"

class MyClass : public PetInterface, public Character, public Pet
{
private:

public:
	MyClass ();
	~MyClass ();

	// ������������ ����� PetInterface
	virtual void play() override;

	virtual void passiveStep() override;

};