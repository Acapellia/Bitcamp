#include<stdio.h>
#include<stdlib.h>

/*
- �������� �Ҵ�
- �ʿ��� �� �Ҵ�/���� ������� �� �� ����
- ū �޸𸮰� �ʿ��� ��
*/
/*
- ��������
- �޸𸮰� ������� �ʴ´�
- ������ ó���� �Ҵ�ũ�⸦ ������ ���ؾ� �Ѵ�
- �Լ� ȣ�� �� ���� ���ο� �޸𸮸� �߰��ϴ� ���� �Ұ����ϴ�
*/
char* getName() {
	char* name = (char*)malloc(sizeof(char) * 20);
	printf("�̸� �Է� : ");
	fgets(name, sizeof(char) * 20, stdin);
	printf("�̸� : %s\n", name);
	printf("�̸� �ּ� : %p\n", name);
	return name;
}
int main()
{
	char* pName = getName();

	printf("�̸� : %s\n", pName);
	printf("pName : %p\n", pName);
	free(pName);
	return 0;
}