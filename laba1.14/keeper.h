#pragma once
#include "stdio.h"
#include "conference.h"
#include "my.h"
#include "string.h"

class Keeper
{
	int size;
	Conference** list;
	void printSearchFio();
	
	void printSeachName();

public:

	Keeper();
	~Keeper();

	int add();
	int edit();

	void printAll();
	int printAllOfType(int t);
	int printTypeMenu();

	int searchPrint();

};
