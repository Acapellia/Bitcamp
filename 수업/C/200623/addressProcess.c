#include "addressDefine.h"
#include "addressProcess.h"

extern int g_addrCnt;
extern Address g_Address[ADDR_LEN];

// View
void showMenu() {
	puts("1. Insert");
	puts("2. printAllAddress");
	puts("3. Exit");
	printf("\n");
}

int selMenu() {
	int num = 0;
	printf("Select Number : ");
	num = getchar() - '0'; getchar();
	return num;
}

// Controller
void insertAddress() {
	if (g_addrCnt == ADDR_LEN) {
		printf("Memory is Full!!\n");
		return;
	}
	char name[20];
	char address[30];
	int age = 0;
	printf("\n-------------[Insert]-------------\n\n");
	printf("이름을 입력하세요 : ");
	// fgets의 마지막 인자에 stdin을 주면 키보드로 부터 입력받고 파일포인터를 주면 파일을 읽는다.
	fgets(name, sizeof(name) - 1, stdin);
	name[strlen(name) - 1] = 0; // '\0', NULL
	printf("주소를 입력하세요 : ");
	fgets(address, sizeof(address) - 1, stdin);
	address[strlen(address) - 1] = 0;
	printf("나이를 입력하세요 : ");
	scanf_s("%d", &age);	getchar();
	strncpy(g_Address[g_addrCnt].name, name, sizeof(name));
	strncpy(g_Address[g_addrCnt].address, address, sizeof(address));
	g_Address[g_addrCnt].age = age;
	g_addrCnt++;
}

void printAllAddress() {
	for (int i = 0; i < g_addrCnt; i++) {
		printf("\n-------------[Print]-------------\n\n");
		printf("이름 : %s\n", g_Address[i].name);
		printf("주소 : %s\n", g_Address[i].address);
		printf("나이 : %d\n", g_Address[i].age);
	}
}

int processAddress(int sel) {
	int ret = 1;
	if (sel == INSERT) insertAddress();
	else if (sel == PRINT) printAllAddress();
	else if (sel == EXIT) {
		printf("\n-------------[Exit]-------------\n");
		saveAllAddress();
		ret = 0;
	}
	else printf("Invalid Value\n");
	printf("\n");
	return ret;
}

// Model
void saveAllAddress() {
	FILE* fp = NULL;
	fopen_s(&fp, "address.bin", "wb");
	fwrite(&g_addrCnt, sizeof(int), 1, fp);
	fwrite(g_Address, sizeof(Address), g_addrCnt, fp);
	fclose(fp);
}

void loadAllAddress() {
	FILE* fp = NULL;
	errno_t err = 0;
	g_addrCnt = 0;
	err = fopen_s(&fp, "address.bin", "rb");
	if (err == 0) {
		fread(&g_addrCnt, sizeof(int), 1, fp);
		fread(g_Address, sizeof(Address), g_addrCnt, fp);
		fclose(fp);
	}
	else {
		printf("파일 로드 실패\n");
	}
}

