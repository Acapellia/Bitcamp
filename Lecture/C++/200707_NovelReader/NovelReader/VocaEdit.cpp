#include <iostream>
#include "BookReader.h"
using namespace std;

void main() {
	FILE* in = fopen("Voca.txt", "r+");
	map<string, pair<string, int>> voca;
	vector<pair<string, string> > vp;
	int n=0;
	char tword[30] = { 0 };
	int cscore;
	cout << "점수를 변경할 단어 입력 : ";
	cin >> tword;
	cout << "점수를 올린다1 내린다-1 : ";
	cin >> cscore;

	char word[30], mean[30];
	int score;
	while (!feof(in)) {
		fscanf(in, "%s", word); fscanf(in, "%s", mean); fscanf(in, "%d", &score);
		if (!strcmp(word, tword)) { 
			n += (strlen(word) + strlen(mean) + 2);
			break;
			//fprintf(in, "%d", 11); break; 
		}
		n += (strlen(word) + strlen(mean)+2);
		n += (strlen("\n")*2 + 1);
		cout << word << " " << mean << endl;
	}
	fseek(in, n, SEEK_SET);
	cout << ftell(in)<<endl;
	fprintf(in, "%d", score+cscore);
}