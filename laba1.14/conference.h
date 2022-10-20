#pragma once
#include "stdio.h"
#define PERFORMER_T 0
#define ADMIN_T 1
#define PROGR_T 2

#define FIO 0
#define ORG 1
#define NAME 2
#define ABS 3

#define DAY 0
#define TIME 1
#define NAME 2

#define TITLE 1
#define RESP 2

class Conference
{
	int type;
	virtual int takeIdOfProp() { return 0; };

	
public:

	Conference();
	~Conference();

	virtual void print() {};
	virtual void filePrint(FILE* f) {};
	virtual char* operator[](int i) { return nullptr; };
	virtual int setProp(int i) { return 0; };
	virtual int setProp(int i, char* s) { return 0; };

	int edit();

	void setType(int);
	int getType();
};