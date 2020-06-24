#include<iostream>
using namespace std;
class Point {
private:
	char* Name;
	int x, y;
public:
	Point() {}
	Point(char* _Name, int _x, int _y) {
		Name = new char[strlen(_Name) + 1];
		memset(Name, 0, strlen(_Name) + 1);
		strncpy(Name, _Name, strlen(_Name));
		x = _x;
		y = _y;
		cout << "매개변수 있는 생성자 호출";
	}
	// 반드시 복사 생성자가 필요한 경우 - > 동적할당 해준 곳이 delete로 인해 지워졌는데 복사를 해 간 객체가 참조를 할 때
	Point(const Point& apt) {
		Name = new char[strlen(Name) + 1];
		memset(Name, 0, strlen(apt.Name) + 1);
		strncpy(Name, apt.Name, strlen(apt.Name));
		x = apt.x;
		y = apt.y;
		cout << "복사생성자 호출" << endl;
	}
	~Point() {
		delete[] Name;
		cout << "소멸자 호출" << endl;
	}
	void ShowPoint() {
		cout << Name << " " << x << " " << y << endl;
	}
};
int main()
{
	char* n = "원점";
	Point pt(n, 100, 100);
	Point pt1 = pt;
	pt1.ShowPoint();

	return 0;
}