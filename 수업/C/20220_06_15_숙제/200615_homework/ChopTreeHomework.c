#include<stdio.h>
// 1번
// 숫자를 입력받고 숫자 만큼 나무를 찍고 다 찍으면 "나무를 캐었다" 
// 2번
// 1번을 함수로 만들고 함수에 숫자를 전달하면 "나무를 찍는다"를 반복
// 3번
// 함수를 만들어서 func(반복횟수,해당 번째마다 쿵을 출력)
// chopTree(10,3)
// 4번
// chopTree(10,3,2) 3번에 한번 쿵 2번에 한번 쩍
void chopTree(int n, int c,int c2) {
	for (int i = 1; i <= n; i++) {
		printf("나무를 %2d번 찍었다!!\n",i);
		if (i%c == 0) printf("쿵~~\n");
		if (i%c2 == 0) printf("쩍~~\n");
	}
	printf("나무를 베었다!!!\n\n");
}
void main()
{
	int n,c,c2; 
	while (1) {
		printf("반복횟수 n과 쿵 출력 c 쩍 출력 c2: ");
		scanf_s("%d %d %d", &n, &c, &c2);
		printf("\n");
		if (n == 0) break;
		chopTree(n, c, c2);
	}
}

