// 1. 변수의 선언위치
// c : 지역이 시작된 후 바로 선언해야 한다
// c++ : 자유롭게 선언가능
#include<iostream>
using namespace std;
int main()
{
	int num = 0;
	cout << "반복 횟수 입력 : " << endl;
	cin >> num;
	for (int i = 0; i < 10; i++)
		cout << num << " ";
	cout << endl;
	return 0;
}