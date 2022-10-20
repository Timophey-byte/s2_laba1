#define _CRT_SECURE_NO_WARNINGS
#include "my.h"
#include "string.h"

int scan(const char* _f, void* _x)
{
	while (1)
	{
		printf("input: ");
		if (scanf(_f, _x) != 1)
			printf("try again\n");
		else
		{
			if (getchar());
			return 1;
		}
		if (getchar());
	}
}
char** newStrList(int n)
{
	char** arr = (char**)calloc(n, sizeof(char*));
	for (int i = 0; i < n; i++)
	{
		arr[i] = (char*)calloc(2, sizeof(char));
	}
	return arr;
}

void setListZero(char** arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = (char*)calloc(4, sizeof(char));
		strcpy(arr[i], "---");
	}
}

void myInvalidParamHandler(const wchar_t*, const wchar_t*, const wchar_t*, unsigned int, uintptr_t)
{

}

void s_get(char* s)
{
	_CrtSetReportMode(_CRT_ASSERT, 0);
	_invalid_parameter_handler oldHandler = _set_invalid_parameter_handler(myInvalidParamHandler);
	if (gets_s(s, MAXLEN) == nullptr)
	{
		_set_invalid_parameter_handler(oldHandler);
		throw (char*)"error: line too short for input\n";
	}
	_set_invalid_parameter_handler(oldHandler);
}

void s_getf(FILE* f, char* s)
{
	_CrtSetReportMode(_CRT_ASSERT, 0);
	_invalid_parameter_handler oldHandler = _set_invalid_parameter_handler(myInvalidParamHandler);
	if (fgets(s, MAXLEN, f) == nullptr)
	{
		_set_invalid_parameter_handler(oldHandler);
		throw (char*)"error: line too short for input\n";
	}
	_set_invalid_parameter_handler(oldHandler);
}