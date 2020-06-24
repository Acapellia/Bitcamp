#include "turboc.h"
// �Լ��� ����� 2���� ����
// 1. �ݺ��Ǵ� �ڵ��� ��Ģ���� ã�Ƽ� ���ϴ� ��Ҹ� �Ű������� �����ؼ� �����ش�.
// 2. ������ ������ ������ �׷�ȭ�Ͽ� ��ü �帧�� ������ �� �ִ�.
enum {
	INPUT_ADDR = 1, 
	SEARCH_ADDR,
	UPDATE_ADDR,
	DELETE_ADDR, 
	PRINTALL_ADDR,
	EXIT
};
void viewMenu() {
	printf("\n\t<�ּҷ� ���� ���α׷�>\n");
	printf("1. �Է�\n");
	printf("2. �˻�\n");
	printf("3. ����\n");
	printf("4. ����\n");
	printf("5. ��ü�˻�\n");
	printf("6. ����\n");
}
int getSelNum() {
	int selNum = 0;
	printf("\n��ȣ�� �����ϼ��� : ");
	scanf_s("%d", &selNum);
	return selNum;
}
void inputAddress() {
	printf("�Է��Ͽ����ϴ�\n");
}
void searchAddress() {
	printf("�˻��Ͽ����ϴ�\n");
}
void updateAddress() {
	printf("�����Ͽ����ϴ�\n");
}
void deleteAddress() {
	printf("�����Ͽ����ϴ�\n");
}
void printAll() {
	printf("��ü �˻��Ͽ����ϴ�\n");
}
void exitProgram() {
	printf("�����Ͽ����ϴ�\n");
	
}
int processWork(int selNum) {
	switch (selNum) {
	case INPUT_ADDR: inputAddress(); break;
	case SEARCH_ADDR: searchAddress(); break;
	case UPDATE_ADDR: updateAddress(); break;
	case DELETE_ADDR: deleteAddress(); break;
	case PRINTALL_ADDR: printAll(); break;
	case EXIT: exitProgram(); return 0;
	default: printf("�� �� �Է��ϼ̽��ϴ�\n"); break;
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