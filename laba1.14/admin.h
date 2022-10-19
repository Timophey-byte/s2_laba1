#pragma once
#include "my.h"
#include "conference.h"
#include "string.h"



class Admin : public Conference
{

	char* prop[3];

public:

	Admin();
	~Admin();


	char* operator[](int i);

	void print() override;

	void edit() override;


};