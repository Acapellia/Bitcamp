#pragma once
#include<iostream>
using namespace std;

class Voca {
private:
	string word;
	string mean;
	int score;
public:
	Voca();
	Voca(string w, string m, int s);
	string getWord();
	void setWord(string w);
	string getMean();
	void setMean(string m);
	int getScore();
	void setScore(int s);
};