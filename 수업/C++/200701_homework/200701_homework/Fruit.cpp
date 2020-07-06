/* 둘 이상의 클래스를 만들어서 상호작용

"과일구매자가 과일장수한테 2000원을 주고
사과 2개를 구매했다"

[객체지향 설계 방법]
1) 업무별(역할별) - MVC 패턴
   Model: Data, DataAccess        (명사형 클래스)
   View : 화면, 사용자와의 입출력   (명사형 클래스)
   Controller : 업무, 로직, 처리 집합 (동사형 클래스)
2) 명사-동사 구분법
   명사중에 큰 개념 : 클래스의 대상
   명사중에 작은 개념 : 멤버변수의 대상
   동사들이 모여서 종류 그룹 : 클래스
   그냥 동사(하는 기능) : 멤버함수
*/
/*
"과일구매자가 과일장수한테 2000원을 주고
사과 2개를 구매했다"

명사: 과일구매자, 과일장수, 2000원, 사과 2개
동사: 주다, 구매하다

클래스 : 과일구매자, 과일장수
멤버변수 : 2000원, 사과 2개
멤버함수 : 주다, 구매하다
*/

#include <iostream>

using namespace std;

class FruitBuyer
{
private:
	int money = 10000;
	int numOfApple = 0;

public:
	void buyApple(int num, int money)
	{
		this->numOfApple += num;
		this->money -= money;
	}
	void showBuyResult()
	{
		cout << "[구매자의 현황]" << endl;
		cout << "사과 개수: " << this->numOfApple << endl;
		cout << "현재 잔액: " << this->money << endl;
		cout << endl;
	}
};

class FruitSeller
{
private:
	int numOfApple = 20;
	int money = 100000;
	const int APPLE_PRICE = 1000;

public:
	int saleApple(FruitBuyer& fb, int money)
	{
		int num = money / APPLE_PRICE;
		this->numOfApple -= num;
		this->money += money;
		fb.buyApple(num, money);
		return num;
	}
	int saleApple(int money)
	{
		int num = money / APPLE_PRICE;
		this->numOfApple -= num;
		this->money += money;
		return num;
	}
	void showSaleResult()
	{
		cout << "[판매자의 현황]" << endl;
		cout << "남은 사과: " << this->numOfApple << endl;
		cout << "전체 총액: " << this->money << endl;
		cout << endl;
	}
};
void main()
{
	FruitSeller seller;
	FruitBuyer buyer;

	seller.showSaleResult();
	buyer.showBuyResult();

	cout << "==========================\n";
	seller.saleApple(buyer, 2000);
	//buyer.buyApple(seller, 2000);

	seller.showSaleResult();
	buyer.showBuyResult();
}