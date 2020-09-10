/* 
<연산자 오버로딩>
; 연산자 == 기호
  기호 => 직관적인 느낌
; 클래스에서
  개발자가 연산기호의 직관적인 느낌을 살려
  재정의(편집)하게 해주는 기능으로써
  연산자를 함수로 편집하게 해준다
*/

#include "Position.h"

void main()
{
	Position pos(10, 10);
	/*
	++pos;는 컴파일러에 의해서
	pos.operator++(); 와 같은
	함수 호출로 변경됨

	결국 객체의 연산자 호출은 함수 호출이다
	*/
	++pos;
	pos.showPosition();
	++++pos; // ++(++pos);
	pos.showPosition();
}