/*
지하실에 포도주를 1000병 보관해 놓은 왕이 있었다.
왕은 자신의 50번째 생일을 맞이했을 때 이 포도주를 모두 개봉하여 세계 각지에서 오는 소님을 대접할
계획을 세우고 있다. 그날은 바로 내일이다.
그런데 이 왕의 나라와 경쟁을 벌이는 적국의 스파이가 지하실에 잠입해서 포도주에 강력한 독극물을
두입하다가 적발되었다.
다행히 스파이는 단 하나의 병에만 독약을 풀고 잡혔는데, 그는 특수한 주사바늘을 이용해서 병에 아무
런 표시가 나지 않게 주입을 했기 때문에 독이 섞인 포도주가 어느것인지는 알 도리가 없다.
이독은 효능이 매우 강해서 포도주병 1,000,000병 분량의 다른 액체와 이 독 한 방울을 섞어 놓더라도
그 액체를 단 한 방울만 마시면 사람을 즉사시키는 위력을 가지고 있다.
이 상황에서는 누군가 포도주를 직접 마시고 이상이 없는지를 확인하는 방법 말고는 독이 투입된
포도주병을 골라낼 방법은 없다.
하지만 이 독은 이미 한 방울이라도 술을 마신 사람에게는 작용하지 않는다.
그래서 어느 한 사람이 첫 번째 병에서 시작해서 1,000번째 병까지 조금씩 맛을 보도록 한 다음
과연 어느 병을 마시고 죽는지 확인하는 방법은 사용할 수 없다.
물론 왕은 1,000명의 사람을 동원해서 각자 1병의 포도주를 한 잔씩 마시게 한 다음 누가 죽는지 확인
하는 방법을 쓸 수도 있다.
하지만, 이것은 무고한 시민을 죽음에 이르게 할 수도 있는 방법이기 때문에 정치적인 이유로 타당성이
없다.
그리하여 왕은 감옥에 갇혀 있는 사형수를 동원하라는 명령을 내렸다.
사형수들에게 포도주를 마시게 해서 독약이 섞인 포도주를 찾아내라고 한 것이다.
그렇지만, 감옥에 갇힌 사형수는 모두 10명밖에 없다.
이 나라의 대신인 당신은 과연 왕의 명령대로 독이 섞인 포도주를 찾아낼 수 있을 것인가?
*/

#include<stdio.h>
#include<iostream>
#include<time.h>
#include <stdlib.h>
using namespace std;
int arr[1001] = {-1};
int havePoison(int s, int e){
	int sum = 0;
	for (int i = s; i <= e; i++) {
		sum += arr[i];
	}
	return sum;
}
void initWine(int s, int e) {
	for (int i = s; i <= e; i++) {
		arr[i] = 0;
	}
}
void bSearch(int s, int e, int m ) {
	static int cnt = 0;
	if (s == e) { cout << "find : " << cnt << "번 탐색 | 독극물 위치 : " << s << " " << endl;  cnt = 0; return; }
	if (havePoison(s, m)) {
		cnt++;
		cout << cnt << " " << s << " " << m << " " << endl;
		bSearch(s, m, (s + m) / 2);
	}
	else if (havePoison(m + 1, e)) {
		cnt++;
		cout << cnt << " " <<  m + 1 << " " << e << " " << endl;
		bSearch(m + 1, e, (m + 1 + e) / 2);
	}
}
int main() {
	srand((unsigned)time(NULL));
	int con;
	while (1) {
		printf("독극물을 찾겠습니까?(y=1|n=0) ");
		cin >> con;
		if (con == 0) { cout << "프로그램을 종료합니다" << endl; break; }
		int idx = rand() % 1000 + 1; arr[idx] = 1; cout << idx << endl;
		int s = 1, e = 1000;
		int m = (s + e) / 2;
		bSearch(s,e,m);
		initWine(1, 1000);
		cout << endl;
	}
	return 0;
}
//2. 학생 구조체를 작성합니다
//구조체는 이름, 나이, 키, 몸무게, 번호 로 이루어져있습니다
//학생 5명의 정보를 입력받고
//모두 출력하세요
//반드시 함수로 작성하고, 함수의 매개변수는 포인터를 통해 전달해야 합니다
//#include <iostream>
//#include <stdio.h>
//#define member 5
//
//typedef struct Student
//{
//    char name[10];
//    int age;
//    double height;
//    double weight;
//    int num;
//}std;
//
//std _std[member];
//int stdcnt = 0;
//
//void input(char* name, int* age, double* height, double* weight, int* num)
//{
//    std _std[member];
//    for (int i = 0; i < member; i++)
//    {
//        printf("학생 이름, 나이, 키, 몸무게, 번호를 입력해주세요 : ");
//        scanf_s("%s", _std[i].name, sizeof(_std[i].name));
//        scanf_s("%d", &_std[i].age);
//        scanf_s("%lf", &_std[i].height);
//        scanf_s("%lf", &_std[i].weight);
//        scanf_s("%d", &_std[i].num);
//        stdcnt++;
//    }
//    stdcnt--;
//    for (int j = 0; j < member; j++)
//    {
//        printf("%s, %d, %lf, %lf, %d", _std[j].name, _std[j].age,
//            _std[j].height, _std[j].weight, _std[j].num);
//    }
//}
//
//void main()
//{
//    char name[10];
//    int age;
//    double height;
//    double weight;
//    int num;
//    input(name, &age, &height, &weight, &num);
//}