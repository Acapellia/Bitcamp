#include<iostream>
//#include<ctime>
//#include<windows.h>
#include "turboc.h"
using namespace std;
//1. random하게 80 * 25안의 임의의 위치에 100개의 별이 생성되고 역순으로 지워지는 프로그램
#define W 80
#define H 25
struct Star {
	int point[100][2]; // x,y 좌표
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
//2. 학생 구조체를 작성합니다
//구조체는 이름, 나이, 키, 몸무게, 번호 로 이루어져있습니다
//학생 5명의 정보를 입력받고
//모두 출력하세요
//반드시 함수로 작성하고, 함수의 매개변수는 포인터를 통해 전달해야 합니다
struct Student {
	char name[20];
	int age, num;
	double height, weight;
};
void insertStudent(Student* st) {
	cout << "5명의 학생 정보를 입력받겠습니다" << endl;
	for (int i = 0; i < 5; i++) {
		char name[20];
		cout << i + 1 << "번째 학생의 정보를 입력해주세요(이름, 나이, 키, 몸무게, 번호)" << endl;
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
		cout << "원하는 과제를 입력하세요 : ";
		cin >> sel;
		if (sel == 0) { cout << "end!!" << endl; break; }
		else if (sel == 1) { problem1(); }
		else if (sel == 2) { problem2(); }

		cout << endl;
	}
	return 0;
}