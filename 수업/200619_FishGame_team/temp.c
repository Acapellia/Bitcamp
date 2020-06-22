#include "turboc.h"

#define WallW   27 // 행
#define WallH   57 // 열
#define MAXFISH 10
int mapWall[WallW][WallH] = { 0 };
const int MapWallHStart = 1;
const int MapWallHEnd1 = 24;
const int MapWallHEnd2 = 25; // Level, Score 라인
const int MapWallHEnd3 = 26;
const int MapWallHEnd4 = 56;

#define TypeNum 6

typedef struct _FishType {
	char shape[20];
	char rshape[20];
	int type;
}FishType;
typedef struct _Fish {
	int x, y, Endx;
	int life, dir;
	FishType ft;
}Fish;
typedef struct _Game {
	int time, level, score, eat;
}Game;

void init_fish(FishType ft[TypeNum], Fish* shark) {
	char rshape[TypeNum][20] = {{"<·)<<"},{"<⌒)≪"},{"<·)))<<"}, {"<(°)))><<"},{"<°))))><<"},{"≥(˚˚)≤"} };
	char shape[TypeNum][20] = {{">>(·>"},{"≫(⌒>"},{">>(((·>"}, {">><(((°)>"},{">><((((°>"},{"≥(˚˚)≤"} };
	for (int i = 0; i < TypeNum; i++) {
		strcpy_s(ft[i].shape, 20, shape[i]);
		strcpy_s(ft[i].rshape, 20, rshape[i]);
		ft[i].type = i + 1;
		//printf("%d %s\n", ft[i].type, ft[i].shape);
	}
	strcpy_s(shark->ft.shape, 20, ">°))(1)>≪");
	strcpy_s(shark->ft.rshape, 20, "≫<(1)((°<");
	shark->ft.type = 9;
	shark->x = 10; shark->y = 10; shark->Endx = 10+strlen(shark->ft.rshape);  shark->life = 1;
}
char* LevelUp(char* shape) {
	for (int i = 0; i < strlen(shape); i++)
	{
		if (shape[i] >= '0' && shape[i] <= '9')
		{
			shape[i]++;
		}
	}
	return shape;
}

int seaweed[10] = { 0 };

void make_background(Game* game) {
	// seaweed
	for (int i = 0; i < 10; i++) {
		int seaweedX = rand() % 100 + 5;
		seaweed[i] = seaweedX;
	}
	game->level = 1; game->score = 0; game->eat = 0; game->time = GetTickCount();
}
void draw_background(Game* game) {
	for (int i = 0; i < 10; i++) {
		gotoxy(seaweed[i], MapWallHEnd1 - 2); puts("((");
		gotoxy(seaweed[i], MapWallHEnd1 - 3); puts("))");
		gotoxy(seaweed[i], MapWallHEnd1 - 4); puts("((");
	}
	gotoxy(3, MapWallHEnd1); printf("Level : %d", game->level);
	gotoxy(20, MapWallHEnd1); printf("Score : %d", game->score);
}
void drawWall()
{
	for (int c = 0; c < WallH; ++c) // 행 : H
	{
		mapWall[MapWallHStart][c] = -1;
		mapWall[MapWallHEnd1][c] = -1;
		//mapWall[MapWallHEnd2][c] = -2;
		mapWall[MapWallHEnd3][c] = -1;

		for (int r = 0; r < WallW; ++r) // 열 : W
		{
			mapWall[r][MapWallHStart] = -1;
			mapWall[r][MapWallHEnd4] = -1;
		}
	}

	for (int r = 1; r < WallW; ++r) // 행 : H
	{
		for (int c = 1; c < WallH; ++c) // 열 : W
		{
			printf("%s", (mapWall[r][c] == -1) ? "★" : (mapWall[r][c] == -2) ? "☆" : "  "); // 맵 출력 모양
		}
		putchar('\n');
	}
}

void drawFish2(Fish fish, int c)
{
	if (fish.ft.type == -1) return;
	gotoxy(fish.x, fish.y);
	char temp[20] = { 0 };
	if (c == 0) {
		if (fish.dir == 1) {
			for (int i = 0; i < strlen(fish.ft.shape); i++) { temp[i] = ' '; }
		}
		else {
			for (int i = 0; i < strlen(fish.ft.rshape); i++) { temp[i] = ' '; }
		}
		puts(temp);
	}
	else {
		if (fish.dir == 1) puts(fish.ft.shape);
		if (fish.dir == -1) puts(fish.ft.rshape);
	}

}
void drawFish(int x, int y, char* fish)
{
	gotoxy(x, y);
	puts(fish);
}

