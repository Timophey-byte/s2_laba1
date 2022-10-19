#pragma once
#include "my.h"
#include "conference.h"
#include "string.h"



class Prog : public Conference
{

	char* prop[3];

public:

	Prog();
	~Prog();


	char* operator[](int i);

	void print() override;

	void edit() override;


};