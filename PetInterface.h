#pragma once

class PetInterface
{

public:
	PetInterface();
	~PetInterface();

	virtual void play() = 0;
	virtual void passiveStep() = 0;
};
