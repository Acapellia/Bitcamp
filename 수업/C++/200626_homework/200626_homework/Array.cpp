#include<iostream>
#include<cstring>
#include<string>
using namespace std;
//1. 길이가 5인 int형 배열을 선언해서 5개의 정수를 입력받습니다.
//이중 최대값, 최소값, 총합, 평균을 구하세요.
void problem1(){
	int arr[5] = { 0 };
	int max = 0, min = 9999999, sum = 0;
	double avg = 0.0;
	for (int i = 0; i < 5; i++) {
		cout << "정수를 입력하세요 : ";
		cin >> arr[i];
		sum += arr[i];
		if (max < arr[i]) max = arr[i];
		if (min > arr[i]) min = arr[i];
	}
	avg = double(sum) / 5;
	cout << "최대값 : " << max << endl;
	cout << "최소값 : " << min << endl;
	cout << "총합 : " << sum << endl;
	cout << "평균 : " << avg << endl;
}
//2. char형 1차원배열을 선언 후 "Good Morning"로 초기화 하세요.
//그리고 문장을 출력하세요.
void problem2() {
	char str[] = "Good Morning";
	cout << "string : " << str << endl;
}
//3. 영단어를 입력받고 영단어를 역순으로 뒤집으세요.
//단, 널값은 그대로여야 합니다.
//역순으로 전환한 값을 출력하세요.
void problem3() {
	char str[20] = { 0 }, rvs[20] = {0};
	cout << "영단어를 입력해주세요 : ";
	cin >> str;
	int len = strlen(str);
	for (int i = 0; i < len; i++) {
		rvs[len-i-1] = str[i];
	}
	cout << "뒤집어진 영단어는 : "<< rvs << endl;
}
//4. 길이가 5인 int형 배열 arr을 선언하고
//1, 2, 3, 4, 5로 초기화한다.
//마지막 요소를 가리키는 ptr을 선언하고
//ptr을 감소하는 연산으로 배열의 요소를 모두 더하여 결과를
//출력한다.
void problem4() {
	int arr[5] = { 1,2,3,4,5 };
	int* ptr = &arr[4];
	int sum = 0;
	for (int i = 0; i < 5; i++) {
		sum += (*ptr--);
	}
	cout << "sum : " << sum << endl;
}
//5. 길이가 6인 배열 arr 1, 2, 3, 4, 5, 6 으로 초기화한 다음
//배열에 저장된 값의 순서를 6, 5, 4, 3, 2, 1로 변경한다.
//배열의 앞과 뒤를 가리키는 포인터 변수 2개를 선언해서
//이를 활용하여 저장된 값의 순서를 바꿔야 한다.
void problem5() {
	int arr[6] = { 1,2,3,4,5,6 };
	int* ptr1 = arr;
	int* ptr2 = &arr[5];
	for (int i = 0; i < 3; i++) {
		int temp = (*ptr1);
		*ptr1 = *ptr2;
		*ptr2 = temp;
		*ptr1++; *ptr2--;
	}
	for (int i = 0; i < 6; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}
//6. 숫자를 포함한 문자열을 입력받아서 그 안에 존재하는 숫자의 총합을
//구하세요.
//예를 들어 q1df3kf9lj3의 경우는
//1 + 3 + 9 + 3을 출력해야 합니다.
void problem6() {
	char str[20] = { 0 };
	int num[20] = { 0 };
	int idx = 0,sum=0;
	cout << "숫자를 포함한 문자열을 입력하세요 : ";
	cin >> str;
	for (int i = 0; i < strlen(str); i++) {
		if ('0' <= str[i] && str[i] <= '9') {
			num[idx++] = str[i] - '0';
			sum += (str[i] - '0');
		}
	}
	for (int i = 0; i < idx; i++) {
		cout << num[i];
		if (i < idx-1) cout << " + ";
	}
	cout << " = " << sum << endl;
}
//7. 20byte char 배열 3개를 만듭니다.
//배열에 문자열을 두개를 입력받습니다.
//나머지배열에 두개의 문자열을 연결하여 붙여넣습니다.
//즉 korea, student를 입력받았다면
//세번째 배열에는 koreastudent가 저장되어 출력하여야 합니다.
void problem7() {
	char str1[20] = {0}, str2[20] = { 0 }, str3[20] = { 0 };
	int idx = 0;
	cout << "문자열1을 입력하세요 : ";
	cin >> str1;
	cout << "문자열2를 입력하세요 : ";
	cin >> str2;
	for (int i = 0; i < strlen(str1); i++) {
		str3[idx++] = str1[i];
	}
	for (int i = 0; i < strlen(str2); i++) {
		str3[idx++] = str2[i];
	}
	cout << str3 << endl;
}
//8. 사용자로부터 이름과 나이를 다음의 형식에 맞춰서 하나의 문자열로
//입력받습니다.
//홍길동 32
//임꺽정 17
//그래서 이름과 나이 사이에는 공백이 삽입되어야 합니다.
//이름과 나이가 같은지 다른지 판단하여 출력하는 프로그램을 작성하세요.
void problem8() {
	char str1[30] = { 0 }, str2[30] = { 0 };
	getchar();
	cout << "1번째 사람 : ";	cin.getline(str1, 30);
	cout << "2번째 사람 : ";	cin.getline(str2, 30);
	cout << "------------------------------" << endl;
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	int same[2] = { 0 }, idx = 0;

	cout << "----------<비교>----------" << endl;
	for (int i = 0,j=0; i < len1 && j <len2;) {
		cout << "str1 : " << str1[i] << " " << "str2 : " << str2[j] << endl;
		if (str1[i] != ' ') { i++; }
		if (str2[j] != ' ') { j++; }
		if (str1[i] == ' ' && str2[j] == ' ') { idx++; i++; j++; }
		if (str1[i] != str2[j]) { same[idx] = 1; }
	}
	cout << "--------------------------" << endl;
	cout << "----------<결과>----------" << endl;
	if(same[0] == 0 && same[1] == 0) cout << "이름과 나이가 같습니다" << endl;
	else if (same[0] == 0) cout << "이름이 같습니다" << endl;
	else if (same[1] == 0) cout << "나이가 같습니다" << endl;
	else { cout << "이름과 나이가 모두 다릅니다" << endl; }
	cout << "--------------------------" << endl;
}
int main()
{
	while (1) {
		int sel;
		cout << "원하는 과제를 입력하세요 : ";
		cin >> sel;
		if (sel == 0) { cout << "end!!" << endl; break; }
		else if (sel == 1) { problem1(); }
		else if (sel == 2) { problem2(); }
		else if (sel == 3) { problem3(); }
		else if (sel == 4) { problem4(); }
		else if (sel == 5) { problem5(); }
		else if (sel == 6) { problem6(); }
		else if (sel == 7) { problem7(); }
		else if (sel == 8) { problem8(); }
		cout << endl;
	}
	return 0;
}