/*
���Ͻǿ� �����ָ� 1000�� ������ ���� ���� �־���.
���� �ڽ��� 50��° ������ �������� �� �� �����ָ� ��� �����Ͽ� ���� �������� ���� �Ҵ��� ������
��ȹ�� ����� �ִ�. �׳��� �ٷ� �����̴�.
�׷��� �� ���� ����� ������ ���̴� ������ �����̰� ���Ͻǿ� �����ؼ� �����ֿ� ������ ���ع���
�����ϴٰ� ���ߵǾ���.
������ �����̴� �� �ϳ��� ������ ������ Ǯ�� �����µ�, �״� Ư���� �ֻ�ٴ��� �̿��ؼ� ���� �ƹ�
�� ǥ�ð� ���� �ʰ� ������ �߱� ������ ���� ���� �����ְ� ����������� �� ������ ����.
�̵��� ȿ���� �ſ� ���ؼ� �����ֺ� 1,000,000�� �з��� �ٸ� ��ü�� �� �� �� ����� ���� ������
�� ��ü�� �� �� ��︸ ���ø� ����� ����Ű�� ������ ������ �ִ�.
�� ��Ȳ������ ������ �����ָ� ���� ���ð� �̻��� �������� Ȯ���ϴ� ��� ����� ���� ���Ե�
�����ֺ��� ��� ����� ����.
������ �� ���� �̹� �� ����̶� ���� ���� ������Դ� �ۿ����� �ʴ´�.
�׷��� ��� �� ����� ù ��° ������ �����ؼ� 1,000��° ������ ���ݾ� ���� ������ �� ����
���� ��� ���� ���ð� �״��� Ȯ���ϴ� ����� ����� �� ����.
���� ���� 1,000���� ����� �����ؼ� ���� 1���� �����ָ� �� �ܾ� ���ð� �� ���� ���� �״��� Ȯ��
�ϴ� ����� �� ���� �ִ�.
������, �̰��� ������ �ù��� ������ �̸��� �� ���� �ִ� ����̱� ������ ��ġ���� ������ Ÿ�缺��
����.
�׸��Ͽ� ���� ������ ���� �ִ� �������� �����϶�� ����� ���ȴ�.
�������鿡�� �����ָ� ���ð� �ؼ� ������ ���� �����ָ� ã�Ƴ���� �� ���̴�.
�׷�����, ������ ���� �������� ��� 10��ۿ� ����.
�� ������ ����� ����� ���� ���� ��ɴ�� ���� ���� �����ָ� ã�Ƴ� �� ���� ���ΰ�?
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
	if (s == e) { cout << "find : " << cnt << "�� Ž�� | ���ع� ��ġ : " << s << " " << endl;  cnt = 0; return; }
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
		printf("���ع��� ã�ڽ��ϱ�?(y=1|n=0) ");
		cin >> con;
		if (con == 0) { cout << "���α׷��� �����մϴ�" << endl; break; }
		int idx = rand() % 1000 + 1; arr[idx] = 1; cout << idx << endl;
		int s = 1, e = 1000;
		int m = (s + e) / 2;
		bSearch(s,e,m);
		initWine(1, 1000);
		cout << endl;
	}
	return 0;
}
//2. �л� ����ü�� �ۼ��մϴ�
//����ü�� �̸�, ����, Ű, ������, ��ȣ �� �̷�����ֽ��ϴ�
//�л� 5���� ������ �Է¹ް�
//��� ����ϼ���
//�ݵ�� �Լ��� �ۼ��ϰ�, �Լ��� �Ű������� �����͸� ���� �����ؾ� �մϴ�
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
//        printf("�л� �̸�, ����, Ű, ������, ��ȣ�� �Է����ּ��� : ");
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