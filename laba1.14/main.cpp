#include "stdio.h"
#include "my.h"
#include "keeper.h"

void list()
{
	printf("\n\tlist of main commands:\n");
	printf("0 exit programm\n");
	printf("1 print choice\n");
	printf("2 search\n");
	printf("3 add new\n");
	printf("4 edit one item\n");
	printf("5 delete one item\n");
	printf("10 open file settings (save, load, change path)\n");
	printf("\n");
}


int main()
{
	Keeper conf;

	int t = 0;
	while (1)
	{
		list();
		printf("enter menu command:\n");
		scan("%d", &t);
		switch (t)
		{
		case 0:
			return 0;

		case 1:
		{
			int t2 = 0;
			while (t2 == 0)
			{
				printf("print command list:\n-1 back\n1 print all\n2 choose type to print\n");
				scan("%d", &t2);
				switch (t2)
				{
				case -1:
					break;
				case 1:
					conf.printAll();
					t2 = 0;
					break;
				case 2:
					conf.printTypeMenu();
					t2 = 0;
					break;
				default:
					printf("no such command\n");
					t2 = 0;
					break;
				}
			}
		}
			break;

		case 2:
			conf.searchPrint();
			break;
		
		case 3:
			conf.add();
			break;
		
		case 4:
			try {
				conf.edit();
			}
			catch (char* msg)
			{
				printf("exeption: %s\n", msg);
			}
			break;
		
		case 5:
			conf.delit();
			break;
		

		case 10:
			try {
				conf.fileMenu();
			}
			catch (char* msg)
			{
				printf("exeption: %s\n", msg);
			}
			break;


		default:
			printf("no such command\n");
				break;
		}

	}


	return 0;

}