#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
void main()
{
	string str = "abc.def.hij";
	const char* ch = str.c_str();
	//cout << ch;
	char* st = new char; 
	strcpy(st, ch);
	char* token = strtok(st, ".");
	while (token!=NULL) {
		cout << token << " ";
		token = strtok(NULL, ".");
	}
}