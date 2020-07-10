#pragma once
#include "BookReader.h"
#include <cstdio>
#include <fstream>
#include <string>
#include <sstream>
#include <windows.h>
#include "Turboc.h"
#include "Function.h"
#include "Voca.h"
using namespace std;

void BookReader::showMenu() {
	cout << "----------Menu----------" << endl;
	cout << "1. Read Novel" << endl;
	cout << "2. Interpreting a sentence" << endl;
	cout << "3. Open Vocabulary note" << endl;
	cout << "4. Words Test" << endl;
	cout << "5. Game" << endl;
	cout << "0. Exit" << endl;
	cout << "------------------------" << endl;
}

void BookReader::readNovelName() {
	ifstream in("Novel.txt");
	while (!in.eof()) {
		char name[100] = { 0 };
		in.getline(name, 100);
		novelName.push_back(name);
	}
}

void BookReader::readVocaTxt() {
	FILE* note = fopen("Voca.txt", "rt");
	while (!feof(note)) {
		char word[30] = { 0 }, mean[30] = { 0 };
		int score = 0;
		fscanf(note, "%s", word);
		fscanf(note, "%s", mean);
		fscanf(note, "%d", &score);
		voca.push_back(Voca(word, mean, score));
		vocaMap.insert({ word, make_pair(mean, score) });
		vocaMap.insert({ mean, make_pair(word, -1) });
		vocaExist.insert({ word, 1 });
	}
}

void BookReader::addVocaToTxt(char word[30], char mean[30]) {
	FILE* out = fopen("Voca.txt", "at");
	fprintf(out, "\n%s %s %d", word, mean, 0);
	fclose(out);
}

// 1. function Read Novel
void BookReader::readNovelContent(string nName) {
	ifstream in(nName);
	vector<string> nContent;
	string content;
	while (!in.eof()) {
		string temp;
		getline(in, temp); temp += " ";
		content += temp;
		while(content.size()>=LineLength) {
			nContent.push_back(content.substr(0, LineLength));
			content = content.substr(LineLength, content.size()-1);
		}	
		if (content.size() > 2 && content[content.size() - 2] == '.') {
			nContent.push_back(content);
			content.clear();
		}
		else if (temp.size() == 1) {
			nContent.push_back(content);
			content.clear();
		}
	}
	nContent.push_back("\n-end-\n");
	novelContent.insert({ nName, nContent });
	in.close();
}

void BookReader::funcReadNovel() {
	showNovelName();
	int novelNum = getSelNovel();
	string nName = novelName[novelNum - 1];
	int nowLine = 0;
	int state = 0;
	readNovelContent(nName);
	while (true) {
		system("cls");	color(WHITE);
		for (int i = nowLine; i < nowLine + PageLine; i++) {
			if (i >= novelContent[nName].size()) { state = 1; break; }
			stringstream stream(novelContent[nName][i]);
			string temp;
			while (stream >> temp) {
				if (vocaExist[temp]) { color(RED); }
				cout << temp << " ";
				color(WHITE);
			}cout << endl;
		}
		if (state==1 || nowLine >= novelContent[nName].size()) {
			clear();  getchar();
			system("cls"); gotoxy(50, 12);
			color(RED);
			cout << novelName[novelNum - 1] << "끝" << endl;
			color(WHITE);
			state = 1; break;
		}
		
		while (true) {
			printLine(false, "", 27);
			color(YELLOW);
			printLine(true, "e. 나가기 / s. 단어 검색 / f. 이전 페이지 / n. 다음 페이지 : ", 27);
			char sel; cin >> sel;
			if (sel == 'e') { system("cls");  return; }
			else if (sel == 's') { findWord(); }
			else if (sel == 'f' && nowLine>=PageLine) { nowLine -= PageLine; break; }
			else if (sel == 'n') { nowLine += PageLine; break; }
		}
	}
	getchar();
	system("cls");
}

