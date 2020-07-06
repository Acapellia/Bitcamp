#include<iostream>
using namespace std;
struct Point {
	int x, y;
	void insertPoint(int x, int y) {
		this->x = x; this->y = y;
	}
	void showPoint() {
		cout << "[ " << x << ", " << y << " ]" << endl;
	}

};
int main()
{
	Point p;
	p.insertPoint(6, 1);
	p.showPoint();
	return 0;
}