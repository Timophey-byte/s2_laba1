#pragma once
#include "stdio.h"
#include "conference.h"
#include "my.h"
#include "string.h"

class Keeper
{
	bool ChangeSaved;
	int size;
	Conference** list;
	void printSearchFio();
	
	void printSeachName();
	char filePath[MAXLEN];

	void setFilePath(char* p);
	char* getFilePath();

public:

	Keeper();
	~Keeper();

	void setChangeSaved(bool v);
	bool isChangeSaved();

	int add();
	int edit();
	int delit();

	void printAll();
	int printAllOfType(int t);
	int printTypeMenu();

	int searchPrint();

	int fileMenu();
	
	void setPath();
	

	void save();
	void load();


};
