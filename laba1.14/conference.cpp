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