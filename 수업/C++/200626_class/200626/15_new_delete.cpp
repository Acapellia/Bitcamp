#include<iostream>
using namespace std;
void main()
{
	//c
	int* num = (int*)malloc(sizeof(int));
	*num = 10;
	cout << *num << endl;
	free(num);

	//c++
	int* num1 = new int();
	*num1 = 20;
	cout << *num1 << endl;
	delete num1;
}