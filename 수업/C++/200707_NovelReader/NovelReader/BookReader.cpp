#pragma once
#include "BookReader.h"
#include <cstdio>
#include <fstream>
#include <string>
#include <sstream>
#include <windows.h>
#include <set>
#include "Turboc.h"
#include "Function.h"
#include "Voca.h"

using namespace std;

void BookReader::showMainScreen() {
	mainScreen.push_back("\n\n\n\n\n\n");
	mainScreen.push_back("		            CCCCCCCCCCCCCCCCC      EEEEEEEEEEEEEEEEE      OOOOOOOOOOOOOOOOO\n");
	mainScreen.push_back("		            CC                     EE                     OO             OO\n");
	mainScreen.push_back("		            CC                     EE                     OO             OO\n");
	mainScreen.push_back("		            CC                     EE                     OO             OO\n");
	mainScreen.push_back("		            CC                     EE                     OO             OO\n");
	mainScreen.push_back("		            CC                     EE                     OO             OO\n");
	mainScreen.push_back("		            CC                     EEEEEEEEEEEEEEEEE      OO             OO\n");
	mainScreen.push_back("		            CC                     EE                     OO             OO\n");
	mainScreen.push_back("		            CC                     EE                     OO             OO\n");
	mainScreen.push_back("		            CC                     EE                     OO             OO\n");
	mainScreen.push_back("		            CC                     EE                     OO             OO\n");
	mainScreen.push_back("		            CC                     EE                     OO             OO\n");
	mainScreen.push_back("		            CCCCCCCCCCCCCCCCC      EEEEEEEEEEEEEEEEE      OOOOOOOOOOOOOOOOO\n\n");
	mainScreen.push_back("\n			    		           <start with enter>\n");
	for (int i = 0; i < mainScreen.size(); i++)
		cout << mainScreen[i];
}

void BookReader::showMenu() {
	cout << "----------Menu----------" << endl;
	cout << "1. Read Novel" << endl;
	cout << "2. Interpreting a sentence" << endl;
	cout << "3. Open Vocabulary note" << endl;
	cout << "4. Words Test" << endl;
	cout << "0. Exit" << endl;
	cout << "------------------------" << endl;
}

