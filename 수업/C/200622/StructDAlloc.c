#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct _Address {
	char name[20];
	char address[30];
	int age;
}Address;

void inputAddress(Address* pAddr) {
	printf("�̸� �Է� : "); fgets(pAddr->name, sizeof(pAddr->name), stdin); 
	pAddr->name[strlen(pAddr->name) - 1] = 0;
	printf("�ּ� �Է� : "); fgets(pAddr->address, sizeof(pAddr->address), stdin); 
	pAddr->address[strlen(pAddr->address) - 1] = 0;
	printf("���� �Է� : "); scanf_s("%d",&pAddr->age); getchar();
}
void showAddress(Address* pAddr) {
	printf("�̸� : %s / �ּ� : %s / ���� : %d\n", pAddr->name, pAddr->address, pAddr->age);
}
void main()
{
	Address* pAddr;
	int num = 0;
	
	printf("�� ���� �ּҸ� �����Ͻðڽ��ϱ�? : ");
	scanf_s("%d", &num);
	pAddr = (Address*)malloc(sizeof(Address) * num);
	getchar();

	for (int i = 0; i < num; i++) {
		inputAddress(pAddr + i);
	}
	for (int i = 0; i < num; i++) {
		showAddress(pAddr + i);
	}

	free(pAddr);
}