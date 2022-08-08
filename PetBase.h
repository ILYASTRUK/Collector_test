#pragma once
class PetBase
{
private:
	int* attrPtr;
public:
	PetBase(int* attr);
	virtual ~PetBase();
};