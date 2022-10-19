#pragma once
#include "my.h"
#include "conference.h"
#include "string.h"



class Performer : public Conference
{
	
	char* prop[4];
	int takeIdOfProp() override;

	int setProp(int i) override;

public:

	Performer();
	~Performer();

	char* operator[](int i);

	void print() override;
	
};