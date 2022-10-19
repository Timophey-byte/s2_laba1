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
	printf("FIO %s\n", prop[FIO]);
	printf("POST %s\n", prop[TITLE]);
	printf("RESPOSIBILITY %s\n", prop[RESP]);

}

