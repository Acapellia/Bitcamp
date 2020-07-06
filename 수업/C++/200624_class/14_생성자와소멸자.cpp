#include<iostream>
using namespace std;
class Point {
private:
	int x, y;
public:
	Point();
	Point(int _x, int _y);
	~Point();
public:
	void SetPoint(int _x, int _y);
	void AddPoint(Point& pt);
	void SubPoint(Point& pt);
	void MovePoint(int addX, int addY);
	void ShowPoint();
};
Point::Point() {
	x = 0;
	y = 0;
	cout << "생성자 호출" << endl;
}
Point::Point(int _x, int _y) {
	x = _x;
	y = _y;
	cout << "매개변수가 있는 생성자 호출" << endl;
}
Point::~Point() {
	cout << "소멸자 호출" << endl;
}
void Point::SetPoint(int _x, int _y) {
	x = _x;
	y = _y;
}
void Point::AddPoint(Point& pt) {
	x += pt.x;
	y += pt.y;
}
void Point::SubPoint(Point& pt) {
	x -= pt.x;
	y -= pt.y;
}
void Point::MovePoint(int addX, int addY) {
	x += addX;
	y += addY;
}
void Point::ShowPoint() {
	cout << "x, y : [" << x << ", " << y << "]" << endl;
}
void main()
{
	Point pt, pt1;
	pt.SetPoint(100, 100);
	pt1.SetPoint(30, 30);
	pt.AddPoint(pt1);
	pt.ShowPoint();
	pt.SubPoint(pt1);
	pt.ShowPoint();
	pt.MovePoint(100, 100);
	pt.ShowPoint();
}