#pragma once
#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include "Voca.h"
using namespace std;
#define NovelPath "./Novel/"
#define InterpretPath "./Interpret/"
#define LineLength 119
#define PageLine 25
class BookReader {
	// �ɽ��ؼ� ���� mainȭ��
	vector<string> mainScreen;
	// ��� ����
	vector<string> novelName;
	vector<string> interpretName;
	map<string, vector<string>> novelContent; 
	map<string, vector<string>> novelInterpret;
	map<string, pair<string, int>> vocaMap; // ���� ���°� ����...
	map<string, int> vocaExist; 
	vector<Voca> voca;
	int nowPage = 0;
public:
	// �ɽ��ؼ� ���� mainȭ�� ���� �Լ�
	void showMainScreen();
	// ��� �Լ�
	void showMenu();
	char getSelmenu();
	void readNovelName();
	void readVocaTxt();
	void addVocaToTxt(char word[30], char mean[30]);

	// 1. function Read Novel
	void funcReadNovel();
	void readNovelContent(string nName);
	void showNovelName();
	char getSelNovel();
	void findWord();

	// 2. function Interpret Sentence
	void funcInterpretSentence();
	void readNovelInterpret(string nName);
	void writeNovelInterpret(string nName);

	// 3. function Voca Note
	void funcVocaNote();
	void showVocaMenu();
	char getSelVocaMenu();
	void showVocaContent(char sel);
	void editVocaScore(string type, char tword[30], int vScore);
	void writeVocaTxt();

	// 4.function Voca Test
	void funcVocaTest() ;

};