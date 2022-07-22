#pragma once
class PetBase
{
private:
	int* attrPtr;
	PetBase* petbase[];
public:
	PetBase(int* attr);
	virtual ~PetBase();
};