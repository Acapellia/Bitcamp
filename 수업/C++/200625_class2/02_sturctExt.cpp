#include<iostream>
using namespace std;
struct Point {
	int x, y;
};
int main()
{
	Point p = { 1,3 };
	cout << "x : " << p.x << " " << "y : " << p.y << endl;
	return 0;
}