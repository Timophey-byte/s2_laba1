#pragma once
#include "my.h"
#include "conference.h"
#include "string.h"



class Performer : public Conference
{
	
	char* prop[4];

public:

	Performer();
	~Performer();


	char* operator[](int i);

	void print() override;
	
	void edit() override;


};