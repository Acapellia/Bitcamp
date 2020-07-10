#include <iostream>
#include "BookReader.h"
using namespace std;
#include<string>
void main()
{
	BookReader br;
	br.readNovelName();
	br.readVocaTxt();
	while (true) {
		br.showMenu();
		int sel = br.getSelmenu();
		if (sel == 1) { br.funcReadNovel(); }
		else if (sel == 2) { br.funcInterpretSentence(); }
		else if (sel == 3) { br.funcVocaNote(); }
		else if (sel == 0) { return; }
		else { cout << "Please select the menu again." << endl << endl; return; }
	}
	//search();
}

