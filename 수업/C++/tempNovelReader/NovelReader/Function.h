#pragma once
using namespace std;

#define GREEN    2
#define WHITE    7
#define BLUE     11
#define RED     12
#define YELLOW   14

void clear();
void printLine(bool state, char* str, int lineNum);
void color(unsigned short color);
void searchWord1();
void search();
void searchWord2(char word[100]);
