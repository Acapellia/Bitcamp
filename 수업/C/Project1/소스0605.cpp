#include<stdio.h>
#include<string.h> // 문자열
#include<math.h>
#include<stdlib.h> // 여러 유틸리티
#include<conio.h> // 콘솔용 입출력
#include<time.h>
#include<Windows.h>
typedef struct Car {
	int number;
	double price;
	time_t in, out;
}car;
// car를 여러개 저장(주차) 해야함
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
	//printf("%d시 %d분 %d초\n", (sn->tm_hour) % 12, sn->tm_min, sn->tm_sec);
	localtime_s(&sn,&now);
	printf("%d시 %d분 %d초\n", (sn.tm_hour) % 12, sn.tm_min, sn.tm_sec);
	
	if (sn.tm_hour >= 18)
		return 0; // 퇴근시간이다...
	else {
		printf("아직 퇴근시간이 아니다...\n");
		return 1;
	}
}
/*void main()
{
	double total_money = 0;
	// 주차장입니다... 저는 주차장 관리인이니다.
	printf("주차장입니다..... 저는 주차장 관리자입니다.\n");
	// 차가 들어오고 있다
	do {
		printf("[1] IN [2] out > ");
		char key = getchar(); getchar();
		if(key == '1'){
			printf("차가 들어오고 있다...\n");
			// 주자장 내 빈 공간이 있으면 주자할 수 있다...
			int idx = hasEmpty();
			if (idx != -1) {
				printf("주차할 수 있다...\n");
				printf("차의 번호는?(4자리) >" );
				Car car;
				scanf_s("%d",&car.number);
				car.price = 1000.0;
				car.in = time(NULL);
				car.out = 0;
				list[idx] = car;
			}
			else {
				printf("주차할 수 없다... 나가세요!!\n");
			}
		}
		else if (key == '2') {
			// 차가 나가고 있다.
			printf("차가 나가고 있다...\n");
			printf("차의 번호는?(4자리) >");
			int carnum;
			scanf_s("%d", &carnum);
			for(int i=0;i<20;i++){
				if (list[i].number == carnum) {
					// 요금
					printf("요금 내세요!\n");
					tm in_time,out_time;
					time_t now = time(NULL);
					localtime_s(&in_time, &list[i].in);
					localtime_s(&out_time, &now);
					double money = list[i].price;
					money = money + (out_time.tm_hour - in_time.tm_hour*1000.0);
					total_money += money;
					printf("요금은 %ld 원 입니다~~~\n");
					// 나갔으니 빈자리 생김
					printf("차가 나가서 빈자리가 생겼다...\n");
					list[i].number = 0; list[i].price = 0; list[i].in = 0; list[i].out = 0;
					break;
				}
			}
		}		
	} while (goHome());
	// 주차장 출입문 잠그고 집에 감
	printf("퇴근 시간이 되어서 주차장 출입문을 잠그고 집에 간다...\n");
	printf("오늘 %ld 원을 벌었다...\n", total_money);

}*/