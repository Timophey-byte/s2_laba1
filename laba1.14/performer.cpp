#define _CRT_SECURE_NO_WARNINGS
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


int Performer::takeIdOfProp()
{
	printf("there are 4 properties you can edit\n");
	print();
	int id = -1;

	while (id < 0 || id > 4)
	{
		printf("enter id of propertie or -1 to exit\n");
		scan("%d", &id);
		if (id == -1)
			return -1;
	}

	return id;
}

int Performer::setProp(int i)
{
	char s[MAXLEN] = { '\0' };
	printf("new value\n");
	try {
		s_get(s);
	}
	catch (char* msg)
	{
		throw msg;
	}

	strcpy(prop[i], s);

	return 0;
}



