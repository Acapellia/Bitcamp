#include<cstdio>
int add(int a, int b) {
	return a + b;
}
int sum(int a, int b) {
	return a - b;
}
//void Calc(int (*calc)(int a, int b)) {
//	int a = 3, b = 5;
//	int num = calc(a, b);
//	printf("num : %d", num);
//}
void main() {
	//Calc(add);
	int (*calc)(int a, int b);
	calc = add;
	printf("num : %d", calc(3,5));
}