#include<iostream>
// 연산자 오버로딩
// c에서 << >> 는 비트 연산자이지만
// c++에서 같은 연산자로 입출력을 할 때 사용한다
// 같은 연산자로 다른 기능을 만들 수 있다.

void main()
{
	int num, num2;
	std::cout << "정수 2개 입력 : " << std::endl;
	std::cin >> num >> num2;
	std::cout << num << " + " << num2 << " = " << num + num2 << std::endl;
}