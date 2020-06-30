#include<iostream>
#include <cstdlib>
#include <ctime> 
#include<cstring>
using namespace std;
//1. cout << 연산자를 이용해서 구구단을 출력하세요
//2 x 1 = 2  3 x 1 = 3 ..... 9 x 1 = 9
//......
//2 x 9 = 18
void problem1() {
	for (int i = 1; i <= 9; i++) {
		for (int j = 2; j <= 9; j++) {
			cout << j << " * " << i << " = " << j * i << " ";
		}cout << endl;
	}
}
//2. 키보드로부터 2개의 정수를 읽어서 큰 수를 출력하세요
void problem2() {
	int num1, num2;
	cout << "2개의 정수를 입력하세요 : ";
	cin >> num1 >> num2;
	cout << (num1 > num2 ? num1 : num2);
}
//3. 소수점을 가지는 5개의 실수를 입력받아 제일 큰 수를 출력하세요
void problem3() {
	double max = 0.0;
	cout << "5개의 실수를 입력하세요"<<endl;
	for (int i = 1; i <= 5; i++) {
		cout << i << "번째 실수를 입력하세요 : ";
		double num; cin >> num;
		if (i == 1) max = num;
		max < num ? (max = num) : (max = max);
	}
	cout << "max : " << max<<endl;

}
//4. < Enter > 키가 입력될 때까지 문자들을 읽고, 입력된 문자 'x'의
//개수를 화면에 출력하세요.
void problem4() {
	getchar();
	int cnt = 0;
	cout << "문자열을 입력하세요:";
	while (true) {
		char x;
		cin.get(x);
		if (x == '\n') { cout << "cnt : " << cnt; break; }
		cnt++;
	}
}
//5. "yes"가 입력될 때까지 종료하지 않는 프로그램을 작성해세요.입력은 cin.getline() 함수를 사용하세요
// 이상함
void problem5() {
	getchar();
	for(int i=0;i<3;i++) {
		char x[10];
		cout << "문자열을 입력하세요 : ";
		//getchar();
		cin.getline(x, 10,'\n');
		if (!strcmp(x, "yes")) { cout << "종료" << endl; break; }
		//cout << "string : " << x<<endl;
	}
}
//6. ';'으로 5개의 이름을 구분해서 입력받아, 각 이름을 끊어내여 화면에 출력하세요.
//그리고 가장 긴 이름을 판별해서 나타내세요.
//cin.getline(str, 100, ';');
//홍길동; 임꺽정; 장길산; 일지매; 모짜르트;
//1:홍길동
//2 : 임꺽정
//3 : 장길산
//4 : 일지매
//5 : 모짜르트
void problem6() {
	getchar();
	int len=0;
	char maxStr[100];
	cout << ";를 끝으로 하는 문자열들을 입력하세요 : ";
	for (int i = 0; i < 5; i++) {
		char str[100] = { 0 };
		cin.getline(str, 100, ';');
		if (len < strlen(str)) { len = strlen(str); strcpy(maxStr, str); }
		cout << i+1 << " : "  << str << endl;
	}
	cout << endl;
	cout << "string : " << maxStr << endl;
	cout << "len : " << len << endl;
}
//7. 이름, 주소, 나이를 입력받아 출력하세요.
void problem7() {
	char name[20], addr[20];
	int age;
	cout << "이름 : ";  cin >> name; 
	cout << "주소 : ";  cin >> addr; 
	cout << "나이 : ";  cin >> age; 
	cout << name << endl;
	cout << addr << endl;
	cout << age << endl;

}
//8. 문자열을 하나 입력받고 문자열의 부분 문자열을 출력하세요
//hello
//h
//he
//hel
//hell
//hello
void problem8() {
	char str[20];
	cout << "문자열을 입력하세요 : ";
	cin >> str;
	for (int i = 0; i < strlen(str); i++) {
		for (int j = 0; j <= i; j++) {
			cout << str[j];
		}cout << endl;
	}
}
int main()
{
	while (1) {
		int sel;
		cout << "원하는 과제를 입력하세요 : ";
		cin >> sel;
		if (sel == 0) { cout << "end!!" << endl; break; }
		else if (sel == 1) { problem1(); }
		else if (sel == 2) { problem2(); }
		else if (sel == 3) { problem3(); }
		else if (sel == 4) { problem4(); }
		else if (sel == 5) { problem5(); }
		else if (sel == 6) { problem6(); }
		else if (sel == 7) { problem7(); }
		else if (sel == 8) { problem8(); }
		cout << endl;
	}
	return 0;
}