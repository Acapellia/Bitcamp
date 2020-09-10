#include<iostream>
using namespace std;
int add(int a, int b) {
	return a + b;
}
double add(double a, double b) {
	return a + b;
}

int main()
{
	cout << add(1, 5) << endl;
	cout << add(1.0, 5.3) << endl;
	return 0;
}