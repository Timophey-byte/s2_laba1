#include"performer.h"

Performer::Performer()
{
	printf("+ performer\n");
	setType(PERFORMER_T);
	setListZero(prop, 4);
}

Performer::~Performer()
{
	printf("- performer\n");
}

char* Performer::operator[](int i)
{
	if (i < 0)
		return nullptr;
	if (i >= 4)
		return nullptr;
	
	return prop[i];
}


void Performer::print()
{
	printf("FIO %s\n", prop[FIO]);
	printf("ORGANISATION %s\n", prop[ORG]);
	printf("NAME %s\n", prop[NAME]);
	printf("ABSTRACT %s\n\n", prop[ABS]);
}




void Performer::edit()
{
	// TODO
}

