#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <vector>
using namespace std;

// #define
#define W 50
#define H 25
#define FishCnt 16

// class
class FishType {
public:
	int type;
	int hp;
	FishType() {};
	FishType(int t, int h) { type = t; hp = h; };
	void sharkShape(int x, int y) {
		//printf("%d", this->type);
	};
};
class Fish {
public:
	int x, y, level, dir;
	FishType type;
	Fish() { x = 0; y = 0; };
	Fish(int x, int y, FishType t) {
		this->x = x; this->y = y; this->type = t; this->level = 1;
	};
	Fish(int x, int y, int d, FishType t) {
		this->x = x; this->y = y; this->dir = d; this->type = t;
	};
};

// 함수 선언
void init_screen();
void show_screen();
void draw_fish(int x, int y, int type, int n);
void shark_move(Fish* shark);
void create_fish(int cnum, int tn);
void move_fish();

// 전역 변수
int screen[H + 2][W + 2];
Fish shark = Fish(H / 2, W / 2, FishType(9, 1));
vector<Fish> fish;

// screen 초기화
void init_screen() {
	for (int i = 0; i < H+2; i++) { screen[i][0] = -1; screen[i][W+1] = -1; }
	for (int i = 0; i < W+2; i++) { screen[0][i] = -1; screen[H+1][i] = -1; }
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			screen[i][j] = 0;
		}
	}
}
// screen 보여주기
void show_screen() {
	for (int i = 0; i < H+2; i++) {
		for (int j = 0; j < W+2; j++) {
			if (i == 0 || j == 0 || i == H + 1 || j == W + 1) printf("▩");
			else {
				if (screen[i][j] == 0) printf("  ");
				else if (screen[i][j] == 9) printf("@ ");
				else { printf("* "); }
			}
		}printf("\n");
	}
}
// 물고기 그려주기
void draw_fish(int x, int y, int type, int n) {
	if (type == 1) { screen[x][y] = n; }
	if (type == 2) {
		screen[x][y] = n; screen[x][y + 1] = n;
	}
	if (type == 3) {
		screen[x][y] = n; screen[x][y + 1] = n; screen[x - 1][y + 2] = n; screen[x][y + 2] = n;
	}
	if (type == 4) {
		screen[x][y] = n; screen[x][y + 1] = n; screen[x - 1][y + 2] = n; screen[x + 1][y + 2] = n;
	}
}
// 캐릭터(유저) 움직이기
void shark_move(Fish* shark) {
	int x, y;
	x = shark->x;
	y = shark->y;
	if (_kbhit()) {
		char ch = _getch();
		if (ch == 0xFFFFFFE0) {
			char key = _getch();
			ch = key;
		}
		if (ch == '\r') {
			exit(1);
		}
		else if (ch == 'w' || ch == 'W' || ch == 72) { // up
			if (x > 1) {
				draw_fish(x, y, shark->level, 0); shark->x--; draw_fish(x-1, y, shark->level, shark->type.type);
			}
		}
		else if (ch == 's' || ch == 'S' || ch == 80) { // down
			if (x < H) {
				draw_fish(x, y, shark->level, 0); shark->x++; draw_fish(x + 1, y, shark->level, shark->type.type);
			}
		}
		else if (ch == 'a' || ch == 'A' || ch == 75) { // left
			if (y > 1) {
				draw_fish(x, y, shark->level, 0); shark->y--; draw_fish(x, y-1, shark->level, shark->type.type);
			}
		}
		else if (ch == 'd' || ch == 'D' || ch == 77) { // right
			if (y < W) {
				draw_fish(x, y, shark->level, 0); shark->y++; draw_fish(x, y+1, shark->level, shark->type.type);
			}
		}

	}
}
// 물고기(적) 생성하기
void create_fish(int cnum, int tn) {
	for (int i = 0; i < cnum; i++) {
		int x = rand() % (H - 1) + 1;
		int y = rand() % (W - 1) + 1;
		int type = rand() % tn + 1;
		if (type > 2 && x==1) x += 1;
		if (type > 2 && x==H) x -= 1;
		int dir = rand() % 2 == 0 ? 1 : -1;
		fish.push_back(Fish(x, y, dir,FishType(type, 1)));
		draw_fish(x, y, type, type);
	}
}
// 물고기(적) 움직이기
void move_fish() {
	for(int i=0;i<fish.size();i++){
		if (rand() % 5 == 0) fish[i].dir *= -1;
		int next = (fish[i].y + fish[i].dir);
		int type = fish[i].type.type;
		int x = fish[i].x; int y = fish[i].y; int dir = fish[i].dir;
		
		if (type == 1 && (next == 0 || next == W)) continue;
		else  if (type==2 && (next == 0 || next >= W-1)) continue;
		else if (type == 3 && (next == 0 || next >= W-2)) continue;
		else if (type == 4 && (next == 0 || next >= W-2)) continue;
		
		draw_fish(x, y, type, 0);

		fish[i].y += fish[i].dir;
		y = fish[i].y;

		draw_fish(x, y, type, type);
	}
}
int hit_fish(int &cnt)
{
	int eat[100] = { 0 };
	int i = 0,e=0;
	vector<Fish>::iterator it;
	for (it=fish.begin();  it!= fish.end(); it++,i++) {
		if (fish[i].type.type == 0) { continue; }
		if (shark.x == it->x && shark.y == it->y) {
			if (shark.level >= it->type.type) {
				fish[i].type.type = 0; draw_fish(fish[i].x, fish[i].y, fish[i].type.type, 0);  cnt++;
			}
			else {
				return 1;
			}
		}
	}
}
int main()
{
	srand((unsigned)time(NULL));
	init_screen();
	long long int createFishTime = GetTickCount();
	int time,game,level=1;
	int fishCnt = 0;
	int eatFish = 0;
	draw_fish(shark.x, shark.y, shark.level, shark.type.type); // 유저 위치 초기화
	while (1) {
		time = GetTickCount();
		if (time - createFishTime>=1000) { // 주기(1초)에 따라 적 생성
			if (!(fishCnt-eatFish + 2 > FishCnt)) {
				create_fish(2, level+1);
				fishCnt += 2;
				createFishTime = time;
			}
		}
		system("cls");	
		shark_move(&shark);
		move_fish(); 
		show_screen();
		game = hit_fish(eatFish);
		if (game == 1) {
			printf("Your Shark is Dead!!\n");
			break;
		}
		if (eatFish < 30) {
			level = eatFish / 10 + 1;
			if (eatFish % 10 == 0) shark.level += eatFish / 10;
		}
		printf("level : %d eat : %d\n", shark.level, eatFish);
	}
}