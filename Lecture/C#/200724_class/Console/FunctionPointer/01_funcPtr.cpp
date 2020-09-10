#include<cstdio>
void korPresentation() {
	printf("정수를 입력하세요 : ");
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
	printf("입력 값은 %d 입니다.\n", value);
	value = inputValue(engPresentation);
	printf("Input Value is %d.\n", value);
}