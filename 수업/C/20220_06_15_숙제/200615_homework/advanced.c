#include<stdio.h>
#include<math.h>
//1. �̱� �ε����� 1627�⿡ ���� ����ư ����
//�״����� �����ڵ鿡�� �ܵ� 24�޷��� �ȾҴٰ� �մϴ�.
//���� �����ϸ� �氪�� �� �� ������,
//�� ���� ���ݱ��� ���࿡ �־�ΰ�
//8 % �� ���ڸ� ������ �޾Ҵٸ� ������ ��û�� �ݾ���
//�Ǿ� ���� �Ŷ�� �մϴ�.
//2010���� �������� �� ���� ��ġ�� �󸶳� �Ǵ���
//����ϴ� ���α׷��� �ۼ��ϼ���.
//������ 1���� ���������� 8 % �� ���ݿ� ������ �Ǿ
//�� �ݾ��� �ٽ� ������ �Ǵ� ���� ���մϴ�.
// ���� ->  �̷���ġ = ���簡ġ * (1+������)^���ڱⰣ
int problem1() {
	double money = 24; 
	double a = 1;
	double r = (1 + 0.08);
	
	//������ 1���� ���������� 8 % �� ���ݿ� ������ �Ǿ
	//�� �ݾ��� �ٽ� ������ �Ǵ� ���� ���մϴ�.
	/*printf("%d�� %.2lf\n", 1627, money);
	for (int i = 1628; i <= 2010; i++) {
		money = money + money * 0.08;
		printf("%d�� %.2lf\n", i, money);
	}
	printf("money : %.2lf\n", money);*/
	
	// ���� ->  �̷���ġ = ���簡ġ * (1+������)^���ڱⰣ
	/*for (int i = 0; i < 2010-1627; i++) {
		a = a * r;
	}
	money = money * a;
	printf("money : %.2lf\n", money);*/

	printf("money : %.2lf\n", money * pow(r, 2010 - 1627));
}

//2. 5�� �Է��ϸ�
//o
//*o
//**o
//***o
//****o
//�̷��� ����ϼ���.
int problem2() {
	printf("������ �Է��ϼ��� : ");
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
		printf("���� : ");
		scanf_s("%d", &select);
		if (select == 0) break;
		else if (select == 1) problem1();
		else if (select == 2) problem2();
	}
}