#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<conio.h>
#include<math.h>
#include<windows.h>

// Ctrl k c / ctrl k u 주석 처리/해제
int main(void)
{
	int num = 100;
	char ch = 'A';
	double fnum = 3.14;
	char str[] = "korean";

	printf("정수 : %d\n", num);
	printf("문자 : %c %d\n", ch,ch);
	printf("실수 : %lf\n", fnum);
	printf("문자열 : %s\n", str);

	return 0;
}