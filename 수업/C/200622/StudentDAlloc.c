#include<stdio.h>
#include<stdlib.h>

void main()
{
	int stNum = 0;
	printf("����� �л��� ������ �Է��Ͻðڽ��ϱ�? : ");
	scanf_s("%d", &stNum);

	int* pStScore = (int*)malloc(sizeof(int)*stNum);

	for (int i = 0; i < stNum; i++) {
		printf("%d��° �л��� ���� �Է� : ", i + 1);
		scanf_s("%d", &pStScore[i]);
	}printf("\n");
	
	for (int i = 0; i < stNum; i++) {
		printf("%d��° �л��� ���� : ", i + 1);
		printf("%d\n", pStScore[i]);
	}

	free(pStScore);
}