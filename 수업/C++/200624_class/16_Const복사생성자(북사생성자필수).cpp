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
		cout << "�Ű����� �ִ� ������ ȣ��";
	}
	// �ݵ�� ���� �����ڰ� �ʿ��� ��� - > �����Ҵ� ���� ���� delete�� ���� �������µ� ���縦 �� �� ��ü�� ������ �� ��
	Point(const Point& apt) {
		Name = new char[strlen(Name) + 1];
		memset(Name, 0, strlen(apt.Name) + 1);
		strncpy(Name, apt.Name, strlen(apt.Name));
		x = apt.x;
		y = apt.y;
		cout << "��������� ȣ��" << endl;
	}
	~Point() {
		delete[] Name;
		cout << "�Ҹ��� ȣ��" << endl;
	}
	void ShowPoint() {
		cout << Name << " " << x << " " << y << endl;
	}
};
int main()
{
	char* n = "����";
	Point pt(n, 100, 100);
	Point pt1 = pt;
	pt1.ShowPoint();

	return 0;
}