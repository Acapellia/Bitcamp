#include<stdio.h>
#include<windows.h>
#include"turboc.h"
// 변수 사용 이유 - 반복
void draw_tree(int time, int n) {
	for (int i = 0; i < 25; i++) {
		if (i != 20) {
			for (int j = 10; j < time + 10; j++) {
				gotoxy(j, i); printf("*");
			}
		}
		else {
			for (int j = 10; j < time-n+10; j++) {
				gotoxy(j, i); printf("*");
			}
		}
	}
}
int main() 
{
	int cnt = 0;
	int time=60;
	while (cnt < time*60) {
		system("cls");
		draw_tree(time,cnt/60);
		printf("\n\n나무를 %4d번 찍었습니다. 쿵~\n", ++cnt);
		Sleep(1000);
	}printf("나무를 배었습니다\n");
	return 0;
}