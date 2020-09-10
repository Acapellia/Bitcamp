#include<iostream>
#include<string>
using namespace std;
void main()
{
	string song("falling in love with you");
	string elvis("elvis presely");
	string singer;

	cout << song << "을 부른 가수는";
	cin >> singer;

	if (elvis == singer) cout << "맞았습니다" << endl;
}