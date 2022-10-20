#define _CRT_SECURE_NO_WARNINGS
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
	printf("1) DAY %s\n", prop[DAY]);
	printf("2) TIME %s\n", prop[TIME]);
	printf("3) NAME %s\n", prop[NAME]);
}

void Prog::filePrint(FILE* f)
{
	fprintf(f, "%d\n", getType());
	for (int i = 0; i < 3; i++)
		fprintf(f, "%s\n", prop[i]);
}


int Prog::takeIdOfProp()
{
	printf("there are 3 properties you can edit\n");
	print();
	int id = -1;

	while (id <= 0 || id > 3)
	{
		printf("enter id of property or -1 to exit\n");
		scan("%d", &id);
		if (id == -1)
			return -1;
	}

	return id;
}

int Prog::setProp(int i)
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

	strcpy(prop[i - 1], s);

	return 0;
}

int Prog::setProp(int i, char* s)
{
	strcpy(prop[i], s);
	return 0;
}