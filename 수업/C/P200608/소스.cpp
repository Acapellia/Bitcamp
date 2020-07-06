#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<math.h>
#include<algorithm>


int op4pointer() {
	char str[80]="korea";
	char* p = str;
	printf(" %p - %c \n", &str[0], str[0]);
	printf(" %p - %c \n", &str[1], str[1]);
	printf(" %p - %c \n", &str[2], str[2]);
	printf(" %p - %c \n", &str[3], str[3]);
	printf(" %p - %c \n", &str[4], str[4]);

	printf(" %p - %c \n", p+0, *(p+0));
	printf(" %p - %c \n", p + 1, *(p + 1));
	printf(" %p - %c \n", p + 2, *(p + 2));
	printf(" %p - %c \n", p + 3, *(p + 3));
	printf(" %p - %c \n", p + 4, *(p + 4));
	return 0;
}
int string2pointer() {
	char aStr[10] = "abcdefg";
	char* pStr;
	
	pStr = aStr;
	pStr = &aStr[0];

	pStr[0] = 's';
	pStr[1] = 'h';

	char(*pp)[80];
	return 0;
}

// const 변경 불가능
int ptr4string() {
	int* p;
	int num;
	// 주소 변경 가능
	const int* cp ;
	cp = &num;
	int *const ccp = &num;
	*ccp = num;
	return 0;
}

int main()
{
	/*char s[80] = { 0 };
	char c;
	int i = 0;
	//scanf("%s", s);
	while ((c=getchar())!='\n') {
		if (i != 0) {
			if ('a' <= c && c <= 'z') {
				c -= 32;
			}
		}
		s[i++] = c;
	}s[i] = 0;
	printf("str : %s\n", s);*/
	op4pointer();
	return 0;
}