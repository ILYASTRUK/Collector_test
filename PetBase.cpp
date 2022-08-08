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
	srand(time(0));
	*attrPtr -= rand() % (*attrPtr / 2);

#ifdef _DEBUG
	cout << "PetBase destructor" << endl;
#endif
}