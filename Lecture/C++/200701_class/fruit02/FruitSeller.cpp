#include "FruitSeller.h"
#include<iostream>
using namespace std;

int FruitSeller::saleApple(int money)
{
	int num = money / APPLE_PRICE;
	this->numOfApple -= num;
	this->money += money;
	return num;
}
void FruitSeller::showSaleResult()
{
	cout << "[판매자의 현황]" << endl;
	cout << "남은 사과: " << this->numOfApple << endl;
	cout << "전체 총액: " << this->money << endl;
	cout << endl;
}