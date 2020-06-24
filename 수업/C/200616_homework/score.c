#include<stdio.h>
//1. 3명의 학생의 이름과 국어점수를 입력받고
//총점과 평균
//각 학생 이름과 점수를 출력하세요
//이름과 국어점수 모두 배열을 사용하세요
#define SIZE 3
int main()
{
	char name[SIZE][20] = { 0 };
	int kor[SIZE] = { 0 };
	int sum = 0;
	double avg = 0.0;
	for (int i = 0; i < SIZE; i++) {
		printf("학생 %d의 이름과 국어성적을 입력하세요 : ",i+1);
		scanf("%s %d", name[i], &kor[i]);
		sum += kor[i];
	}
	avg = (double)sum / SIZE;
	for (int i = 0; i < SIZE; i++) {
		printf("학생이름 : %s 국어성적 : %d\n", name[i], kor[i]);
	}
	printf("학생 총합 : %d\n", sum);
	printf("학생 평균 : %.2lf\n", avg);
}