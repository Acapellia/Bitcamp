// c에서 쓰는 헤더의 .h를 빼고 앞에 c를 붙인다
#include <cstdio>
#include <cmath>
void main()
{
	int num = 0;
	printf("음수 입력 : ");
	scanf("%d", &num);
	printf("%d\n", abs(num));
}