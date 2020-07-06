#pragma once
#include "FruitSeller.h"

class FruitBuyer
{
private:
	int money = 10000;
	int numOfApple = 0;

public:
	void buyApple(FruitSeller& seller, int money);
	void showBuyResult();
};