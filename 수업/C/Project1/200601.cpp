#include<stdio.h>
#include<string.h> // 문자열
#include<math.h>
#include<stdlib.h> // 여러 유틸리티
#include<conio.h> // 콘솔용 입출력
#include<time.h>
/*
i = 0 * 3 + 2    2   
i = 1 * 3 + 2    5
i = 2 * 3 + 2    8
*/
int main()
{
	for (int i = 0; i < 3; i++) {
		for (int j = 1; j <= 9; j++) {
			for (int k = (i*3+2); k < (i * 3 + 2) + 3; k++) {

				printf("%2d * %2d = %2d ", k, j, k * j);
			}
			printf("\n");
		}
		printf("------------------------------------------\n");
	}
}
// tank 움직임
// 제어문 : if while
// 자료형 : int 배열 x



/*void binary(int n){
	for (int b = 11; b >= 0; b--) {
		if ((n & (1 << b)) != 0)
			printf("1");
		else
			printf("0");
	}printf("\n");
}

// 중복없는 3자리 정수를 10개 이상 출력하시오
// flag = bit (비트연산자로 확인 및 변경)

int checkFlags(unsigned int flags, int num) {
	//binary(flags); binary(1 << num); binary(flags & (1 << num));
	//printf("%d\n", ((flags & (1 << num) != 0)) ? 1 : 0);
	return ((flags & (1 << num)) != 0) ? 1 : 0;
}
unsigned int setFlags(unsigned int flags, int idx) {
	unsigned int set = ~(1 << idx);
	return flags & set;
}
int main()
{
	srand((unsigned int)time(NULL));
	int cnt = 0;
	while (cnt++ != 10) {
		unsigned int flags = 0x3FF;
		int num = 0;
		for (int nc = 0; nc < 3; nc++) {
			while (1) {
				int tempNum = rand() % 10;
				if (nc == 0 && tempNum == 0) continue;
				//printf("temp : %d\n", tempNum);
				if (checkFlags(flags, tempNum)) {
					num = num * 10 + tempNum;
					flags = setFlags(flags, tempNum);
					break;
				}
				else { 
					//printf("x\n");
				}
			}
		}
		printf("num %-2d : %d\n", cnt, num);
	}
}*/