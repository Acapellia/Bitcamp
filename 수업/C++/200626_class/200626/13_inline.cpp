#include<iostream>
#define MUL(x,y) x*y
using namespace std;
__int64 square(int a, int b) {
	__int64 result = 1;
	for (int i = 0; i < b; i++)
		result *= a;
	return result;
}
int mul(int a, int b) {
	return a * b;
}
void main()
{
	cout << square(15, 5) << endl;
	cout << MUL(3, 5) << endl;
}