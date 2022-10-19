#pragma once
#include "my.h"

#include "keeper.h"

#include "stdio.h"
#include "conference.h"
#include "performer.h"
#include "admin.h"
#include "prog.h"
#include "string.h"

Keeper::Keeper()
{
	printf("+ Keeper\n");
	size = 0;
	list = nullptr;
}

Keeper::~Keeper()
{
	printf("- Keeper\n");
	for (int i = 0; i < size; i++)
		delete list[i];
}

int Keeper::add() {
	int type = -1;


	while (type < 1 || type > 4)
	{
		printf("EDIT MENU\nLIST OF COMMANDS:\n-1 back to main\n");
		printf("1 add performer\n");
		printf("2 add administrator\n");
		printf("3 add programm\nenter your choice:\n");
		scan("%d", &type);
		if (type == -1)
			return 0;
	}

	Conference* add = new Conference;

	switch (type)
	{
	case 1:
		add = new Performer;
		break;

	case 2:
		add = new Admin;
		break;

	case 3:
		add = new Prog;
		break;

	}

	int originalSize = size;
	size++;

	Conference** created = new Conference * [size];

	for (int i = 0; i < originalSize; i++)
	{
		created[i] = new Conference;
		created[i] = list[i];
	}

	list = created;
	list[size - 1] = add;

	return 0;
};





int Keeper::edit() 
{
	

	return 0;
};

void Keeper::printAll()
{
	printf("\n");
	int  c = 0;
	for (int i = 0; i < size; i++)
	{
		printf("N%d\n", i);
		list[i]->print();
		printf("\n");
		c++;
	}
	if (c == 0)
		printf("no found");
	printf("\n");
}

int Keeper::printTypeMenu()
{
	int type = -1;

	while (type < 1 || type > 4)
	{
		printf("PTINT ALL OF ONE TYPE\nLIST OF COMMANDS:\n-1 back\n");
		printf("1 see all performers\n");
		printf("2 see all administrators\n");
		printf("3 see all programms\nenter your choice:\n");
		scan("%d", &type);
		if (type == -1)
			return 0;
	}
	printAllOfType(type-1);
	return 0;
}

int Keeper::printAllOfType(int t)
{
	int c = 0;
	for (int i = 0; i < size; i++)
	{
		if (list[i]->getType() == t)
		{
			printf("No %d\n", i);
			list[i]->print();
			c++;
		}
	}
	if (c == 0)
		printf("no found");
	printf("\n");
	return 0;
}

void Keeper::printSearchFio()
{
	printf("SEARCH: ");
	char str[1000] = { 0 };
	gets_s(str);
	int c = 0;
	for (int i = 0; i < size; i++)
	{
		Conference* item = list[i];

		if (list[i]->getType() == PERFORMER_T || list[i]->getType() == ADMIN_T)
			if (strcmp((*item)[FIO], str) == 0)
			{
				item->print();
				c++;
			}

	}
	if (c == 0)
		printf("no found");
	printf("\n");
}

void Keeper::printSeachName()
{
	printf("SEARCH: ");
	char str[1000] = { 0 };
	gets_s(str);
	int c = 0;
	for (int i = 0; i < size; i++)
	{
		Conference* item = list[i];

		if (list[i]->getType() == PERFORMER_T || list[i]->getType() == PROGR_T)
			if (strcmp((*item)[NAME], str) == 0)
			{
				item->print();
				c++;
			}

	}
	if (c == 0)
		printf("no found");
	printf("\n");
}


int Keeper::searchPrint()
{
	int mode = -1;
	printf("EXIT SEACH -1\nSEARCH BY FIO 1\nSEARCH BY TEXT NAME\n");

	while (true)
	{
		scan("%d", &mode);
		switch (mode)
		{
		default:
			printf("invalid input\n");
			break;
		case -1:
			return 0;
		case 1:
			printSearchFio();
			break;
		case 2:
			printSeachName();
			break;

		}
	}

}


