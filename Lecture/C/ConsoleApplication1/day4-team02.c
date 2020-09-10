#define PAN_SIZE 19

int team02(int pan[][PAN_SIZE], int* px, int* py)
{
	*px = rand() % PAN_SIZE;
	*py = rand() % PAN_SIZE;
	return 0;
}

