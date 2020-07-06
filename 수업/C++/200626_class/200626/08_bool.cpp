#include<iostream>
using namespace std;
void main()
{
	int num;
	cout << "숫자 입력(1이면 3개 반복): ";
	cin >> num;

	int cnt = 0;
	bool isRun = num == 1;
	while (isRun) {
		cout << cnt << endl;
		cnt++;
		if (cnt == 3) break;
	}
}
