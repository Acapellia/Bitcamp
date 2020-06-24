#include<stdio.h>
#include<string.h> // 문자열
#include<math.h>
#include<stdlib.h> // 여러 유틸리티
#include<conio.h> // 콘솔용 입출력
#include<time.h>
#define SIZE 19
int board[21][21];
int AllStone = 0;
int ex=10, ey=10;
void init_board() {
	for (int i = 0; i < 21; i++) { board[i][0] = 9; board[i][20] = 9; board[0][i] = 9; board[20][i] = 9; }
	for (int i = 1; i < 20; i++) {
		for (int j = 1; j < 20; j++) {
			board[i][j] = -1;
		}
	}
}
void show_board(int x=0,int y=0) {
	for (int i = 0; i < 20; i++) { 
		printf("%d ", i%10); 
	}
	printf("\n");
	for (int i = 1; i < 20; i++) {
		printf("%d ", i%10);
		for (int j = 1; j < 20; j++) { 
			if (i == x && j == y) { printf("◎"); }
			else if (board[i][j] == -1) printf("┼ ");
			else if (board[i][j] == 0) printf("●");
			else if (board[i][j] == 1) printf("○");
			else { printf("%d ", board[i][j]); }
			//printf("%c ", board[i][j]);

		}printf("\n");
	}
	printf("\n--------------------------------------------------------\n");
}
void show_board(int board[21][21]) {
	for (int i = 0; i < 20; i++) {
		printf("%d ", i % 10);
	}
	printf("\n");
	for (int i = 1; i < 20; i++) {
		printf("%d ", i % 10);
		for (int j = 1; j < 20; j++) {
			printf("%-3d ", board[i][j]);
		}printf("\n");
	}
	printf("\n--------------------------------------------------------\n");
}
void set_stone(int x,int y,int t) {
	if (t == 0) board[x][y] = 0;
	else board[x][y] = 1;
}
int check_stone(int x, int y) {
	return (board[x][y] == -1) ? 1 : 0;
}
int check_win() {
	// 가로
	int cnt;
	for (int i = 1; i < 20; i++) {
		cnt = 0;
		for (int j = 1; j < 20; j++) {
			if (board[i][j] != 0 && board[i][j] != 1) { cnt = 0; }
			else if ((board[i][j] == 0 || board[i][j] == 1) && board[i][j] != board[i][j-1]) { cnt = 1;}
			else if (board[i][j] == board[i][j - 1]) {
				cnt++;
			}
			else if(board[i][j] != board[i][j - 1]){ cnt = 0; }
			if (cnt == 5) {
				if (board[i][j] == board[i][j + 1]) { cnt = 0; continue; }
				return 1; 
			}
		}
	}
	// 세로
	for (int j = 1; j < 20; j++) {
		cnt = 0;
		for (int i = 1; i < 20; i++) {
			if (board[i][j] != 0 && board[i][j] != 1) { cnt = 0;}
			else if ((board[i][j] == 0 || board[i][j] == 1) && board[i][j] != board[i-1][j]) { cnt = 1;}
			else if (board[i][j] == board[i-1][j]) {
				cnt++;
			}
			else if (board[i][j] != board[i-1][j]) { cnt = 0; }
			if (cnt == 5) { 
				if (board[i][j] == board[i+1][j]) { cnt = 0; continue; }
				return 1; 
			}
		}
	}
	// 대각 '\'
	for (int k = 19; k > 0; k--) {
		for (int i = 1, j = k; j <20; i++, j++) {
			if (board[i][j] != 0 && board[i][j] != 1) { cnt = 0; }
			else if ((board[i][j] == 0 || board[i][j] == 1) && board[i][j] != board[i - 1][j - 1]) { cnt = 1; }
			else if (board[i][j] == board[i - 1][j - 1]) {
				cnt++;
			}
			else if (board[i][j] != board[i - 1][j - 1]) { cnt = 0; }
			if (cnt == 5) { 
				if (board[i][j] == board[i+1][j + 1]) { cnt = 0; continue; }
				return 1; 
			}
		}
	}
	for (int k = 2; k < 20; k++) {
		for (int i = k, j = 1; i < 20; i++, j++) {
			if (board[i][j] != 0 && board[i][j] != 1) { cnt = 0; }
			else if ((board[i][j] == 0 || board[i][j] == 1) && board[i][j] != board[i - 1][j - 1]) { cnt = 1; }
			else if (board[i][j] == board[i - 1][j - 1]) {
				cnt++;
			}
			else if (board[i][j] != board[i - 1][j - 1]) { cnt = 0; }
			if (cnt == 5) { 
				if (board[i][j] == board[i+1][j + 1]) { cnt = 0; continue; }
				return 1; 
			}
		}
	}
	// 대각 '/'
	for (int k = 1; k < 20; k++) {
		for (int i = 1, j = k; j > 0; i++, j--) {
			if (board[i][j] != 0 && board[i][j] != 1) { cnt = 0; }
			else if ((board[i][j] == 0 || board[i][j] == 1) && board[i][j] != board[i - 1][j + 1]) { cnt = 1; }
			else if (board[i][j] == board[i - 1][j + 1]) {
				cnt++;
			}
			else if (board[i][j] != board[i - 1][j + 1]) { cnt = 0; }
			if (cnt == 5) {
				if (board[i][j] == board[i + 1][j - 1]) { cnt = 0; continue; }
				return 1;
			}
		}
	}
	for (int k = 2; k < 20; k++) {
		for (int i = k, j = 19; i < 20; i++, j--) {
			if (board[i][j] != 0 && board[i][j] != 1) { cnt = 0; }
			else if ((board[i][j] == 0 || board[i][j] == 1) && board[i][j] != board[i - 1][j + 1]) { cnt = 1; }
			else if (board[i][j] == board[i - 1][j + 1]) {
				cnt++;
			}
			else if (board[i][j] != board[i - 1][j + 1]) { cnt = 0; }
			if (cnt == 5) {
				if (board[i][j] == board[i + 1][j - 1]) { cnt = 0; continue; }
				return 1;
			}
		}
	}


	return 0;
}
void setWeightW(int Cboard[21][21], int check[21][21], char stone, int x, int y, int w) {
	int cnt, tcnt = 0, mw;
	int tx = x, ty = y;
	char stone1, stone2;
	if (stone == 0) {
		stone1 = 0; stone2 = 1;
	}
	else { stone1 = 1; stone2 = 0; }
	cnt = 1; tcnt = 0;
	x = tx; y = ty;

	check[x][y] = 1;

	if (w == -1) mw = 3;
	else mw = 1;
	//가로
	for (int i = x, j = y + 1; j < 20; j++) {
		if (tcnt + cnt > 4) break;
		//check[i][j - 1] = 1;
		if (board[x][y] == board[i][j]) {
			cnt++; mw *= 10;// printf("가로 %d\n", cnt);
			if ((cnt + tcnt) == 4) mw *= 10;
			if ((cnt + tcnt) == 3) mw *= 5;
			if (tcnt == 0) check[i][j] = 1;
		}
		else {
			// 양쪽다 공백
			if (board[x][y - 1] == -1 && board[i][j] == -1) {
				if (cnt == 1) { Cboard[x][y - 1] += (1 * cnt * mw * w); Cboard[i][j] += (1 * cnt * w); }
				else { Cboard[x][y - 1] += (9 * cnt * mw * w); Cboard[i][j] += (9 * cnt * mw * w); }
			}
			// 한쪽만 공백
			else if (board[x][y - 1] == -1 && board[i][j] != -1) {
				Cboard[x][y - 1] += (1 * cnt * mw * w);
			}
			else if (board[x][y - 1] != -1 && board[i][j] == -1) {
				Cboard[i][j] += (1 * cnt * mw * w);
			}
			// 둘다 막힘
			else if (board[x][y - 1] != -1 && board[i][j] != -1) {
			}
			if (board[i][j] == -1) {
				tcnt = cnt; cnt = 0; x = i; y = j + 1;
				if (board[x][y] == -1 || board[x][y] == stone2) break;
			}
			else break;
		}
	}
}
void setWeightH(int Cboard[21][21], int check[21][21], char stone, int x, int y, int w) {
	int cnt, tcnt = 0, mw;
	int tx = x, ty = y;
	char stone1, stone2;
	if (stone == 0) {
		stone1 = 0; stone2 = -1;
	}
	else { stone1 = -1; stone2 = 0; }
	//세로
	cnt = 1; tcnt = 0;
	x = tx; y = ty;

	check[x][y] = 1;

	if (w == -1) mw = 3;
	else mw = 1;
	for (int i = x + 1, j = y; i < 20; i++) {
		if (tcnt + cnt > 4) break;
		//check[i - 1][j] = 1;
		if (board[x][y] == board[i][j]) {
			cnt++; mw *= 10; //printf("세로 %d\n", cnt);
			if ((cnt + tcnt) == 4) mw *= 10;
			if ((cnt + tcnt) == 3) mw *= 5;
			if (tcnt == 0) check[i][j] = 1;
		}
		else {
			// 양쪽다 공백
			if (board[x - 1][y] == -1 && board[i][j] == -1) {
				if (cnt == 1) { Cboard[x - 1][y] += (1 * cnt * mw * w); Cboard[i][j] += (1 * cnt * mw * w); }
				else { Cboard[x - 1][y] += (9 * cnt * mw * w); Cboard[i][j] += (9 * cnt * mw * w); }
			}
			// 한쪽만 공백
			else if (board[x - 1][y] == -1 && board[i][j] != -1) {
				Cboard[x - 1][y] += (1 * cnt * mw * w);
			}
			else if (board[x - 1][y] != -1 && board[i][j] == -1) {
				Cboard[i][j] += (1 * cnt * mw * w);
			}
			// 둘다 막힘
			else if (board[x - 1][y] != -0 && board[i][j] != -1) {
			}
			if (board[i][j] == -1) {
				tcnt = cnt; cnt = 0; x = i + 1; y = j;
				if (board[x][y] == -1 || board[x][y] == stone2) break;
			}
			else break;
		}
	}
}
void setWeightDL(int Cboard[21][21], int check[21][21], char stone, int x, int y, int w) {
	int cnt, tcnt = 0, mw;
	int tx = x, ty = y;
	char stone1, stone2;
	if (stone == 0) {
		stone1 = 0; stone2 = 1;
	}
	else { stone1 = 1; stone2 = 0; }
	// 대각 /
	cnt = 1; tcnt = 0;
	x = tx; y = ty;

	check[x][y] = 1;

	if (w == -1) mw = 3;
	else mw = 1;
	for (int i = x + 1, j = y - 1; i < 20; i++, j--) {
		if (tcnt + cnt > 4) break;
		//check[i - 1][j + 1] = 1;
		if (board[x][y] == board[i][j]) {
			cnt++; mw *= 10; //printf("대각\/ %d\n", cnt);
			if ((cnt + tcnt) == 4) mw *= 10;
			if ((cnt + tcnt) == 3) mw *= 5;
			if (tcnt == 0) check[i][j] = 1;
		}
		else {
			// 양쪽다 공백
			if (board[x - 1][y + 1] == -1 && board[i][j] == -1) {
				if (cnt == 1) { Cboard[x - 1][y + 1] += (1 * cnt * mw * w); Cboard[i][j] += (1 * cnt * w); }
				else { Cboard[x - 1][y + 1] += (9 * cnt * mw * w); Cboard[i][j] += (9 * cnt * mw * w); }
			}
			// 한쪽만 공백
			else if (board[x - 1][y + 1] == -1 && board[i][j] != -1) {
				Cboard[x - 1][y + 1] += (1 * cnt * mw * w);
			}
			else if (board[x - 1][y + 1] != -1 && board[i][j] == -1) {
				Cboard[i][j] += (1 * cnt * mw * w);
			}
			// 둘다 막힘
			else if (board[x - 1][y + 1] != -1 && board[i][j] != -1) {
			}
			if (board[i][j] == -1) {
				tcnt = cnt; cnt = 0; x = i + 1; y = j - 1;
				if (board[x][y] == -1 || board[x][y] == stone2) break;
			}
			else break;
		}
	}
}
void setWeightDR(int Cboard[21][21], int check[21][21], char stone, int x, int y, int w) {
	int cnt, tcnt = 0, mw;
	int tx = x, ty = y;
	char stone1, stone2;
	if (stone == 0) {
		stone1 = 0; stone2 = 1;
	}
	else { stone1 = 1; stone2 = 0; }
	// 대각 '\'
	cnt = 1; tcnt = 0;
	x = tx; y = ty;

	check[x][y] = 1;

	if (w == -1) mw = 3;
	else mw = 1;
	for (int i = x + 1, j = y + 1; i < 20; i++, j++) {
		if (tcnt + cnt > 4) break;
		//check[i - 1][j - 1] = 1;
		if (board[x][y] == board[i][j]) {
			cnt++; mw *= 10; //printf("대각\\ %d\n", cnt);
			if ((cnt + tcnt) == 4) mw *= 10;
			if ((cnt + tcnt) == 3) mw *= 5;
			if(tcnt==0) check[i][j] = 1;
		}
		else {
			// 양쪽다 공백
			if (board[x - 1][y - 1] == -1 && board[i][j] == -1) {
				if (cnt == 1) { Cboard[x - 1][y - 1] += (1 * cnt * mw * w); Cboard[i][j] += (1 * cnt * mw * w); }
				else { Cboard[x - 1][y - 1] += (9 * cnt * mw * w); Cboard[i][j] += (9 * cnt * mw * w); }
			}
			// 한쪽만 공백
			else if (board[x - 1][y - 1] == -1 && board[i][j] != -1) {
				Cboard[x - 1][y - 1] += (1 * cnt * mw * w);
			}
			else if (board[x - 1][y - 1] != -1 && board[i][j] == -1) {
				Cboard[i][j] += (1 * cnt * mw * w);
			}
			// 둘다 막힘
			else if (board[x - 1][y - 1] != -1 && board[i][j] != -1) {
			}
			if (board[i][j] == -1) {
				tcnt = cnt; cnt = 0; x = i+1; y = j + 1;
				if (board[x][y] == -1 || board[x][y] == stone2) break;
			}
			else break;
		}
	}
}
void maxValue(char s, int point[4]) {
	int Cboard[21][21] = {0};
	int check1[21][21] = { 0 };
	int check2[21][21] = { 0 };
	int check3[21][21] = { 0 };
	int check4[21][21] = { 0 };
	char myStone, yourStone;
	if (s == 0) {
		myStone = 0; yourStone = 1;
	}
	else { myStone = 1; yourStone = 0; }
	for (int i = 1; i < 20; i++) {
		for (int j = 1; j < 20; j++) {
			if (board[i][j] == myStone && check1[i][j] != 1) {
				setWeightW(Cboard, check1, yourStone, i, j, 1);
			}	
		}
	}
	for (int i = 1; i < 20; i++) {
		for (int j = 1; j < 20; j++) {
			if (board[i][j] == myStone && check2[i][j] != 1) {
				setWeightH(Cboard, check2, yourStone, i, j, 1);
			}
		}
	}
	for (int i = 1; i < 20; i++) {
		for (int j = 1; j < 20; j++) {
			if (board[i][j] == myStone && check3[i][j] != 1) {
				setWeightDL(Cboard, check3, yourStone, i, j, 1);
			}
		}
	}
	for (int i = 1; i < 20; i++) {
		for (int j = 1; j < 20; j++) {
			if (board[i][j] == myStone && check4[i][j] != 1) {
				setWeightDR(Cboard, check4, yourStone, i, j, 1);
			}
		}
	}
	int stone[4] = {0};
	stone[0] = 10; stone[1] = 10; stone[2] = 0; stone[3] = 1;
	for (int i = 1; i < 20; i++) {
		for (int j = 1; j < 20; j++) {
			if (Cboard[i][j] > stone[2]) {
				stone[0] = i; stone[1] = j; stone[2] = Cboard[i][j]; stone[3] = 1;
			}
			else if (Cboard[i][j] == stone[2]) {
				if (rand() % 2 == 0) { continue; }
				stone[0] = i; stone[1] = j; stone[2] = Cboard[i][j]; stone[3] = yourStone;
			}
		}
	}
	if (stone[2] == 0) { stone[0] = 10; stone[1] = 10; stone[2] = 0; stone[3] = 1; }
	point[0] = stone[0]; point[1] = stone[1]; point[2] = stone[2]; point[3] = stone[3];
	//show_board(Cboard);
}
void minValue(char s, int point[4]) {
	int Cboard[21][21] = { 0 };
	int check1[21][21] = { 0 };
	int check2[21][21] = { 0 };
	int check3[21][21] = { 0 };
	int check4[21][21] = { 0 };
	char myStone, yourStone;
	if (s == 0) {
		myStone = 1; yourStone = 0;
	}
	else { myStone = 0; yourStone = 1; }

	for (int i = 1; i < 20; i++) {
		for (int j = 1; j < 20; j++) {
			if (board[i][j] == yourStone && check1[i][j]!=1) {
				setWeightW(Cboard, check1, yourStone, i, j, -1);
			}
		}
	}
	for (int i = 1; i < 20; i++) {
		for (int j = 1; j < 20; j++) {
			if (board[i][j] == yourStone && check2[i][j] != 1) {
				setWeightH(Cboard, check2, yourStone, i, j, -1);
			}
		}
	}
	for (int i = 1; i < 20; i++) {
		for (int j = 1; j < 20; j++) {
			if (board[i][j] == yourStone && check3[i][j] != 1) {
				setWeightDL(Cboard, check3, yourStone, i, j, -1);
			}
		}
	}
	for (int i = 1; i < 20; i++) {
		for (int j = 1; j < 20; j++) {
			if (board[i][j] == yourStone && check4[i][j] != 1) {
				setWeightDR(Cboard, check4, yourStone, i, j, -1);
			}
		}
	}
	int stone[4] = {0};
	stone[0] = 10; stone[1] = 10; stone[2] = 99999; stone[3] = yourStone;
	for (int i = 1; i < 20; i++) {
		for (int j = 1; j < 20; j++) {
			if (Cboard[i][j] < stone[2]) {
				stone[0] = i; stone[1] = j; stone[2] = Cboard[i][j]; stone[3] = yourStone;
			}
			else if (Cboard[i][j] == stone[2]) {
				if (rand() % 2 == 0) { continue; }
				stone[0] = i; stone[1] = j; stone[2] = Cboard[i][j]; stone[3] = yourStone;
			}
		}
	}
	printf("Cboard\n");
	//show_board(Cboard);
	if (stone[2] == 0) { stone[0] = 10; stone[1] = 10; stone[2] = 0; stone[3] = 1; }
	point[0] = stone[0]; point[1] = stone[1]; point[2] = stone[2]; point[3] = stone[3];
}
void omokAI(int s, int point[2]) {
	char myStone, yourStone;
	int max[4] = { 0 };
	int min[4] = { 0 };
	if (s == 0) {
		myStone = 0; yourStone = 1;
	}
	else { myStone = 1; yourStone = 0; }
	maxValue(myStone,max);
	printf("max %d %d %d %d\n", max[0], max[1], max[2], max[3]);
	minValue(yourStone, min);
	printf("min %d %d %d %d\n", min[0], min[1], min[2], min[3]);
	if (max[2] >= min[2]*(-1)) {
		point[0] = max[0];
		point[1] = max[1];
	}
	else {
		point[0] = min[0];
		point[1] = min[1];
	}
}
void User(int* x,int* y) {
	int ix = ex; int iy = ey;
	system("cls");
	printf("User Turn(Set Stone = z)\n");
	show_board(ix,iy);
	while (1) {
		//ch = tolower(ch); <ctype.h>
		// 키보드가 눌렸을 때
		if (_kbhit()) {
			char ch = _getch();
			if (ch == 0xFFFFFFE0) {
				char key = _getch();
				//printf("\n%d\n", key);
				ch = key;
				//printf("\n%c\n", ch);
			}
			
			if (ch == '\r') {
				break;
			}
			else if (ch == 'w' || ch == 'W' || ch == 72) { // up
				if (ix <= 1) { continue; }
				--ix;
			}
			else if (ch == 's' || ch == 'S' || ch == 80) { // down
				if (ix >= SIZE) { continue; }
				++ix;
			}
			else if (ch == 'a' || ch == 'A' || ch == 75) { // left
				if (iy <= 1) { continue; }
				--iy;
			}
			else if (ch == 'd' || ch == 'D' || ch == 77) { // right
				if (iy >= SIZE) { continue; }
				++iy;
			}
			else if (ch == 'z' || ch == 'Z') { // right
				*x = ix; *y = iy; return;
			}
			system("cls");
			printf("User Turn(Set Stone = z)\n");
			show_board(ix, iy);
			//map[iy][ix] = 1 - map[iy][ix];
		}
	}
}
void game() {
	int turn = 0;
	while (1) {
		if (AllStone == 19 * 19) { printf("더이상 둘 곳이 없습니다!!\n"); break; }
		int x, y;
		if (turn == 0) { // player
			User(&x, &y);
			if (check_stone(x, y)) { set_stone(x, y, turn); }
			/*Stone AIstone = omokAI(0);
			if (check_stone(AIstone.x, AIstone.y)) { set_stone(AIstone.x, AIstone.y, turn); AllStone++; }*/
			else { printf("돌을 둘 수 없는 위치입니다\n");  continue; }
			turn = 1;
		}
		else { // AI
			int AIstone[2];
			omokAI(1,AIstone);
			//printf("set stone(x,y) : ");
			//scanf("%d %d", &x, &y);
			if (check_stone(AIstone[0], AIstone[1])) { 
				set_stone(AIstone[0], AIstone[1], turn); AllStone++;
				ex = AIstone[0]; ey = AIstone[1];  
			}
			else { printf("돌을 둘 수 없는 위치입니다\n"); continue; }
			turn = 0;
		}
		system("cls");
		show_board();
		int win = check_win();
		if (win==1) {
			printf("End!!\n");
			return;
		}	
	}
}
// 3 3 / 4 3 안막힘 - > 경우의 수 미리 선언 후 비교
/* struct _3343{
	int arr[4][4]={~~~~~~~~}
	Point p;
	p.x=?; p.y=?;
}*/

// 중간이 비어있는 3 4 공방시 양쪽 끝을 파악 못 함
// #@ @@#

// 다음 수를 생각할 수 있게 깊이를 주는 방법
// & 시간을 줄이기 위한 cut 방식
// 

int main()
{
	srand((unsigned int)time(NULL));
	init_board();
	show_board();
	game();
}