#pragma once
#include "Function.h"
#include <iostream>
#include <tchar.h>
#include "Turboc.h"
using namespace std;

void clear() {
	int temp;
	while ((temp = getchar()) != EOF && temp != '\n') {}
}

void printLine(bool state, char* str, int lineNum) {
	gotoxy(0, lineNum);
	cout << (state == true ? str : "                                                                                      ");
}

void color(unsigned short color)
{
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hCon, color);
}

/*void searchWord1() {
	char word[100] = { 0 };
	char link[150] = "https://papago.naver.com/?sk=ko&tk=en&hn=0&st=";
	//char link[150] = "https://translate.google.com/#view=home&op=translate&sl=en&tl=ko&text=";
	cout << "영어로 번역할 단어를 입력하세요 : ";
	cin >> word;
	strcat(link, word);
	ShellExecute(NULL, NULL, _T("C:\\Program Files (x86)\\Google\\Chrome\\Application\\chrome.exe"),
		link, NULL, SW_HIDE);
}

void search() {
	while (true) {
		int sel;
		char word[100];
		cout << "1. ko -> en" << endl;
		cout << "2. en -> kr" << endl;
		cout << "select : ";
		cin >> sel;
		if (sel == 1) searchWord1();
		else if (sel == 2) searchWord2(word);
		cout << endl;
	}
}*/

void searchWord2(char word[100]) {
	char link[150] = "https://papago.naver.com/?sk=en&tk=ko&hn=0&st=";
	strcat(link, word);
	ShellExecute(NULL, NULL, _T("C:\\Program Files (x86)\\Google\\Chrome\\Application\\chrome.exe"),
		link, NULL, SW_HIDE);
}