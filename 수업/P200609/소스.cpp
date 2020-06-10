#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>

#define W 30
#define H 15

int map[H][W] = {0};

int showMap(void) {
	// 키보드로 이동을 시키고 이동경로를 벽으로 만든다...
	// 키보드를 한 번씩 입력 할 때마다 화면을 출력하고 지우는 동작
	// <enter> 를 입력하면 종료

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			printf("%d ", map[i][j]);
		}printf("\n");
	}
	return 0;
}

int drawMap(void) {
	// 키보드로 이동을 시키고 이동경로를 벽으로 만든다...
	// 키보드를 한 번씩 입력 할 때마다 화면을 출력하고 지우는 동작
	// <enter> 를 입력하면 종료
	int ix = 0 , iy = 0;
	map[iy][ix] = 1;
	printf("start drawMap()\n\n");
	while (1) {
		system("cls");
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				if (i == iy && j == ix) printf("☆");
				else if(map[i][j]==1){ printf("★"); }
				else printf("%2d", map[i][j]); 
			}printf("\n");
		}
		//ch = tolower(ch); <ctype.h>
		// 키보드가 눌렸을 때
		if (_kbhit()) {
			char ch = _getch();
			if (ch ==0xFFFFFFE0) {
				char key = _getch();
				//printf("\n%d\n", key);
				ch = key;
				//printf("\n%c\n", ch);
			}

			if (ch == '\r') {
				break;
			}
			else if (ch == 'w' || ch=='W' || ch==72) { // up
				//if (iy <= 0 || map[iy-1][ix]==1) { continue; }
				if (iy <= 0) { continue; }
				--iy;
			}
			else if (ch == 's' || ch=='S' || ch == 80) { // down
				//if (iy >= H-1 || map[iy + 1][ix] == 1) { continue; }
				if (iy >= H - 1) { continue; }
				++iy;
			}
			else if (ch == 'a' || ch=='A' || ch == 75) { // left
				//if (ix <= 0 || map[iy][ix-1] == 1) { continue; }
				if (ix <= 0) { continue; }
				--ix;
			}
			else if (ch == 'd' || ch=='D' || ch == 77) { // right
				//if (ix >= W-1 || map[iy][ix+1] == 1) { continue; }
				if (ix >= W - 1) { continue; }
				++ix;
			}
			map[iy][ix] = 1;
			//map[iy][ix] = 1 - map[iy][ix];
		}
	}
	printf("end drawMap()\n\n");
	return 0;
}
struct Point {
	int x, y, u=0, d=0, l=0, r=0;
};
struct Coord {
	//struct Point arr[W * H];
	//int length;
	int length;
	struct Point* arr;
};
Coord* searchMap() {
	struct Coord* coord = (Coord*)malloc(sizeof(Coord));
	coord->length=0; // 여러개
	coord->arr = (Point*)malloc(sizeof(Point) * (coord->length+1));
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (map[i][j] == 1) {
				coord->arr[coord->length].x = i;
				coord->arr[coord->length].y = j;
				coord->arr[coord->length].u = 0;
				coord->arr[coord->length].d = 0;
				coord->arr[coord->length].l = 0;
				coord->arr[coord->length].r = 0;
				if (i-1>=0 && map[i - 1][j] == 1) coord->arr[coord->length].u = 1;
				if (i+1<=H && map[i + 1][j] == 1) coord->arr[coord->length].d = 1;
				if (j-1>=0 && map[i][j - 1] == 1) coord->arr[coord->length].l = 1;
				if (j+1<=W && map[i][j + 1] == 1) coord->arr[coord->length].r = 1;
				coord->length++;
				coord->arr = (Point*)realloc(coord->arr, sizeof(Point)*(coord->length + 1));
				if (coord->arr == NULL) {
					printf("error\n");
					exit(1);
				}
			}
		}
	}
	return coord;
}
int main()
{
	drawMap();
	Coord* cp;
	cp = searchMap();
	for (int i = 0; i < cp->length; i++) {
		int sum = cp->arr[i].u + cp->arr[i].d + cp->arr[i].l + cp->arr[i].r;
		if (sum > 2) {
			printf("(%d %d){ %d %d %d %d }\n",
				cp->arr[i].x, cp->arr[i].y, cp->arr[i].u,
				cp->arr[i].d, cp->arr[i].l, cp->arr[i].r);
		}
	}

	return 0;
}