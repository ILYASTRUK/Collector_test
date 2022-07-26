#pragma once
#include "PetInterface.h"


class Cat : public PetInterface
{
public:
	Cat();
	~Cat();

	// Унаследовано через PetInterface
	virtual void play() override;

	virtual void passiveStep() override;

};