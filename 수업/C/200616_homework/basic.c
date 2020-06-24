#include<stdio.h>
//1. do~while문을 이용해서 1부터 100까지 출력하세요
//for문을 이용해서 1부터 100까지 출력하세요
void problem1() {
	int num = 1;
	do {
		printf("%d ", num);
	} while (++num<=100);
	printf("\n");
	for (int i = 1; i <= 100; i++) printf("%d ", i);
}
//2. do~while문을 이용해서 10부터 20까지 출력하세요
//for문을 이용해서 10부터 20까지 출력하세요
void problem2() {
	int num = 10;
	do {
		printf("%d ", num);
	} while (++num <= 20);
	printf("\n");
	for (int i = 10; i <= 20; i++) printf("%d ", i);
}
//3. do~while문을 이용해서 1부터 10까지 합을 출력하세요
//for문을 이용해서 1부터 10까지 합을 출력하세요
void problem3() {
	int num = 1;
	int sum = 0;
	do {
		sum += num;
	} while (++num <= 10);
	printf("sum : %d\n",sum);
	sum = 0;
	for (int i = 1; i <= 10; i++) sum += i;
	printf("sum : %d ", sum);
}
//4. do~while문을 이용해서 1부터 10까지 중에 짝수만 출력하세요
//do~while문내에 조건문을 넣어주면 됨
//짝수 조건 if (num % 2 == 0)
void problem4() {
	int num = 1;
	do {
		if(num%2==0)	printf("%d ", num);
	} while (++num <= 10);
	printf("\n");

	for (int i = 1; i <= 10; i++) {
		if (i % 2 == 0) printf("%d ", i);
	}
}
//5. do~while문을 이용해서 양의 정수를 입력받고 그 수만큼 "감사합니다"를 출력하세요
//for문을 이용해서 양의 정수를 입력받고 그 수만큼 "감사합니다"를 출력하세요
void problem5() {
	int num; 
	int n=0;
	printf("숫자를 입력하세요 : ");  scanf("%d", &num);
	do {
		printf("감사합니다\n");
	} while (++n<num);
	printf("\n");

	for (int i = 1; i <=num ; i++) {
		printf("감사합니다\n");
	}
}
//6. do~while문을 이용해서 양의 정수 입력받고 그 수만큼 3의 배수 출력하세요
//예를 들어 5를 입력받으면 3 6 9 12 15를 출력하면 됩니다
//for문을 이용해서 ~
void problem6() {
	int num;
	int n = 1;
	printf("숫자를 입력하세요 : ");  scanf("%d", &num);
	do {
		printf("%d ",3*n);
	} while (++n <= num);
	printf("\n");

	for (int i = 1; i <= num; i++) {
		printf("%d ",3*i);
	}
}
//7. do~while문을 이용해서, for문을 이용해서 각각 2가지로 풀어보세요
//입력받은 숫자의 구구단을 출력하세요
//예를 들어 3을 입력하면
//3 x 1 = 3
//3 x 2 = 6
//...
//3 x 9 = 27
void problem7() {
	int num; 
	int m = 1;
	printf("구구단 숫자 입력 : ");  scanf("%d", &num);
	do {
		printf("%d * %d = %d\n",num,m,num*m);
	} while (++m < 10);
	printf("\n");

	for (int i = 1; i < 10; i++) {
		printf("%d * %d = %d\n", num, i, num * i);
	}
}
//8. do~while문을 이용해서, for문을 이용해서 2가지로 풀어보세요
//사용자로부터 정수를 입력받습니다.
//입력 받은 값을 계속 더합니다
//사용자가 0을 입력하면 합을 출력합니다
//그리고 프로그램을 종료합니다.
void problem8() {
	int num=0;
	int sum = 0;
	do {
		printf("숫자를 입력하세요 : ");
		scanf("%d", &num);
		sum += num;
	} while (num!=0);
	printf("%d\n",sum);
	
	sum = 0;
	for (int i = 1; ; i++) {
		printf("숫자를 입력하세요 : ");
		scanf("%d", &num);
		if (num == 0) break;
		sum += num;
	}
	printf("%d\n", sum);
}
//9. 0부터 1씩 증가한 값을 누적하여 더합니다.
//모두 더한값이 1000이 넘을 때 의 총합과
//더한 값을 구하세요.
void problem9() {
	int sum = 0;
	int n = 0;
	while (1) {
		sum += n;
		if (sum > 1000) break;
		n++;
	}
	printf("총합 : %d 더한 값 : %d\n", sum, n);
}
//10. int multiplication[8][9] 배열을 생성하세요
//그리고 구구단의 2 ~9단까지의 결과값을
//배열에 저장하세요
//그리고 출력하세요
void problem10() {
	int multiplication[8][9];
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 9;j++) {
			multiplication[i][j] = (i + 2) * (j + 1);
		}
	}
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 9; j++) {
			printf("%d * %d = %d\n",i+2,j+1,multiplication[i][j]);
		}printf("\n");
	}
	printf("\n");
}
int main() 
{
	while (1) {
		printf("실행할 과제를 입력하세요 : ");
		int select; scanf("%d", &select);
		if (select == 0) break;
		else if (select == 1) problem1();
		else if (select == 2) problem2();
		else if (select == 3) problem3();
		else if (select == 4) problem4();
		else if (select == 5) problem5();
		else if (select == 6) problem6();
		else if (select == 7) problem7();
		else if (select == 8) problem8();
		else if (select == 9) problem9();
		else if (select == 10) problem10();
		printf("\n\n");

	}
}