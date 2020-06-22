#include<stdio.h>
#include<stdlib.h>
/*
- realloc 재할당
- malloc/calloc으로 할당한 공간을 늘이거나 줄일 때 사용
- 연속공간 상 할당을 못할 때 위치를 이동
*/
#define ALLOC_NUM 5

void main()
{
	int i = 0;
	int allocCnt = ALLOC_NUM;
	int* pNum = (int*)malloc(sizeof(int) * allocCnt);
	
	while (i < allocCnt) {
		printf("Input Num : ");
		scanf_s("%d", &pNum[i]); getchar();
		i++;
		if (i == allocCnt) {
			printf("Memory Full!!\n");
			printf("Are you sure you want to realloc? : ");
			char ans = getchar();
			if (ans == 'Y' || ans == 'y') {
				allocCnt += ALLOC_NUM;
				pNum = (int*)realloc(pNum,sizeof(int) * allocCnt);
			}
			else if (ans == 'N' || ans == 'n') {
				for (int i = 0; i < allocCnt; i++)
					printf("%d ", pNum[i]);
				printf("\n");
			}
			else {
				printf("Invalid Value\n");
			}
		}
	}
	free(pNum);
}