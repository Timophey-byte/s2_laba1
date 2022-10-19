#include"prog.h"

Prog::Prog()
{
	printf("+ programm\n");
	setType(PROGR_T);
	setListZero(prop, 3);
}

Prog::~Prog()
{
	printf("- programm\n");
}

char* Prog::operator[](int i)
{
	if (i < 0)
		return nullptr;
	if (i >= 3)
		return nullptr;

	return prop[i];
}


void Prog::print()
{
	printf("DAY %s\n", prop[DAY]);
	printf("TIME %s\n", prop[TIME]);
	printf("NAME %s\n", prop[NAME]);
}


