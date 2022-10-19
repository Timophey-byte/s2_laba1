#pragma once
#include "stdio.h"
#include "malloc.h"

int scan(const char* _f, void* _x);

char** newStrList(int n);

void setListZero(char** arr, int n);
