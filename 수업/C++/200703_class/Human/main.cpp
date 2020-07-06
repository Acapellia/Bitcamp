#include<iostream>
#include "Human.h"
#include "ComputerEngineer.h"
#include "Developer.h"
#include "ServerManager.h"
using namespace std;
// 생성자를 만들때 부모 생성자로부터 값을 받아 오는겨우
// class Parent{
// private:
// int X,Y;
// public:
// Parent(int x, int y){ X=x; Y=y}
//}
//Child(int x, int y, int n) : Parent(x,y){ int N=n;}
// 다음과 같이 부모의 변수가 아닌 생성자의 변수를 써줘야 한다.
void main()
{
	Developer dev;
	ServerManager sm;
}