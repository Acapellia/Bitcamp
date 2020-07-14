#include<iostream>
#include<cstdio>
#include<fstream>
#include<string>
#include<utility>
#include<vector>
#include<map>
#include<ctime>
using namespace std;

void main()
{
	srand((unsigned)time(NULL));
	FILE* in = fopen("Voca.txt", "r");
	map<string, pair<string, int>> voca;
	vector<pair<string, string> > vp;
	while (!feof(in)) {
		char word[30], mean[30];
		int score;
		fscanf(in, "%s", word); fscanf(in, "%s", mean); fscanf(in, "%d", &score);
		voca.insert({ word,make_pair(mean,score) });
		voca.insert({ mean,make_pair(word,score) });
		vp.push_back(make_pair(word,mean));
		//cout << word << " - " << voca[word].first << " : " << voca[word].second << endl;
	}
	/*map<string, pair<string, int>>::iterator it = voca.begin();
	while (it != voca.end()) {
		cout << it->first << " " << it->second.first << " " << it->second.second << endl;
		it++;
	}*/
	while (true) {
		cout << "------------------\n";
		int snum = rand() % 2;
		int rnum = rand() % vp.size();
		if (snum == 0) {
			cout << vp[rnum].first << endl;
			while (true) {
				string Ans;
				cin >> Ans;
				if (Ans == vp[rnum].second) break;
			}
		}
		else if (snum == 1) {
			cout << vp[rnum].second << endl;
			while (true) {
				string Ans;
				cin >> Ans;
				if (Ans == vp[rnum].first) break;
			}
		}
	}
}
