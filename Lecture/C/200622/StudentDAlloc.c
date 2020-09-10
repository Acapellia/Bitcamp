#include<stdio.h>
#include<stdlib.h>

void main()
{
	int stNum = 0;
	printf("몇명의 학생의 점수를 입력하시겠습니까? : ");
	scanf_s("%d", &stNum);

	int* pStScore = (int*)malloc(sizeof(int)*stNum);

	for (int i = 0; i < stNum; i++) {
		printf("%d번째 학생의 점수 입력 : ", i + 1);
		scanf_s("%d", &pStScore[i]);
	}printf("\n");
	
	for (int i = 0; i < stNum; i++) {
		printf("%d번째 학생의 점수 : ", i + 1);
		printf("%d\n", pStScore[i]);
	}

	free(pStScore);
}