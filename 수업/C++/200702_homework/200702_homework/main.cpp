#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

#include "PersonManager.h"
#include "Telinfo.h"
using namespace std;

void main()
{
	int choice = 0;						
	int nPersonNum = 0;

	printf("How many People? : ");
	scanf("%d", &nPersonNum);

	PersonManager pm(nPersonNum);			

	while (1)
	{
		pm.ShowMenu();
		printf("Choose the item : ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			pm.InsertTelInfo(pm.getPersonArr(), pm.getPnum() );
			break;
		case 2:
			pm.DeleteTelInfo(pm.getPersonArr(), pm.getPnum());
			break;
		case 3:
			pm.SearchTelInfo(pm.getPersonArr(), *pm.getPnum());
			break;
		case 4:
			pm.PrintAll(pm.getPersonArr(), *pm.getPnum());
			break;
		case 5:
			delete[] pm.getPersonArr();
			return;
			break;
		default:
			printf("illegal selection.. \n");
			break;
		}
	}

}

