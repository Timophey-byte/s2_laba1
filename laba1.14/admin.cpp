#define _CRT_SECURE_NO_WARNINGS
#include"admin.h"

Admin::Admin()
{
	printf("+ admin\n");
	setType(ADMIN_T);
	setListZero(prop, 3);
}

Admin::~Admin()
{
	printf("- admin\n");
}

char* Admin::operator[](int i)
{
	if (i < 0)
		return nullptr;
	if (i >= 3)
		return nullptr;

	return prop[i];
}


void Admin::print()
{
	printf("1) FIO %s\n", prop[FIO]);
	printf("2) POST %s\n", prop[TITLE]);
	printf("3) RESPOSIBILITY %s\n", prop[RESP]);

}

int Admin::takeIdOfProp()
{
	printf("there are 3 properties you can edit\n");
	print();
	int id = -1;

	while (id <= 0 || id > 3)
	{
		printf("enter id of property or -1 to exit\n");
		scan("%d", &id);
		if (id == -1)
			return -1;
	}

	return id;
}

int Admin::setProp(int i)
{
	char s[MAXLEN] = { '\0' };
	printf("new value\n");
	try {
		s_get(s);
	}
	catch (char* msg)
	{
		throw msg;
	}

	strcpy(prop[i-1], s);

	return 0;
}