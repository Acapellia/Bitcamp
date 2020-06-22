#include<stdio.h>
#include<stdlib.h>

/*
- 힙영역에 할당
- 필요할 때 할당/삭제 마음대로 할 수 있음
- 큰 메모리가 필요할 때
*/
/*
- 전역변수
- 메모리가 사라지지 않는다
- 하지만 처음에 할당크기를 무조건 정해야 한다
- 함수 호출 시 마다 새로운 메모리를 추가하는 것은 불가능하다
*/
char* getName() {
	char* name = (char*)malloc(sizeof(char) * 20);
	printf("이름 입력 : ");
	fgets(name, sizeof(char) * 20, stdin);
	printf("이름 : %s\n", name);
	printf("이름 주소 : %p\n", name);
	return name;
}
int main()
{
	char* pName = getName();

	printf("이름 : %s\n", pName);
	printf("pName : %p\n", pName);
	free(pName);
	return 0;
}