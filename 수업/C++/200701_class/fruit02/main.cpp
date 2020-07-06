/* <파일 분할 절차>
1) class를 선언부와 구현부로 분리한다
2) 선언부는 h(헤더파일)로 생성한다
3) 구현부는 cpp(소스파일)로 생성한다
4) 해당 파일에 없는 정보는 #include를 해준다
*/
#pragma once
#include <iostream>
#include "FruitSeller.h"
#include "Fruitbuyer.h"
using namespace std;

void main()
{
	FruitSeller seller;
	FruitBuyer buyer;
	buyer.buyApple(seller, 2000);

	seller.showSaleResult();
	buyer.showBuyResult();
}