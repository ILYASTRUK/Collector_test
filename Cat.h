#pragma once
#include "PetInterface.h"


class Cat : public PetInterface
{
public:
	Cat();
	~Cat();

	// ������������ ����� PetInterface
	virtual void play() override;

	virtual void passiveStep() override;

};