#include <iostream>
#include "Function.h"
#include "BookReader.h"
using namespace std;
#include<string>
void main()
{
	BookReader br;
	br.showMainScreen();
	getchar();
	br.readNovelName();
	br.readVocaTxt();
	while (true) {
		system("cls");
		br.showMenu();
		char sel = br.getSelmenu(); clear();
		if (sel == '1') { br.funcReadNovel(); }
		else if (sel == '2') { br.funcInterpretSentence(); }
		else if (sel == '3') { br.funcVocaNote(); }
		else if (sel == '4') { br.funcVocaTest(); }
		else if (sel == '0') { return; }
		else { cout << "Please select the menu again." << endl << endl; getchar(); continue; }
	}
	//search();
}

