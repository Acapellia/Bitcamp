#include<iostream>
using namespace std;
inline int Add(int a, int b) { return a + b; }
void main()
{
	int result = 0;
	for (int i = 0; i < 100; i++) {
		result = Add(result, i++);
		cout << result << endl;
	}
}