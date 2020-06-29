#include<iostream>
//#include<ctime>
//#include<windows.h>
#include "turboc.h"
using namespace std;
//1. random�ϰ� 80 * 25���� ������ ��ġ�� 100���� ���� �����ǰ� �������� �������� ���α׷�
#define W 80
#define H 25
struct Star {
	int point[100][2]; // x,y ��ǥ
	char board[H][W] = { 0 };
	void showStar(int x, int y, int s) {
		gotoxy(x, y);
		if (s == 1) cout << "*";
		else cout << " ";
		delay(30);
	}
};
void problem1() {
	while (true) {
		Star star;
		for (int i = 0; i < 100; i++) {
			int x = rand() % W;		int y = rand() % H;
			star.point[i][0] = x;	star.point[i][1] = y;
			star.board[y][x] = '*';
			star.showStar(x,y+1,1);
			gotoxy(W, H + 1);
			cout << endl<< "star count : " << i<< "   " <<endl;
		}
		for (int i = 99; i >=0; i--) {
			int x = star.point[i][0]; int y = star.point[i][1];
			star.board[y][x] = ' ';
			star.showStar(x,y+1,0);
			gotoxy(W, H+1);
			cout << endl<< "star count : " << i + 1 << "   " << endl;
		}
	}
}
//2. �л� ����ü�� �ۼ��մϴ�
//����ü�� �̸�, ����, Ű, ������, ��ȣ �� �̷�����ֽ��ϴ�
//�л� 5���� ������ �Է¹ް�
//��� ����ϼ���
//�ݵ�� �Լ��� �ۼ��ϰ�, �Լ��� �Ű������� �����͸� ���� �����ؾ� �մϴ�
struct Student {
	char name[20];
	int age, num;
	double height, weight;
};
void insertStudent(Student* st) {
	cout << "5���� �л� ������ �Է¹ްڽ��ϴ�" << endl;
	for (int i = 0; i < 5; i++) {
		char name[20];
		cout << i + 1 << "��° �л��� ������ �Է����ּ���(�̸�, ����, Ű, ������, ��ȣ)" << endl;
		cin >> name>>st[i].age>>st[i].height>>st[i].weight>>st[i].num;
		strcpy(st[i].name, name);
	}
}
void printStudent(Student* st) {
	for(int i=0;i<5;i++)
		cout << st[i].name << " " << st[i].age << " " << st[i].height << " " << st[i].weight << " " << st[i].num<<endl;
	cout << endl;
}
void problem2() {
	Student st[5];
	insertStudent(st);
	printStudent(st);
}
int main()
{
	srand((unsigned)time(NULL));
	setcursortype(NOCURSOR);
	while (1) {
		int sel;
		cout << "���ϴ� ������ �Է��ϼ��� : ";
		cin >> sel;
		if (sel == 0) { cout << "end!!" << endl; break; }
		else if (sel == 1) { problem1(); }
		else if (sel == 2) { problem2(); }

		cout << endl;
	}
	return 0;
}