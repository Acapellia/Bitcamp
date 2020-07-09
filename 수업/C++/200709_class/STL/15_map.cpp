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
		cout << "Month이름을 영어 대문자로 3글자 입력하세요 : ";
		string input;
		cin >> input;
		int day = monthDayMap[input];
		if (day == 0) cout << input << "는 없습니다." << endl;
		else cout << input << "은 " << day << "일 까지 있습니다." << endl;
	}
}