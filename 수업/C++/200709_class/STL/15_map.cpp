#include<iostream>
#include<map>
using namespace std;
void main()
{
	map<string, int> monthDayMap;
	string month[] = {
		"JAN", "FEB", "MAR", "AFR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"
	};
	int days[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int len = sizeof(days) / sizeof(int);
	for (int i = 0; i < len; i++) {
		monthDayMap.insert(make_pair(month[i], days[i]));
	}

	while (true) {
		cout << "Month�̸��� ���� �빮�ڷ� 3���� �Է��ϼ��� : ";
		string input;
		cin >> input;
		int day = monthDayMap[input];
		if (day == 0) cout << input << "�� �����ϴ�." << endl;
		else cout << input << "�� " << day << "�� ���� �ֽ��ϴ�." << endl;
	}
}