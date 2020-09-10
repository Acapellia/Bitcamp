#include<iostream>
using namespace std;
template <typename T>
T add(T a, T b) {
	return a + b;
}
void main()
{
	cout << add(1, 2) << endl;
	cout << add(1.0f, 2.0f) << endl;
	cout << add(1.5, 2.4) << endl;
}