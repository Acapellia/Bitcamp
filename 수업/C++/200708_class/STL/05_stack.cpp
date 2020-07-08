#include<iostream>
#include<stack>
using namespace std;
#define DATA_NUM 10
void main()
{
	stack<int> s;
	for (int i = 0; i < DATA_NUM; i++) {
		s.push((i+1) * 10);
	}

	for (int i = 0; i < DATA_NUM; i++) {
		cout << s.top() << " ";
		s.pop();
	}cout << endl;
}