void BookReader::readNovelName() {
	ifstream in("Novel.txt");
	while (!in.eof()) {
		string name;
		getline(in, name);
		novelName.push_back(name + ".txt");
		interpretName.push_back(name + "Interpret.txt");
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
	fclose(note);
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
		while (content.size() >= LineLength) {
			nContent.push_back(content.substr(0, LineLength));
			content = content.substr(LineLength, content.size() - 1);
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
	char novelNum = getSelNovel(); clear();
	if ((novelNum - '0')==0) return;
	string nName = novelName[(novelNum - '0') - 1];
	int nowLine = 0;
	int state = 0;
	readNovelContent(nName);
	while (true) {
		system("cls");	color(WHITE);
		if (nowLine > novelContent[nName].size()) { state = 1; break; }
		for (int i = nowLine; i < nowLine + PageLine; i++) {
			if (i >= novelContent[nName].size()) { break; }
			stringstream stream(novelContent[nName][i]);
			string temp;
			while (stream >> temp) {
				if (vocaExist[temp]) { color(RED); }
				cout << temp << " ";
				color(WHITE);
			}cout << endl;
		}
		color(BLUE);
		gotoxy(0, 26); std::cout << "page -> " << nowPage;
		while (true) {
			printLine(false, "", 27);
			color(YELLOW);
			printLine(true, "e. 나가기 / s. 단어 검색 / f. 이전 페이지 / n. 다음 페이지 / w. 원하는 페이지 : ", 27);
			char sel; cin >> sel;
			if (sel == 'e') { std::system("cls");  return; }
			else if (sel == 's') { findWord(); }
			else if (sel == 'f' && nowLine >= PageLine) { nowLine -= PageLine; nowPage--; break; }
			else if (sel == 'n') { 
				nowLine += PageLine; 
				nowPage++;
				if (nowLine > novelContent[nName].size()) { state = 1;} break;
			}
			else if (sel == 'w') {
				int page;
				while (true) {	
					cout << "원하는 페이지를 입력하세요(숫자로 입력하세요) : ";
					cin >> page;
					if (page<0 || page>novelContent[nName].size() / PageLine) {
						std::cout << "해당 페이지가 없습니다." << endl;
					}
					else { break; }
				}
				if (page > nowPage) { 
					nowLine += (page - nowPage) * PageLine; nowPage += (page - nowPage); 
				}
				else if (page < nowPage) {
					nowLine -= (nowPage - page) * PageLine; nowPage -= (nowPage - page);
				}
				break;
			}
		}
		if (state == 1 || nowLine >= novelContent[nName].size()) {
			clear();
			system("cls"); gotoxy(50, 12);
			color(RED);
			cout << novelName[(novelNum-'0') - 1] << "끝" << endl;
			color(WHITE);
			state = 1; break;
		}		
	}
	getchar();
	system("cls");
}

void BookReader::showNovelName() {
	for (int i = 0; i < novelName.size(); i++) {
		cout << i + 1 << " : " << novelName[i] << endl;
	}
	cout << "0 : exit" << endl << endl;
}

char BookReader::getSelNovel() {
	char sel;
	cout << "Select Novel : ";
	cin >> sel;
	return sel;
}

char BookReader::getSelmenu() {
	char sel;
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
		cin >> searchState; clear();
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
				clear(); cin.getline(mean, 100);
				addVocaToTxt(word, mean);
				voca.push_back(Voca(word, mean, 0));
				vocaExist.insert({ word, 1 });
				printLine(false, " ", 27);
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
	in.close();
}

void BookReader::writeNovelInterpret(string iName) {
	fstream out(iName);
	//cout << iName << endl;
	vector<string> interpret;

	for (int i = 0; i < novelInterpret[iName].size(); i++) {
		out << novelInterpret[iName][i] << endl;
	}
}

void BookReader::funcInterpretSentence() {
	showNovelName();
	char novelTempNum = getSelNovel(); clear();
	int novelNum = novelTempNum - '0';
	if (novelNum == 0) return;
	string nName = novelName[novelNum - 1];
	string iName = interpretName[novelNum - 1];
	int nowLine = 0, pageNum = 0;
	readNovelContent(nName);
	readNovelInterpret(iName);

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
			if (len > 2 && novelContent[nName][nowLine][len - 2] == '.') { nowLine++; break; }
			nowLine++;
		}

		color(GREEN);
		cout << "\n<Follow Up>" << endl << endl;
		string tempTyping;
		getline(cin, tempTyping);

		if (tempTyping.size() > 0 && tempTyping[tempTyping.size() - 1] == '*') {
			std::system("cls"); break;
		}
		cout << endl << "==========================================================================\
===========================================" << endl << endl;

		color(BLUE);
		cout << "<해석>" << endl << endl;
		string tempInterpret;
		//cout << "vec : " << novelInterpret["Interpret.txt"].size() << "now : " << pageNum << endl;
		if (novelInterpret[iName].size() > pageNum && novelInterpret[iName][pageNum].size() == 0) {
			getline(cin, tempInterpret);
			novelInterpret[iName][pageNum] = tempInterpret;
		}
		else if (novelInterpret[iName].size() <= pageNum) {
			getline(cin, tempInterpret);
			novelInterpret[iName].push_back(tempInterpret);
		}
		else {
			cout << novelInterpret[iName][pageNum] << endl;
		}
		if (tempInterpret.size() > 0 && tempInterpret[tempInterpret.size() - 1] == '*') {
			std::system("cls"); return;
		}
		cout << endl << "==========================================================================\
===========================================" << endl << endl;

		while (true) {
			cout << "해석을 수정하시겠습니까?(y/n) : ";
			int ty = wherey();
			string sel;
			//clear();
			getline(cin, sel);
			while (sel == "") { gotoxy(33, ty); getline(cin, sel); break; }
			if (sel[0] == 'y') {
				string temp;
				cout << "<해석 수정>" << endl;
				getline(cin, temp);
				novelInterpret[iName][pageNum] = temp;
				writeNovelInterpret(iName);
			}
			else if (sel[0] == 'n') { break; }
		}
		pageNum++; 
	}
	writeNovelInterpret(iName);
}