void BookReader::showNovelName() {
	for (int i = 0; i < novelName.size(); i++) {
		cout << i + 1 << " : " << novelName[i] << endl;
	}cout << endl;
}

int BookReader::getSelNovel() {
	int sel;
	cout << "Select Novel : ";
	cin >> sel;
	return sel;
}

int BookReader::getSelmenu() {
	int sel;
	cout << "Select Menu : ";
	cin >> sel;
	cout << endl;
	return sel;
}

void BookReader::findWord() {
	while (true) {
		char searchState = 0;
		printLine(false, "", 27);
		printLine(true, "단어를 검색하시겠습니까?(yes : 1 / no : 2) : ", 27);
		cin >> searchState;
		if (searchState == '1') {
			char word[100] = { 0 };
			char mean[100] = { 0 };
			printLine(false, " ", 27);
			gotoxy(0, 27);
			cout << "한글로 번역할 단어를 입력하세요 : ";
			cin >> word;

			auto vocaIt = vocaMap.find((string)word);
			if (vocaIt != vocaMap.end()) {
				strcpy(mean, (vocaIt->second.first).c_str());
				strcat(word, "의 뜻 : ");
				clear();
			}
			else {
				char tword[30] = { 0 };
				searchWord2(word);
				addVocaToTxt(word, mean);
				vocaExist.insert({ word, 1 });
				printLine(false, " ", 27);
				strcpy(tword, word);
				printLine(true, strcat(tword, "의 뜻 : "), 27);
				clear();
				cin.getline(mean, 100);
			}
			printLine(false, " ", 28);
			printLine(true, strcat(word, mean), 28);
			printLine(false, " ", 27);
			clear();
		}
		else if (searchState == '2') { break; }
		else { continue; }
		printLine(false, " ", 28);
	}
}

// 2. function interpret Sentence
void BookReader::readNovelInterpret(string nName) {
	ifstream in(nName);
	vector<string> interpret;

	while (!in.eof()) {
		string temp; 
		getline(in, temp);
		//cout << temp<<endl;
		interpret.push_back(temp);
	}
	novelInterpret.insert({ nName, interpret });
}
void BookReader::writeNovelInterpret(string nName) {
	fstream out(nName);
	vector<string> interpret;

	for (int i = 0; i < novelInterpret["Interpret.txt"].size(); i++) {
		out << novelInterpret["Interpret.txt"][i] << endl;
	}
}
void BookReader::funcInterpretSentence() {
	showNovelName();
	int novelNum = getSelNovel(); clear();
	string nName = novelName[novelNum-1];
	int nowLine = 0 , pageNum=0; 
	
	readNovelContent(nName);
	readNovelInterpret("Interpret.txt");
	/*cout << novelInterpret["Interpret.txt"].size()<<endl;
	for (int i = 0; i<novelInterpret["Interpret.txt"].size();i++) {
		cout << novelInterpret["Interpret.txt"][i] << endl;
	}*/
	while (true) {
		std::system("cls");
		color(YELLOW);
		cout << "< 제목 : " << novelName[novelNum - 1] << " > Menu로 가기 : * 입력" << endl << endl;

		color(WHITE);
		while (true) {
			int len = novelContent[nName][nowLine].size();
			if (len <= 1) { nowLine++;  continue; }
			cout << novelContent[nName][nowLine] << endl;
			if (len < LineLength) { nowLine++; break; }
			if (len>2 && novelContent[nName][nowLine][len-2] == '.') { nowLine++; break; }
			nowLine++;
		}

		color(GREEN);
		cout << "\n<Follow Up>" << endl << endl;
		string tempTyping;
		getline(cin, tempTyping);

		if (tempTyping.size()>0 && tempTyping[tempTyping.size() - 1] == '*') {
			std::system("cls"); break;
		}
		cout << endl << "==========================================================================\
===========================================" << endl << endl;
		
		color(BLUE);
		cout << "<해석>" << endl << endl;
		string tempInterpret;
		//cout << "vec : " << novelInterpret["Interpret.txt"].size() << "now : " << pageNum << endl;
		if (novelInterpret["Interpret.txt"].size() > pageNum && novelInterpret["Interpret.txt"][pageNum].size()==0) {
			getline(cin, tempInterpret);
			novelInterpret["Interpret.txt"][pageNum] = tempInterpret;
		}
		else if (novelInterpret["Interpret.txt"].size()<=pageNum) {
			getline(cin, tempInterpret);
			novelInterpret["Interpret.txt"].push_back(tempInterpret);
		}
		else {
			cout << novelInterpret["Interpret.txt"][pageNum] << endl;
		}
		if (tempInterpret.size() > 0 && tempInterpret[tempInterpret.size() - 1] == '*') {
			std::system("cls"); return;
		}
		cout << endl << "==========================================================================\
===========================================" << endl << endl;
		pageNum++; clear();
	}
	writeNovelInterpret("Interpret.txt");
}

