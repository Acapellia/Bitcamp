#include<stdio.h>
#include<windows.h>
#include"turboc.h"
// ���� ��� ���� - �ݺ�
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
		printf("\n\n������ %4d�� ������ϴ�. ��~\n", ++cnt);
		Sleep(1000);
	}printf("������ ������ϴ�\n");
	return 0;
}