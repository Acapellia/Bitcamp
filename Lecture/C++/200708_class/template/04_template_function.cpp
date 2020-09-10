#include <iostream>

/*  
C++ 클래스를 통해 확장과 설계를 꿈꾸는 개발자 그룹과
별개로 다른 그룹에서는
논리가 동일한 문법을 쉽게 확장할 수 있는
Template문법을 연구적용하기 시작한다
*/
/* Template은 Generic이라는 명칭으로 더 널리
사용되고 있다.
  주로 논리는 동일하고 자료형만 다른 함수나
  클래스 구현에 사용된다.
  대표적인 예가 자료구조, 알고리즘이다.
  그래서 Template으로 만들어진 라이브러리가
  STL이다.
  
  C#/Java에서는 Generic이라고 표현하고
  이를 통해 만들어진 라이브러리를 Collection이라고
  표현한다.
*/

using namespace std;

/* 형판(形板) == 붕어빵틀
add함수를 찍어내는 틀
재료 : int, double
*/
/* 
add<int>(100, 200);을 처리할 때
int add(int a, int b);함수를 만든다.

add<double>(2.5, 3.4);을 처리할 때
double add(double a, double b);함수를 만든다.
*/

//template<class T>
template<typename T>
T add(T a, T b) {
	return a + b;
}

void main()
{
	cout << add<int>(100, 200) << endl;
	cout << add<double>(2.5, 3.4) << endl;

	//cout << add(100, 200) << endl;
	//cout << add(2.5, 3.4) << endl;
}