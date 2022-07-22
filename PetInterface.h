#pragma once
#include "Cat.h";
class PetInterface
{

public:
	PetInterface();
	~PetInterface();

	virtual void play() = 0;
	virtual void passiveStep() = 0;
};
