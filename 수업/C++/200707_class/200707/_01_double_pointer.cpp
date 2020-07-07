#include <iostream>

using namespace std;

/* 
int* ptr에서 
int*는 자료형이고 ptr은 변수이름이다
다만 ptr은 int변수나 int배열의 시작주소를
담을 수 있는 역할로 규정된 것이다
그래서 ptr도 &ptr을 출력하면
ptr의 주소가 출력이 된다.
*/
void main()
{
	int num = 10;
	int* ptr = &num;

	cout << &num << endl;
	cout << *ptr << endl;
	cout << sizeof(ptr) << endl;
	cout << &ptr << endl;
}