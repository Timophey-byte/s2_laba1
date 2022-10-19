#include "conference.h"

Conference::Conference()
{
	printf("+ conference\n");
	type = 0;
}

Conference::~Conference()
{
	printf("- conference\n");
}

void Conference::setType(int t)
{
	type = t;
}

int Conference::getType()
{
	return type;
}

int Conference::edit()
{
	int id = takeIdOfProp();
	if (id == -1) return 0;
	try {
		setProp(id);
	}
	catch (char* msg)
	{
		throw msg;
	}
	return 0;
}