// 3. function Voca Note
void BookReader::funcVocaNote() {
	while (true) {
		cout << "Voca" << endl << endl;
		//if (voca.size() == 0) makeVocaNote();
		showVocaMenu();
		int sel = getSelVocaMenu();
		if (sel == 0) { system("cls"); return; }
		while (true) {
			showVocaContent(sel);
			int editSel;
			cout << endl << "Contents 수정(y=1,n=0) : ";
			cin >> editSel;
			if (editSel == 0) { break; }
			char tword[30] = { 0 };
			int vScore = 0;
			string type = "En";
			if (sel == 1) {
				cout << "<Known Voca>로 변경할 단어 입력 : ";
				cin >> tword;
				vScore = 10;
			}
			if (sel == 2) {
				cout << "<Unknown Voca>로 변경할 단어 입력 : ";
				cin >> tword;
				vScore = 5;
			}
			editVocaScore(type, tword, vScore);
		}
		clear();
		system("cls");
	}
}

// it => map
// it->fist => key (string)
// it->second => value (pair<string,int>)
// it->second.first = pair.first (string)
// it->second.second = pair.second (int)

void BookReader::showVocaMenu() {
	system("cls");
	cout << "---------Menu---------" << endl;
	cout << "1. Unknown" << endl;
	cout << "2. Known" << endl;
	cout << "3. All" << endl;
	cout << "0. Exit" << endl;
	cout << "----------------------" << endl;
}

int BookReader::getSelVocaMenu() {
	int sel;
	cout << endl << "메뉴를 선택하세요 : ";
	cin >> sel;
	cout << endl;
	return sel;
}

void BookReader::showVocaContent(int sel) {
	system("cls");
	for (int i = 0; i < voca.size(); i++) {
		if (sel == 1 && voca[i].getScore() < 10)
			cout << voca[i].getWord() << " - " << voca[i].getMean() << endl;
		else if (sel == 2 && voca[i].getScore() >= 10)
			cout << voca[i].getWord() << " - " << voca[i].getMean() << endl;
		else if (sel == 3)
			cout << voca[i].getWord() << " - " << voca[i].getMean() << endl;
	}
}

void BookReader::editVocaScore(string type, char tword[30], int vScore) {
	FILE* out = fopen("Voca.txt", "wt");
	int i;
	for (i = 0; i < voca.size(); i++) {
		if (type == "En" && !strcmp(voca[i].getWord().c_str(), tword)) {
			break;
		}
		else if (type == "Kr" && !strcmp(voca[i].getMean().c_str(), tword)) {
			break;
		}
	}
	voca[i].setScore((vScore == 1 || vScore == -1) ? voca[i].getScore() + vScore : vScore);
	for (i = 0; i < voca.size(); i++) {
		fprintf(out, "%s %s %d", voca[i].getWord().c_str(), voca[i].getMean().c_str(), voca[i].getScore());
		if (i != voca.size() - 1) fprintf(out, "\n");
	}
}
//4 function Voca Test


