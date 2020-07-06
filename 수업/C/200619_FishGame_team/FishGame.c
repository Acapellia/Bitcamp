#include "turboc.h"
#include "fishDefine.h"

int mapWall[WallW][WallH] = { 0 };
int seaweed[10] = { 0 };

int main()
{
	srand((unsigned)time(NULL));
	setcursortype(NOCURSOR);

	FishType ft[TypeNum];
	Fish shark = { 0 };
	init_fish(ft, &shark);

	runningGame(shark, ft);

	gotoxy(0, MapWallHEnd3 + 1);

	return 0;
}
