#include<iostream>
using namespace std;
// char* str = "스트링" 다음과 같이 " "로 초기화 할때
// "const char *" 형식의 값을 사용하여 "char *" 형식의 엔터티를 초기화할 수 없습니다.
// 1) 프로젝트 속성 -> c/c++ -> 언어 -> 준수모드 -> 아니오
// 2) const char* str = "스트링" 과 같이 변경

int main()
{
	const char* temp = "템프";
	// const는 다음에 오는 값을 상수화 한다.
	// const char* dest -> char 값 변경 불가.
	// char* const dest - > dest 주소 변경 불가.
	const char* dest;
	dest = temp;
	printf("%s", dest);
	return 0;
}