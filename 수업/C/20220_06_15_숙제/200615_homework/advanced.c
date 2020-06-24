#include<stdio.h>
#include<math.h>
//1. 미국 인디언들은 1627년에 뉴욕 맨하튼 섬을
//네덜란드 이주자들에게 단돈 24달러에 팔았다고 합니다.
//지금 생각하면 헐값에 판 것 같지만,
//이 돈을 지금까지 은행에 넣어두고
//8 % 의 이자를 복리로 받았다면 지금쯤 엄청난 금액이
//되어 있을 거라고 합니다.
//2010년을 기준으로 이 돈의 가치가 얼마나 되는지
//계산하는 프로그램을 작성하세요.
//복리란 1년이 지날때마다 8 % 가 원금에 포함이 되어서
//그 금액이 다시 원금이 되는 것을 말합니다.
// 복리 ->  미래가치 = 현재가치 * (1+연이율)^투자기간
int problem1() {
	double money = 24; 
	double a = 1;
	double r = (1 + 0.08);
	
	//복리란 1년이 지날때마다 8 % 가 원금에 포함이 되어서
	//그 금액이 다시 원금이 되는 것을 말합니다.
	/*printf("%d년 %.2lf\n", 1627, money);
	for (int i = 1628; i <= 2010; i++) {
		money = money + money * 0.08;
		printf("%d년 %.2lf\n", i, money);
	}
	printf("money : %.2lf\n", money);*/
	
	// 복리 ->  미래가치 = 현재가치 * (1+연이율)^투자기간
	/*for (int i = 0; i < 2010-1627; i++) {
		a = a * r;
	}
	money = money * a;
	printf("money : %.2lf\n", money);*/

	printf("money : %.2lf\n", money * pow(r, 2010 - 1627));
}

//2. 5를 입력하면
//o
//*o
//**o
//***o
//****o
//이렇게 출력하세요.
int problem2() {
	printf("정수를 입력하세요 : ");
	int n; scanf("%d", &n);
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= i; j++) {
			if (j == i) printf("o");
			else printf("*");
		}printf("\n");
	}
}
void main()
{
	int select;
	while (1) {
		printf("선택 : ");
		scanf_s("%d", &select);
		if (select == 0) break;
		else if (select == 1) problem1();
		else if (select == 2) problem2();
	}
}