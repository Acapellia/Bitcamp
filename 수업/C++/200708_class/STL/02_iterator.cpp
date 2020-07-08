#include<iostream>
#include<vector>
using namespace std;
void main()
{
	vector<int> dArray(6);

	for (int i = 0; i < dArray.size(); i++) {
		dArray[i] = i;
	}
	dArray.push_back(6);
	dArray.push_back(7);

	vector<int>::iterator iter = dArray.begin();
	while (iter != dArray.end()) {
		cout << *iter++ << " ";
	}cout << endl;

	vector<int>::iterator it;
	for (it = dArray.begin(); it != dArray.end(); it++) {
		cout << *it << " ";
	}cout << endl;
	
	vector<int>::reverse_iterator rit;
	for (rit = dArray.rbegin(); rit != dArray.rend(); rit++) {
		cout << *rit << " ";
	}cout << endl;
}