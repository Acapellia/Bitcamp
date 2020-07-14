#include<iostream>
#include<set>
using namespace std;

void main() {
	set<string> s;

	s.insert("바나나");
	s.insert("사과");
	s.insert("연필");
	s.insert("컴퓨터");
	s.insert("치킨");
	while (true) {
		string temp;
		cout << "찾고 싶은 물품을 입력 : ";
		cin >> temp;

		set<string>::iterator it = s.find(temp);
		if (it != s.end()) {
			cout << temp << "가 있다." << endl;;
		}
		else {
			cout << temp << "가 없다." << endl;
		}
	}
}