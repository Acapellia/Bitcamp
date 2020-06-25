#include<iostream>
using namespace std;
template<typename T>
T Add(T a, T b) { return a + b; }
template<>
char* Add(char* a, char* b) {
	char* p = new char[strlen(a) + strlen(b) + 1];
	int len = strlen(a);
	strncpy(p, a, len);
	int len2 = strlen(b);
	strncpy(p + len, b, len2);
	p[len + len2] = 0;
	return p;
}
template<>
float Add(float a, float b) {
	return a + b + 3.0;
}
void main()
{
	char* p;
	cout << Add(1, 2) << endl;
	cout << Add(1.3, 4.5) << endl;
	cout << (p = Add<char*>("아름다운", "대한민국")) << endl;
	cout << Add<float>(1.3, 4.5) << endl;
	delete[] p;
}