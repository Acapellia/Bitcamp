#include<stdio.h>
#include<string.h> // ���ڿ�
#include<math.h>
#include<stdlib.h> // ���� ��ƿ��Ƽ
#include<conio.h> // �ֿܼ� �����
#include<time.h>
#include<Windows.h>
typedef struct Car {
	int number;
	double price;
	time_t in, out;
}car;
// car�� ������ ����(����) �ؾ���
car list[20];
int seq = 0;
int hasEmpty(void) {
	for (int i = 0; i < 20; i++) {
		if (list[i].number == 0) { return i; }
	}
	return -1;
}
int goHome() {
	time_t now = time(NULL);
	struct tm sn;
	//sn = localtime(&now);
	//printf("%d�� %d�� %d��\n", (sn->tm_hour) % 12, sn->tm_min, sn->tm_sec);
	localtime_s(&sn,&now);
	printf("%d�� %d�� %d��\n", (sn.tm_hour) % 12, sn.tm_min, sn.tm_sec);
	
	if (sn.tm_hour >= 18)
		return 0; // ��ٽð��̴�...
	else {
		printf("���� ��ٽð��� �ƴϴ�...\n");
		return 1;
	}
}
/*void main()
{
	double total_money = 0;
	// �������Դϴ�... ���� ������ �������̴ϴ�.
	printf("�������Դϴ�..... ���� ������ �������Դϴ�.\n");
	// ���� ������ �ִ�
	do {
		printf("[1] IN [2] out > ");
		char key = getchar(); getchar();
		if(key == '1'){
			printf("���� ������ �ִ�...\n");
			// ������ �� �� ������ ������ ������ �� �ִ�...
			int idx = hasEmpty();
			if (idx != -1) {
				printf("������ �� �ִ�...\n");
				printf("���� ��ȣ��?(4�ڸ�) >" );
				Car car;
				scanf_s("%d",&car.number);
				car.price = 1000.0;
				car.in = time(NULL);
				car.out = 0;
				list[idx] = car;
			}
			else {
				printf("������ �� ����... ��������!!\n");
			}
		}
		else if (key == '2') {
			// ���� ������ �ִ�.
			printf("���� ������ �ִ�...\n");
			printf("���� ��ȣ��?(4�ڸ�) >");
			int carnum;
			scanf_s("%d", &carnum);
			for(int i=0;i<20;i++){
				if (list[i].number == carnum) {
					// ���
					printf("��� ������!\n");
					tm in_time,out_time;
					time_t now = time(NULL);
					localtime_s(&in_time, &list[i].in);
					localtime_s(&out_time, &now);
					double money = list[i].price;
					money = money + (out_time.tm_hour - in_time.tm_hour*1000.0);
					total_money += money;
					printf("����� %ld �� �Դϴ�~~~\n");
					// �������� ���ڸ� ����
					printf("���� ������ ���ڸ��� �����...\n");
					list[i].number = 0; list[i].price = 0; list[i].in = 0; list[i].out = 0;
					break;
				}
			}
		}		
	} while (goHome());
	// ������ ���Թ� ��װ� ���� ��
	printf("��� �ð��� �Ǿ ������ ���Թ��� ��װ� ���� ����...\n");
	printf("���� %ld ���� ������...\n", total_money);

}*/