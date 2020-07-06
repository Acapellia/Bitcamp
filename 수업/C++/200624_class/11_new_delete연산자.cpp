#include<iostream>
using namespace std;
void main()
{
	int* num = new int();
	*num = 10;
	cout << *num << endl;
	delete num;
}