#define PAN_SIZE 19
#include<stdio.h>
int team02(int pan[][PAN_SIZE], int* px, int* py)
{
	*px = rand() % 19;
	*py = rand() % 19;
	return 0;	
}