Fish create_fish(Game game, Fish fish[MAXFISH], FishType ft[TypeNum], int* fcnt) {
	int w = 100, h = 24;
	int x, y, t;
	x = rand() % (w - 1) + 1;
	y = rand() % (h - 2) + 1;
	t = rand() % 10;
	if (t < 4 && game.level!=1) t = game.level - 1;
	else if (t < 7) t = game.level;
	else if (t < 9 && game.level+1 < 5) t = game.level + 1;
	else if (t < 10 && game.level + 2 < 5) t = game.level + 2;
	fish[*fcnt].x = x; fish[*fcnt].y = y; fish[*fcnt].Endx = x + strlen(ft[t].shape);
	fish[*fcnt].life = 1; fish[*fcnt].dir = rand() % 2 == 0 ? 1 : -1; fish[*fcnt].ft = ft[t-1];
	(*fcnt)++;
	return fish[(*fcnt) - 1];
}
void move_fish(Fish* fish) {
	if (fish->ft.type == -1) return;
	int dirRand = rand() % 20;
	if (dirRand == 0) {
		fish->dir = fish->dir * -1;
	}
	if (fish->dir == -1 && fish->x > 2) {
		fish->x -= 1; fish->Endx -= 1;
	}
	else if (fish->dir == 1 && fish->Endx < 100) {
		fish->x += 1; fish->Endx += 1;
	}
}
int hit(Game* game, Fish* shark, Fish fish[100], int fcnt, int* dcnt) {
	for (int i = 0; i < fcnt; i++) {
		if (fish[i].ft.type == -1) continue;
		if (i == 0) {
			gotoxy(50, MapWallHEnd1);
			printf("                         ");
			gotoxy(50, MapWallHEnd1);
			printf("%d %d %d %d shark %d %d %d", fcnt, fish[i].x, fish[i].y, fish[i].ft.type, shark->Endx, shark->y, game->level);
		}
		if (shark->y == fish[i].y && (fish[i].x <= shark->Endx && shark->Endx <= fish[i].Endx)) {
			if (game->level >= fish[i].ft.type) {
				game->score = game->score + fish[i].ft.type * 10; game->eat++; (*dcnt)++;
				fish[i].ft.type = -1; fish[i].x = 0; fish[i].y = 0; fish[i].Endx = 0;
			}
			else {
				return 1;
			}
		}
	}
	int tlevel = game->level;
	if (game->eat != 0 && game->eat % 10 == 0) {
		game->level = (game->eat / 10) + 1;
	}
	if (tlevel < game->level) {
		strcpy(shark->ft.rshape,LevelUp(shark->ft.rshape));
	}
	return 0;
}
int GameStart(Fish* shark, FishType ft[TypeNum])
{
	setcursortype(NOCURSOR);
	int preX, preY;
	int newX, newY;
	preX = newX = WallW / 2 - strlen(shark->ft.rshape) / 2;
	preY = newY = WallH / 5;

	int w = 100, h = 24;
	int fcnt = 0, dcnt = 0, time = 0;
	Fish fish[100] = { 0 };
	Game game;

	drawWall();
	make_background(&game);

	drawFish(newX, newY, shark->ft.rshape);

	while (1)
	{
		if (fcnt - dcnt < MAXFISH) {
			Fish temp = create_fish(game, fish, ft, &fcnt);
			drawFish2(temp, 1);
		}
		if (time % 2 == 0) {
			for (int i = 0; i < fcnt; i++) {
				drawFish2(fish[i], 0);	move_fish(&fish[i]);	drawFish2(fish[i], 1);
			}
		}
		preX = newX;
		preY = newY;

		if (GetAsyncKeyState(VK_UP) & 0x8000)
			newY--;
		if (GetAsyncKeyState(VK_DOWN) & 0x8000)
			newY++;
		if (GetAsyncKeyState(VK_LEFT) & 0x8000)
			newX--;
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
			newX++;

		if (newX <= 0 || newX + strlen(shark->ft.rshape) >= WallH * 2 - 4)
			newX = preX;
		if (newY <= 0 || newY >= WallW - 4)
			newY = preY;
		if (newX != preX || newY != preY)
		{
			drawFish(preX, preY, "           ");
			drawFish(newX, newY, shark->ft.rshape);
			shark->x = newX; shark->y = newY; shark->Endx = newX + strlen(shark->ft.rshape);
		}
		hit(&game, shark, fish, fcnt, &dcnt);
		draw_background(&game);
		time++;
		delay(10);
	}
	return 0;
}
int main()
{
	srand((unsigned)time(NULL));
	setcursortype(NOCURSOR);

	FishType ft[TypeNum];
	Fish shark = { 0 };
	init_fish(ft, &shark);
	/*for (int i = 0; i < TypeNum; i++) {
		printf("%d %s\n\n", ft[i].type, ft[i].shape);
	}
	printf("Shark : %s\n\n", shark.ft.shape);*/

	GameStart(&shark, ft);

	gotoxy(0, MapWallHEnd3 + 1);
	//LevelUp(shark.ft.shape);

	return 0;
}
