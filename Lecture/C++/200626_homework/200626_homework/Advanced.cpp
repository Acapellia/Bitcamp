#include<iostream>
#include<cstring>
using namespace std;
//1. strcmp, strncmp, 직접 문자 하나하나 비교해서 검사하는 함수제작
//문자열 2개 입력받고 문자열이 같은지 다른지 검사하는 프로그램 작성하세요.
int str_cmp(char str1[], char str2[]) {
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	if (len1 != len2) return 0;
	int len = len1 > len2 ? len1 : len2; // 같다는것이 보장되므로 아무거나 상관없음
	for (int i = 0; i < len; i++) {
		if (str1[i] != str2[i]) return 0;
	}
	return 1;
}
void problem1() {
	char str1[20],str2[20];
	cout << "문자열 2개를 입력하세요 : ";
	cin >> str1 >> str2;
	if (str_cmp(str1, str2)) { cout << "2개의 문자열은 같습니다." << endl; }
	else { cout << "2개의 문자열은 다릅니다." << endl; }
}
//cin, cout 사용할 것

//2. 사용자로부터 계속 정수를 입력받는다.
//- 1이 되면 출력한다.
//default로 5개를 동적할당하고
//5개를 넘어가면 + 5씩 동적할당을 증가시킨다.
//5 -> 10 -> 15
//반드시 new 연산자를 사용할 것
#define SIZE 5
void problem2() {
	int* num = new int[SIZE]();
	int idx = 0;
	int size = SIZE;
	int tNum;
	while (true) {
		cout << "정수를 입력하세요 : ";
		cin >> tNum;
		if (tNum == -1) break;
		num[idx++] = tNum;
		if (idx >= size) {
			size += SIZE;
			int* temp = new int[size]();
			cout << "size가 " << size << "로 늘어났습니다." << endl;
			for (int i = 0; i < size - SIZE; i++) {
				temp[i] = num[i];
			}
			delete[] num;
			num = temp;
		}
	}
	for (int i = 0; i < idx; i++)
		cout << num[i] << " ";
	cout << endl;
	delete[] num;
}
//3. TelInfo를 new delete를 사용하여 수정할 것
//void problem3() {}
//4. 3번문제를 구조체에서 클래스로 전환할 것
//void problem4() {}
int main()
{
	while (1) {
		int sel;
		cout << "원하는 과제를 입력하세요 : ";
		cin >> sel;
		if (sel == 0) { cout << "end!!" << endl; break; }
		else if (sel == 1) { problem1(); }
		else if (sel == 2) { problem2(); }

		cout << endl;
	}
	return 0;
}