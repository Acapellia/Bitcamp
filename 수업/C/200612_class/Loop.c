#include<stdio.h>
#include<conio.h>
// ctrl k f �ڵ� ����
int main()
{
	printf("***********************\n\n");
	while (1) {
		printf("1. �ּ� �Է�\n");
		printf("2. �ּ� �˻�\n");
		printf("3. �ּ� ����\n");
		printf("4. �ּ� ����\n");
		printf("5. ���α׷� ����\n\n");

		printf("��ȣ��  �����ϼ��� : ");
		char sel = _getch();
		printf("\n%c �� �����ϼ̽��ϴ�\n", sel);

		if (sel == '5') {
			printf("���α׷��� �����մϴ�\n\n");
			printf("***********************\n\n");
			break;
		}
		else {
			printf("������ ó���Ͽ����ϴ�\n\n");
			printf("***********************\n\n");
		}

	}
	return 0;
}