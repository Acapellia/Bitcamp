#include<iostream>
#include<vector>
using namespace std;
void main()
{
	vector<int> dArray(6);
	for (int i = 0; i < 6; i++) {
		dArray[i] = i * 2;
	}
	dArray.push_back(7);
	dArray.push_back(8);

	for (int i = 0; i < dArray.size(); i++) {
		cout << dArray[i] << " ";
	}
}