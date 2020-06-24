#include<stdio.h>
//1. 2개의 정수를 입력받고 큰 값을 반환하는 함수와
//작은 값을 반환하는 함수를 작성하고 사용하세요
int findMax(int x, int y) { return x > y ? x : y; }
int findMin(int x, int y) { return x < y ? x : y; }
void problem1() {
	printf("2개의 정수를 입력하세요 : ");
	int x, y; scanf("%d %d", &x, &y);
	int max = findMax(x, y);
	int min = findMin(x, y);
	printf("max : %d   min : %d\n", max, min);
}
//2. 3개의 정수를 입력받고 큰 값을 반환하는 함수와
//작은 값을 반환하는 함수를 작성하고 사용하세요
int find3Max(int x, int y, int z) { 
	int ret;
	ret = x > y ? x : y;
	return ret > z ? ret : z;
}
int find3Min(int x, int y, int z) { 
	int ret;
	ret = x < y ? x : y;
	return ret < z ? ret : z;
}
void problem2() {
	printf("3개의 정수를 입력하세요 : ");
	int x, y, z; scanf("%d %d %d", &x, &y, &z);
	int max = find3Max(x, y, z);
	int min = find3Min(x, y, z);
	printf("max : %d   min : %d\n", max, min);
}
//3. 양의 정수를 입력받고 그 수만큼 "감사합니다"를 출력하는 함수를 만드세요
void problem3() {
	printf("양의 정수를 입력하세요 : ");
	int cnt; scanf("%d", &cnt);
	for (int i = 1; i <= cnt; i++) {
		printf("감사합니다\n");
	}printf("\n");
}
//4. 5를 입력하면
//o
//* o
//* *o
//* **o
//* ***o
//이렇게 출력하는 함수를 만드세요
//void triangle(int num, char mainChar, char endChar);
//
//사용은 triangle(5, '*', 'o');
//이렇게 하면 됩니다.
int problem4(int num, char mainChar, char endChar) {
	for (int i = 1; i <= num; i++) {
		for (int j = 1; j <= i; j++) {
			if (j == i) printf("%c", endChar);
			else printf("%c", mainChar);
		}printf("\n");
	}printf("\n");
}
void main()
{
	int select;
	while (1) {
		printf("선택 : ");
		scanf_s("%d", &select);
		if (select == 0) break;
		else if (select == 1) problem1();
		else if (select == 2) problem2();
		else if (select == 3) problem3();
		else if (select == 4) problem4(5,'*','o');
	}
}