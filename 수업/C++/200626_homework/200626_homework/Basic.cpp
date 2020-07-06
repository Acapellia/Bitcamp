#include<iostream>
#include<cstring>
using namespace std;
//1. 1 ~100까지 더한 결과를 출력하세요.
//cout을 사용하세요.
void problem1() {
	int sum = 0;
	for (int i = 1; i <= 100; i++) {
		sum += i;
	}
	cout << "sum : " << sum << endl;
}
//2. 1 ~100까지 한줄에 10개씩 출력하세요.
//정수는 탭으로 간격을 줄 것
void problem2() {
	for (int i = 1; i <= 100; i++) {
		cout << i << "	";
		if (i % 10 == 0) cout << endl;
	}
}
//3. C를 C++의 cout, cin을 사용하여 바꾸세요
//
//#include <stdio.h>
//int main() { // 문제에 주어진 코드
//	int k, n = 0;
//	int sum = 0;
//	printf("끝 수를 입력하세요>>");
//	scanf("%d", &n);
//	for (k = 1; k <= n; k++) {
//		sum += k;
//	}
//	printf("1에서 %d까지의 합은 %d 입니다.\n", n, sum);
//	return 0;
//}
int problem3() {
	int k, n = 0;
	int sum = 0;
	cout << "끝 수를 입력하세요>>";
	cin>>n;
	for (k = 1; k <= n; k++) {
		sum += k;
	}
	cout<<"1에서 " << n << "까지의 합은 " << sum << " 입니다."<< endl;
	return 0;
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
		cout << endl;
	}
	return 0;
}