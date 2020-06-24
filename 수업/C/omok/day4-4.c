#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 전역변수 : 함수 밖에서 선언된 변수
//	- 이 소스 파일에 정의된 모든 함수들이 사용 가능
int gValue = 10; // 전달하는 방법이 너무 어려워요 ~ 권장안함
extern int ext_value;// 다른 소스파일에 정의된 전역변수의 사용
// 내 전역변수를 사용하지 마라
static int internal_value;// extern 불가

int f2() {
	// 지역변수에 static 
	static int static_value = 0;// 유지해라... 없애지마라

	int v3 = 100;
	// 이 함수가 살아 있는 동안에만 사용 가능
	gValue = 100;

	return 0;
}

int f1() {
	f2();
	gValue = 10;
	return 0;
}

int static_fn() {
	static int cnt = 0;// 이 변수 값을 계속 유지
	cnt++;
	return cnt;
}
// 포인터변수- 주소를 알면 변경이 가능하다....
int updateNumber(int* param) {// param = &cnt;
	int v = *param;// v = cnt
	*param = v * 10;
	return 0;
}
int main(int argc, char** argv) {
	// 함수 호출된 횟수 알고 싶다....
	int cnt = 2;
	// 자신의 변수를 다른 함수가 변경하도록 
	updateNumber(&cnt);// 주소를 전달
	printf("%d \n", cnt);

	return 0;
}

int main_01(int argc, char** argv) {
	// 선언 위치에 따른 변수의 구분 : 변수 지역성
	// 지역변수 : 함수 내에서 선언된 변수 : 이 함수만 사용할 수 있다.
	// { } 도 지역성을 가진다...
	int v1 = 10;
	int* p;
	{
		int v2 = 1000;
		v1 = 20;
		v2 = 2000;
		p = &v2;
		printf("v2 : %p \n", &v2);
	}
	printf("v2 : %d \n", *p);
	*p = 3000;
	printf("%p -> %d \n", p, *p);
// 포인터을 이용한 간접 참조 방식 가능
	// - 변수가 살아 있는 경우만....
//	v2 = 3000;// 지역 내 선언된 변수는 지역 밖에서 사용 불가



	return 0;
}