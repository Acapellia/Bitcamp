#include<iostream>
using namespace std;
template<typename T>
T Add(T a, T b) { return a + b; }
void main()
{
	cout << Add(1,2) << endl;
	cout << Add(1.3,4.5) << endl;
}