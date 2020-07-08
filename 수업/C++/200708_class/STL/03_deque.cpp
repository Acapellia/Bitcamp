#include<iostream>
#include<deque>
using namespace std;

void main()
{
	const int DATA_NUM = 6;
	deque<int> dEnded(DATA_NUM);
	for (int i = 0; i < dEnded.size(); i++)
		dEnded[i] = i;
	dEnded.push_back(7);
	dEnded.push_front(6);
	
	for (int i = 0; i < dEnded.size(); i++)
		cout << dEnded[i] << " ";
	cout << endl;
	
	deque<int>::iterator iter = dEnded.begin();
	while (iter != dEnded.end()) {
		cout << *iter++ << " ";
	}cout << endl;
}