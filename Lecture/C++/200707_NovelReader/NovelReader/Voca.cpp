#pragma once
#include "Voca.h"

Voca::Voca() {  }
Voca::Voca(string w, string m, int s) {
	word = w; mean = m; score = s; proFre = 0; ansFre = 0;
}
string Voca::getWord() { return word; }
void Voca::setWord(string w) { word = w; }
string Voca::getMean() { return mean; }
void Voca::setMean(string m) { mean = m; }
int Voca::getScore() { return score; }
void Voca::setScore(int s) { score = s; }
int Voca::getAnsFre() { return ansFre; }
void Voca::setAnsFre(int n) { ansFre = n; }
int Voca::getProFre() { return proFre; }
void Voca::setProFre(int n) { proFre = n; }