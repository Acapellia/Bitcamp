/* <���� ���� ����>
1) class�� ����ο� �����η� �и��Ѵ�
2) ����δ� h(�������)�� �����Ѵ�
3) �����δ� cpp(�ҽ�����)�� �����Ѵ�
4) �ش� ���Ͽ� ���� ������ #include�� ���ش�
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