// 3. function Voca Note
void BookReader::funcVocaNote() {
	while (true) {
		cout << "Voca" << endl << endl;
		showVocaMenu();
		char sel = getSelVocaMenu(); clear();
		if (sel == '0') { std::system("cls"); return; }
		else if (!(sel == '1' || sel == '2' || sel == '3')) { continue; }
		while (true) {
			showVocaContent(sel);
			char editSel; 
			cout << endl << "Contents 수정(y=1,n=0) : ";
			cin >> editSel; clear();
			if (editSel == '0') { break; }
			else if (sel == '3') { continue; }
			char tword[30] = { 0 };
			int vScore = 0;
			string type = "En";
			if (sel == '1') {
				cout << "<Known Voca>로 변경할 단어 입력 : ";
				cin >> tword;
				vScore = 10;
			}
			if (sel == '2') {
				cout << "<Unknown Voca>로 변경할 단어 입력 : ";
				cin >> tword;
				vScore = 5;
			}
			editVocaScore(type, tword, vScore);
		}
		writeVocaTxt();
		std::system("cls");
	}
}

void BookReader::showVocaMenu() {
	std::system("cls");
	cout << "---------Menu---------" << endl;
	cout << "1. Unknown" << endl;
	cout << "2. Known" << endl;
	cout << "3. All" << endl;
	cout << "0. Exit" << endl;
	cout << "----------------------" << endl;
}

char BookReader::getSelVocaMenu() {
	char sel;
	cout << endl << "메뉴를 선택하세요 : ";
	cin >> sel;
	cout << endl;
	return sel;
}

void BookReader::showVocaContent(char sel) {
	std::system("cls");
	for (int i = 0; i < voca.size(); i++) {
		if (sel == '1' && voca[i].getScore() < 10)
			cout << voca[i].getWord() << " - " << voca[i].getMean() << endl;
		else if (sel == '2' && voca[i].getScore() >= 10)
			cout << voca[i].getWord() << " - " << voca[i].getMean() << endl;
		else if (sel == '3')
			cout << voca[i].getWord() << " - " << voca[i].getMean() << endl;
	}
}

void BookReader::editVocaScore(string type, char tword[30], int vScore) {
	int i;
	for (i = 0; i < voca.size(); i++) {
		if (type == "En" && !strcmp(voca[i].getWord().c_str(), tword)) {
			break;
		}
		else if (type == "Kr" && !strcmp(voca[i].getMean().c_str(), tword)) {
			break;
		}
	}
	if (i == voca.size()) { cout << "해당 단어가 txt에 없습니다" << endl;  clear(); getchar(); return; }
	voca[i].setScore((vScore <= 3 || vScore == -1) ? voca[i].getScore() + vScore : vScore);
}

void BookReader::writeVocaTxt() {
	FILE* out = fopen("Voca.txt", "wt");
	for (int i = 0; i < voca.size(); i++) {
		fprintf(out, "%s %s %d", voca[i].getWord().c_str(), voca[i].getMean().c_str(), voca[i].getScore());
		if (i != voca.size() - 1) fprintf(out, "\n");
	}
	fclose(out);
}

