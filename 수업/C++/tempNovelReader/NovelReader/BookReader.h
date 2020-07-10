#pragma once
#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include "Voca.h"
using namespace std;
#define LineLength 119
#define PageLine 25
class BookReader {
	vector<string> novelName;
	map<string, vector<string>> novelContent;
	map<string, vector<string>> novelInterpret;
	map<string, pair<string, int>> vocaMap;
	map<string, int> vocaExist;
	vector<Voca> voca;
public:
	void showMenu();
	int getSelmenu();
	void readNovelName();
	void readVocaTxt();
	void addVocaToTxt(char word[30], char mean[30]);

	// 1. function Read Novel
	void funcReadNovel();
	void readNovelContent(string nName);
	void showNovelName();
	int getSelNovel();
	void findWord();

	// 2. function Interpret Sentence
	void funcInterpretSentence();
	void readNovelInterpret(string nName);
	void writeNovelInterpret(string nName);

	// 3. function Voca Note
	void funcVocaNote();
	void showVocaMenu();
	int getSelVocaMenu();
	void showVocaContent(int sel);
	void editVocaScore(string type, char tword[30], int vScore);

	// 4.function Voca Test
	/*void funcVocaTest() {

	}*/

	// 5. function Voca Game
	/*void funcVocaGame() {

	}*/
};