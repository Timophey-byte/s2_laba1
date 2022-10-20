#pragma once
#define _CRT_SECURE_NO_WARNINGS
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
	setChangeSaved(false);
	printf("+ Keeper\n");
	size = 0;
	list = nullptr;
	strcpy(filePath, (char*)"file.txt");
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
	setChangeSaved(false);
	return 0;
};


int Keeper::delit() {
	int n = -1;
	if (size == 0)
	{
		printf("no records found\n");
		return 0;
	}

	while (n < 1 || n >= size)
	{
		printf("enter id of element or -1 to exit or %d to see all\n", size);
		scan("%d", &n);
		if (n == size)
			printAll();
		if (n == -1)
			return 0;
	}

	delete list[n];
	for (int i = n; i < size; i++)
	{
		list[i] = list[i + 1];
	}

	size -= 1;
	setChangeSaved(false);
	return 0;
};





int Keeper::edit() 
{
	int id = -1;
	if (size == 0)
	{
		printf("no records found\n");
		return 0;
	}
	while (id < 0 || id >= size)
	{
		printf("there are %d elements added\n", size);
		printf("enter id of element or -1 to exit or %d to see all\n", size);
		scan("%d", &id);
		if (id == -1)
			return 0;
		if (id == size)
			printAll();
	}
	try {
		list[id]->edit();
	}
	catch(char* m)
	{
		throw m;
	}
	setChangeSaved(false);
	return 0;
};

void Keeper::setChangeSaved(bool v)
{
	ChangeSaved = v;
}

bool Keeper::isChangeSaved()
{
	return ChangeSaved;
}

void Keeper::printAll()
{
	printf("\n");
	int  c = 0;
	for (int i = 0; i < size; i++)
	{
		printf("N%d\n", i+1);
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
		printf("PRINT ALL OF ONE TYPE\nLIST OF COMMANDS:\n-1 back\n");
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
			printf("No %d\n", i+1);
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
				printf("No %d\n", i + 1);
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
				printf("No %d\n", i + 1);
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

char* Keeper::getFilePath()
{
	return filePath;
}

void Keeper::setFilePath(char* p)
{
	strcpy(filePath, p);
}

void Keeper::setPath()
{
	printf("now file path is: %s", getFilePath());
	printf("enter new file path:\n");
	char path[MAXLEN + 1];
	try { 
		s_get(path); 
	}
	catch (char* m)
	{
		throw m;
	}

	setFilePath(path);

}

void Keeper::save()
{
	if (size == 0)
	{
		printf("list is empty\n");
		return;
	}

	FILE* fp = fopen(getFilePath(), "w"); fclose(fp);
	if (fp == NULL)
	{
		printf("invalid file path\n");
		return;
	}
	fp = fopen(getFilePath(), "a");
	if (fp == NULL)
	{
		printf("invalid file path\n");
		return;
	}
	fprintf(fp, "%d\n", size);
	for (int i = 0; i < size; i++)
	{
		list[i]->filePrint(fp);
	}

	fclose(fp);
}

void Keeper::load()
{

	FILE* fp = fopen(getFilePath(), "r"); 
	if (fp == NULL)
	{
		printf("invalid file path\n");
		return;
	}
	int N = 0;
	fscanf(fp, "%d\n", &N);
	if (N <= 0)
	{
		throw (char*)"Data corrupted";
	}

	size = N;
	Conference** created = new Conference * [N];

	Conference* add = new Conference;

	for (int i = 0; i < size; i++)
	{
		int type = 0;
		fscanf(fp, "%d\n", &type);
		switch (type)
		{
		case PERFORMER_T:
			add = new Performer;
			break;

		case ADMIN_T:
			add = new Admin;
			break;

		case PROGR_T:
			add = new Prog;
			break;

		default:
			fclose(fp);
			throw (char*)"Data corrupted";
		}
		add->setType(type);
		int prop_num = 3;
		if (type == PERFORMER_T) prop_num = 4;
		for (int j = 0; j < prop_num; j++)
		{
			char str[200];
			try { s_getf(fp, str); }
			catch (char* s)
			{
				throw s;
			}
			add->setProp(j, str);
		}

		created[i] = add;

	}

	list = created;

	fclose(fp);
}

int Keeper::fileMenu()
{
	int mode = -1;
	
	while (true)
	{
		printf("FILE SETTINGS\nEXIT -1\nSET PATH 0\nSAVE 1\nLOAD 2\nenter command\n");
		scan("%d", &mode);
		switch (mode)
		{
		default:
			printf("invalid input\n");
			break;
		case -1:
			return 0;
		case 0:
			try { setPath(); }
			catch(char* m)
			{
				throw m;
			}
			printf("now path is %s\n", getFilePath());
			break;
		case 1:
			save();
			setChangeSaved(true);
			break;
		case 2:
			try {
				load();
				}
			catch (char* m)
			{
				throw m;
			}
			setChangeSaved(false);
			break;

		}
	}

}
