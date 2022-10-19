#pragma once
#include "my.h"
#include "conference.h"
#include "string.h"



class Prog : public Conference
{

	char* prop[3];
	int takeIdOfProp() override;

	int setProp(int i) override;

public:

	Prog();
	~Prog();


	char* operator[](int i);

	void print() override;



};