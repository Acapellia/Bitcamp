#include<cstdio>
void korPresentation() {
	printf("������ �Է��ϼ��� : ");
}
void engPresentation() {
	printf("Input Integer : ");
}
int inputValue(void (*present)()) {
	present();
	int num = 0;
	scanf_s("%d", &num, sizeof(num));
	return num;
}
void main() {
	int value = 0;
	value = inputValue(korPresentation);
	printf("�Է� ���� %d �Դϴ�.\n", value);
	value = inputValue(engPresentation);
	printf("Input Value is %d.\n", value);
}