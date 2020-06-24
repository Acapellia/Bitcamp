#include<stdio.h>
#include<conio.h>
// ctrl k f 코드 정렬
int main()
{
	printf("***********************\n\n");
	while (1) {
		printf("1. 주소 입력\n");
		printf("2. 주소 검색\n");
		printf("3. 주소 수정\n");
		printf("4. 주소 삭제\n");
		printf("5. 프로그램 종료\n\n");

		printf("번호를  선택하세요 : ");
		char sel = _getch();
		printf("\n%c 번 선택하셨습니다\n", sel);

		if (sel == '5') {
			printf("프로그램을 종료합니다\n\n");
			printf("***********************\n\n");
			break;
		}
		else {
			printf("업무를 처리하였습니다\n\n");
			printf("***********************\n\n");
		}

	}
	return 0;
}