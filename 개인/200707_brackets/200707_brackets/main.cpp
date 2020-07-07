#include<stdio.h>
#include<string.h>
int main()
{
	int nc=0,n;
	//cout << "반복할 횟수를 입력해주세요 : ";
	scanf("%d", &n);
	while (nc++ < n) {
		char bracket[51] = {0};
		char temp[51] = { 0 };
		int idx = -1, state = 0;
		//cout << "괄호 문자열을 입력해주세요 : ";
		scanf("%s", bracket);
		for (int i = 0; i < strlen(bracket); i++) {
			if (bracket[i] == '(') {
				temp[++idx] = '(';
			}
			else {
				if (idx < 0) { state = 1; break; }
				temp[idx--] = 0;
			}
		}
		if (idx >= 0) state = 1;
		if (state == 0) { printf("YES\n"); }
		else { printf("NO\n"); }
	}
	return 0;
}