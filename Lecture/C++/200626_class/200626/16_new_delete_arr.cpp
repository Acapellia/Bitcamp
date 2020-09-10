#include<iostream>
using namespace std;
#define NUM 10
void main()
{
	int* pnum = new int[NUM]();
	for (int i = 0; i < NUM; i++) {
		pnum[i] = i;
	}
	for (int i = 0; i < NUM; i++) {
		cout << pnum[i] << " ";
	}
	cout << endl;
	delete[] pnum;
}