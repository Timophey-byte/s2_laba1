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
public:

	Conference();
	~Conference();

	virtual void print() {};
	virtual char* operator[](int i) { return nullptr; };
	
	virtual void edit() {};

	void setType(int);
	int getType();
};