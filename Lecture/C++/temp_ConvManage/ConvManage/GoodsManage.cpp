#include <iostream>
using namespace std;

class Goods {
	string name;
	int price;
public:
	Goods() {};
	Goods(string n, int p) { name = n; price = p; }
	string getName() { return name; }
	void setName(string n) { name = n; }
	int getPrice() { return price; }
	void setPrice(int p) { price = p; }
};

class Manage {
	int money = 100;
	int cnt = 0;
public:
	Goods g[1000];  // {name , price}
	Manage() {};
	void calcPrice(Goods _g) {
		money += _g.getPrice();
	}
	void addGoods(Goods _g) {
		g[cnt++] = _g;
	}
	int getMoney() { return money; }
	int getCnt() { return cnt; }
};

void main() {
	Manage mn;
	//mn.g[0] = Goods("라면", 1000); //"연필", 100
	while (true) { // 상품 몇 번 for(;;){}
		cout << "1. 상품 추가" << endl;
		cout << "2. 상품 구매" << endl;
		int sel;
		cout << "메뉴를 선택하세요 : ";
		cin >> sel;
		if (sel == 1) {
			string Gname;
			int Gprice;
			cout << "상품 이름을 입력하세요 : "; cin >> Gname;
			cout << "상품 가격을 입력하세요 : "; cin >> Gprice;
			mn.addGoods(Goods(Gname, Gprice));
			cout << endl;
		}
		else if (sel == 2) {
			string goods;
			int i;
			cout << "구매할 상품 이름 : ";
			cin >> goods;
			for (i = 0; i < mn.getCnt(); i++) { // 매장에 해당 상품이 있는지
				if (mn.g[i].getName() == goods) {
					mn.calcPrice(mn.g[i]);
					break;
				}
			}
			if (i == mn.getCnt()) { cout << "구매하려는 상품이 없습니다" << endl; }
			cout << "현재 매출 : " << mn.getMoney() << endl << endl;
		}
	}
}