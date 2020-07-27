#include<stdio.h>
#include<string.h>
#include<windows.h>
int main()
{
	char s[] = "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz";
	while (1) {
		system("cls");
		char t = s[strlen(s)-1];
		for (int i = strlen(s)-1; i > 0; i--) {
			s[i] = s[i-1];
		}
		s[0] = t;
		printf("%s\n", s);
		Sleep(5);
	}
	return 0;
}