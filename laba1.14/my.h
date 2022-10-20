#pragma once
#include "stdio.h"
#include "malloc.h"


#include <crtdbg.h>
#include "stdlib.h"

#define MAXLEN 500

void myInvalidParamHandler(const wchar_t*, const wchar_t*, const wchar_t*, unsigned int, uintptr_t);
int scan(const char* _f, void* _x);

char** newStrList(int n);

void setListZero(char** arr, int n);


void s_get(char* s);
void s_getf(FILE* f, char* s);