#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<windows.h>
#include<math.h>
#include<algorithm>

#define SIZE 22
int board[SIZE][SIZE] = { 0 };
// 벽 = -1 / 빈공간 = 0 / 아군 9 / 적군 2

struct Enemy {
	int type;  // 0이면 죽음 (1~5)
	int x, y;
};
struct User {
	int type;	
	int x, y;
};
struct Bullet {
	int type;
	int x, y;
};
struct Time {
	int etime; // enemy move time
	int atime; // attack time
};
void init_board() {
	// 테두리
	for (int i = 0; i < SIZE; i++) {
		board[0][i] = -1;	board[SIZE-1][i] = -1;	board[i][0] = -1;	board[i][SIZE-1] = -1;
	}
	// 안쪽
	for (int i = 1; i < SIZE-1; i++) {
		for (int j = 1; j < SIZE-1; j++) {
			board[i][j] = 0;
		}
	}
}
void show_board() {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j <SIZE; j++) {
			//printf("%3d", board[i][j]);
			if (board[i][j] == 0)	printf("   ");
			else if (board[i][j] == -1) printf("▩ ");
			else if (board[i][j] == 1) printf("▼ ");
			else if (board[i][j] == 2) printf("▶ ");
			else if (board[i][j] == 3) printf("◀ ");
			else if (board[i][j] == 8) printf("＊ ");
			else if (board[i][j] == 9) printf("♣ ");
		}printf("\n");
	}
}
int del = 0;
void enemy_move(Enemy enemy[5], int* cnt) {
	int d = 0;
	for (int i = 0; i < (*cnt); i++) {
		if (enemy[i].type == 0) continue;
		int x, y;
		x = enemy[i].x; y = enemy[i].y;
		if (enemy[i].type == 1) {
			if (x < SIZE - 2) {
				board[x + 1][y] = 1; board[x][y] = 0; enemy[i].x++;
			}
			else { board[x][y] = 0;  enemy[i].x = 0; enemy[i].y = 0; enemy[i].type = 0; d++; }
		}
		if (enemy[i].type == 2) {
			if (x < SIZE - 2) {
				if (enemy[i].y == SIZE - 2) { board[x][y] = 0; enemy[i].y = 0; }
				else if(enemy[i].y<SIZE-2){ 
					if(enemy[i].y!=0) board[x][y] = 0; 
					board[x + 1][y + 1] = 2; enemy[i].x++; enemy[i].y++; 
				}
			}
			else { board[x][y] = 0;  enemy[i].x = 0; enemy[i].y = 0; enemy[i].type = 0; d++; }
		}
		if (enemy[i].type == 3) { 
			if (x < SIZE - 2) {
				if (enemy[i].y == 1) { board[x][y] = 0; enemy[i].y = SIZE-1; }
				else if (enemy[i].y > 1) {
					if (enemy[i].y != SIZE-1) board[x][y] = 0;
					board[x + 1][y - 1] = 3; enemy[i].x++; enemy[i].y--;
				}
			}
			else { board[x][y] = 0;  enemy[i].x = 0; enemy[i].y = 0; enemy[i].type = 0; d++; }
		}
	}
	del += d;
}
void user_move(User* user) {
	int x, y;
	x = user->x;
	y = user->y;
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
			if (x>1) {
				board[x][y] = 0; user->x--; board[user->x][user->y] = 9;
			}
		}
		else if (ch == 's' || ch == 'S' || ch == 80) { // down
			if (x < SIZE-2) {
				board[x][y] = 0; user->x++; board[user->x][user->y] = 9;
			}
		}
		else if (ch == 'a' || ch == 'A' || ch == 75) { // left
			if (y > 1) {
				board[x][y] = 0; user->y--; board[user->x][user->y] = 9;
			}
		}
		else if (ch == 'd' || ch == 'D' || ch == 77) { // right
			if (y < SIZE - 2) {
				board[x][y] = 0; user->y++; board[user->x][user->y] = 9;
			}
		}

	}
}
Enemy enemy[200] = { 0 };
Bullet bullet[300] = { 0 };
int kill = 0;
int hit(int cnt, int abcnt) {
	for (int i = 0; i < abcnt; i++) {
		if (bullet[i].type == 0) continue;
		for (int j = 0; j < cnt; j++) {
			if (enemy[j].type == 0) continue;
			if (bullet[i].x == enemy[j].x && bullet[i].y == enemy[j].y) {
				bullet[i].type = 0; enemy[j].type = 0; del++; kill++;
				printf("\nDestroy Enemy\n");
			}
		}
	}
	return 0;
}
int kill_hit(User* user,int cnt) {
	for (int i = 0; i < cnt; i++) {
		if (user->x == enemy[i].x && user->y == enemy[i].y) {
			return 1;
		}
	}
	return 0;
}
int main2()
{
	srand(time(NULL));
	int enemy_cnt = 100;
	
	User user = { 0 };
	Time stime = { 0 };
	stime.etime = 5; stime.atime = 5;
	int cnt = 0, bcnt = 0,abcnt=0;
	int time = 0;
	init_board();
	user.x = SIZE - 2; user.y = SIZE / 2; board[user.x][user.y] = 9;
	while (1) {
		system("cls");
		if (time > 1000000) time = 0;
		show_board();
		//printf("cnt : %d del : %d\n", cnt,del);
		if (time % stime.etime == 0) {
			if (cnt - del < enemy_cnt) {
				enemy[cnt].x = 1;	enemy[cnt].y = rand() % 20 + 1;	enemy[cnt].type = (rand() % 3) + 1;
				stime.etime = 3; board[enemy[cnt].x][enemy[cnt].y] = 2; cnt++;
			}
			if(cnt<200) enemy_move(enemy, &cnt);
		}
		user_move(&user);
		/*if (time % stime.atime == 0) {
			for (int i = 0; i < abcnt; i++) {
				if (bullet[i].type == 0) continue;
				int bx = bullet[i].x;
				int by = bullet[i].y;
				board[bx][by] = 0;
				board[bx-1][by] = 8;
				if (bx - 1 <= 1) {
					board[bx - 1][by] = 0;
					bullet[i].type = 0;
					bcnt--;
					continue;
				}
				bullet[i].x--;
			}
			if (bcnt < 30 && abcnt<300) { board[user.x - 1][user.y] = 8; bullet[abcnt].x = user.x; bullet[abcnt].y = user.y; bullet[abcnt].type = 8; bcnt++; abcnt++; }
		}
		hit(cnt, abcnt);*/
		if (kill_hit(&user, cnt)) {
			printf("Game Over\n");
			printf("time : %d\n", time/10);
			int x; scanf("%d", &x);
			return 0;
		}
		time++;
		/*if (kill > 10) {
			printf("\nWIN\n");
			return 0;
		}*/
	}
	return 0;
}