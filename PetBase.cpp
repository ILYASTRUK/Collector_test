#include "PetBase.h"
#include <iostream>
using namespace std;


PetBase::PetBase(int* attr) : attrPtr(attr)
{
#ifdef _DEBUG
	cout << "PetBase constructor" << endl;
#endif
}

PetBase::~PetBase()
{
#ifdef _DEBUG
	cout << "PetBase destructor" << endl;
	attrPtr -= rand() % (*attrPtr / 2);
#endif
}