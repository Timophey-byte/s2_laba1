#pragma once
#include "my.h"
#include "conference.h"
#include "string.h"



class Admin : public Conference
{

	char* prop[3];
	int takeIdOfProp() override;

	int setProp(int i) override;
	int setProp(int i, char*) override;
public:

	Admin();
	~Admin();

	void filePrint(FILE* f) override;
	char* operator[](int i);

	void print() override;


};