//4. function Voca Test
void BookReader::funcVocaTest() {
	std::system("cls");
	string proBlem[50];
	string ansWer[50];
	string inputansWer[50];
	int seqArr[50] = { 0 };
	int scoreArr[50] = { 0 };
	int correctScore = 0, wrongScore = 0;
	int num = 0;
	int rseqNum = 0; // 문제 낸 순서

	srand((unsigned int)time(NULL));
	while (true) {
		system("cls");
		cout << "문제 개수를 입력하세요(50개 이하 / 숫자 아닐 시 터짐 주의) : ";
		cin >> num;
		if (num <= 50) { break; }
	}
	for (int i = 0; i < num; i++) {
		int randEK = rand() % 2;						// EN or KR?
		int freR;
		while (true){
			rseqNum = rand() % voca.size(); // txt파일에 있는 단어 중에 랜덤으로 선택
			freR = rand() % (voca[rseqNum].getScore() + 1); // 출제 빈도 -> 얼마나 해당 단어를 아는지
			if (freR < 10 - voca[rseqNum].getScore()) { break; } // 아는 단어 자주 안나옴
		}
		seqArr[i] = rseqNum;

		if (randEK == 0){
			cout << voca[rseqNum].getWord() << endl;
			proBlem[i] = voca[rseqNum].getWord();
			ansWer[i] = voca[rseqNum].getMean();
		}
		else{
			cout << voca[rseqNum].getMean() << endl;
			proBlem[i] = voca[rseqNum].getMean();
			ansWer[i] = voca[rseqNum].getWord();
		}
		scoreArr[i] = voca[rseqNum].getScore();
		voca[rseqNum].setProFre(voca[rseqNum].getProFre() + 1);
	}
	getchar();
	for (int i = 0; i < num; i++)
	{
		while (true) { // 라인 지키기 -> 답 입력 안하고 넘어가려고 하면 다시 원래 라인으로 
			gotoxy(20, i + 1);
			getline(cin, inputansWer[i]);
			if (inputansWer[i] != "") {
				break;
			}
		}

		if (ansWer[i] == inputansWer[i]){  // 모르는 단어 정답일수록 점수가 높게
			voca[seqArr[i]].setAnsFre(voca[seqArr[i]].getAnsFre() + 1); 	
			correctScore += (10 - scoreArr[i]);
		}
		else { wrongScore += (10 - scoreArr[i]); }
		
		gotoxy(20, i + 2);
	}
	std::system("cls");
	gotoxy(0, 0);

	cout << "테스트 점수 : " << (correctScore * 100) / (correctScore + wrongScore) << endl << endl;
	cout << "<정답율>" << endl;
	cout << "-------------------------\n";

	for (int i = 0; i < voca.size(); i++)
	{
		if (voca[i].getProFre() == 0) { continue; }
		cout << voca[i].getWord() << "의 출제 횟수 : " << voca[i].getProFre() << endl;
		cout << voca[i].getWord() << "의 정답율 : ";
		cout << ((double)voca[i].getAnsFre() / voca[i].getProFre()) * 100 << "%" << endl;
		cout << "-------------------------\n";
	}
	
	getchar();
	std::system("cls");

	// 점수 변환
	int vocSize = voca.size();

	for (int i = 0; i < vocSize; i++){
		if (voca[i].getProFre() != 0){
			double tempScore = ((double)voca[i].getAnsFre() / voca[i].getProFre()) * 100;
			if (voca[i].getProFre() < 3) { // 문제 출제 회수가 3번이 안되면
				tempScore = voca[i].getScore() + 1 >= 9 ? 9 : voca[i].getScore() + 1;
			}
			else if (tempScore == 0) {
				tempScore = voca[i].getScore() - 1 <= 0 ? 0 : voca[i].getScore() - 1;
			}
			else if (tempScore>= 30){ // 정답율이 30퍼이하
				tempScore = voca[i].getScore() + 1 >= 9 ? 9 : voca[i].getScore() + 1;
			}
			else if (tempScore >= 70){ // 정답율이 70퍼이하
				tempScore = voca[i].getScore() + 2 >= 9 ? 9 : voca[i].getScore() + 2;
			}
			else if (tempScore == 100){ // 정답율이 100퍼
				tempScore = voca[i].getScore() + 3 >= 9 ? 9 : voca[i].getScore() + 3;
			}
			voca[i].setScore((int)tempScore);
		}
	}
	// txt파일에 점수 반영
	writeVocaTxt();
}


