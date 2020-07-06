#include<iostream>
struct Point {
	int x, y;
	void Add(Point a, Point b) {
		x = a.x + b.x;
		y = a.y + b.y;
	}
	void Sub(Point a, Point b) {
		x = a.x - b.x;
		y = a.y - b.y;
	}
};
void main()
{
	Point ptA,ptB,ptResult;
	ptA.x = 100;
	ptA.y = 200;
	ptB.x = 50;
	ptB.y = 100;
	ptResult.Add(ptA, ptB);
	printf("[%d, %d]\n", ptResult.x, ptResult.y);
	ptResult.Sub(ptA, ptB);
	printf("[%d, %d]\n", ptResult.x, ptResult.y);
}