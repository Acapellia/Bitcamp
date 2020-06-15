#include "turboc.h"
// 함수를 만드는 2가지 목적
// 1. 반복되는 코드의 규칙성을 찾아서 변하는 요소만 매개변수로 지정해서 묶어준다.
// 2. 업무를 적절한 단위로 그룹화하여 전체 흐름을 정리할 수 있다.
enum {
	INPUT_ADDR = 1, 
	SEARCH_ADDR,
	UPDATE_ADDR,
	DELETE_ADDR, 
	PRINTALL_ADDR,
	EXIT
};
void viewMenu() {
	printf("\n\t<주소록 관리 프로그램>\n");
	printf("1. 입력\n");
	printf("2. 검색\n");
	printf("3. 수정\n");
	printf("4. 삭제\n");
	printf("5. 전체검색\n");
	printf("6. 종료\n");
}
int getSelNum() {
	int selNum = 0;
	printf("\n번호를 선택하세요 : ");
	scanf_s("%d", &selNum);
	return selNum;
}
void inputAddress() {
	printf("입력하였습니다\n");
}
void searchAddress() {
	printf("검색하였습니다\n");
}
void updateAddress() {
	printf("수정하였습니다\n");
}
void deleteAddress() {
	printf("삭제하였습니다\n");
}
void printAll() {
	printf("전체 검색하였습니다\n");
}
void exitProgram() {
	printf("종료하였습니다\n");
	
}
int processWork(int selNum) {
	switch (selNum) {
	case INPUT_ADDR: inputAddress(); break;
	case SEARCH_ADDR: searchAddress(); break;
	case UPDATE_ADDR: updateAddress(); break;
	case DELETE_ADDR: deleteAddress(); break;
	case PRINTALL_ADDR: printAll(); break;
	case EXIT: exitProgram(); return 0;
	default: printf("잘 못 입력하셨습니다\n"); break;
	}
	return 1;
}
void laterProcess() {
	getchar(); getchar(); clrscr();
}
void main()
{
	int selNum = 0;
	int isRun = 1;
	while (isRun) {
		viewMenu();
		selNum = getSelNum();
		isRun = processWork(selNum);
		laterProcess();
	}
}