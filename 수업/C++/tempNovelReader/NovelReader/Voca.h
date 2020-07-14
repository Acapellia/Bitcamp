#pragma once
#include<iostream>
using namespace std;

class Voca {
private:
	string word;
	string mean;
	int score;
	int ansFre;
	int proFre;
public:
	Voca();
	Voca(string w, string m, int s);
	string getWord();
	void setWord(string w);
	string getMean();
	void setMean(string m);
	int getScore();
	void setScore(int s);
	int getAnsFre();
	void setAnsFre(int n);
	int getProFre();
	void setProFre(int n);
};