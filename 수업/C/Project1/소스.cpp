#include<stdio.h>
#include<string.h> // 문자열
#include<math.h>
#include<stdlib.h> // 여러 유틸리티
#include<conio.h> // 콘솔용 입출력
#include<time.h>
#include<Windows.h>
/*int main() {
	int x, y;
	x = 2; y = 1 * x + 5;
	for (int r = 0; r < 10; r++) {
		printf("[%2d]", r);
		for (int c = 0; c < 10; c++) {
			if (r == y && c == x) {
				printf("##");
			}
			else {
				printf("  ");
			}
		}printf("\n");
	}
}*/
/*int main()
{
	char ch = 'A';
	printf("size : %d\n",sizeof(ch));
	printf("address : %d\n", &ch);
	printf("address size : %d\n", sizeof(&ch));
	char* p;
	printf("size : %d\n", sizeof(p));
	printf("address : %d\n", &p);
	printf("address size : %d\n", sizeof(&p));

	p = &ch;
	printf("%d\n",p);
	printf("%c\n", *p);
	printf("%d\n", &p);

	*p = 'B';
	printf("ch : %c\n", ch);
	
	int num[10] = {601,713,592,516,912,815};
	printf("address : %d\n", num);
	printf("n : %d\n", sizeof(*num));
	printf("size : %d\n", sizeof(*(&num)));

	int (*p1)[10];
	p1 = &num;
	printf("%d\n", (*p1)[1]);
	return 0;
}*/