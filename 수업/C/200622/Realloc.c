#include<stdio.h>
#include<stdlib.h>
/*
- realloc ���Ҵ�
- malloc/calloc���� �Ҵ��� ������ ���̰ų� ���� �� ���
- ���Ӱ��� �� �Ҵ��� ���� �� ��ġ�� �̵�
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