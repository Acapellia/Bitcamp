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
	//mn.g[0] = Goods("���", 1000); //"����", 100
	while (true) { // ��ǰ �� �� for(;;){}
		cout << "1. ��ǰ �߰�" << endl;
		cout << "2. ��ǰ ����" << endl;
		int sel;
		cout << "�޴��� �����ϼ��� : ";
		cin >> sel;
		if (sel == 1) {
			string Gname;
			int Gprice;
			cout << "��ǰ �̸��� �Է��ϼ��� : "; cin >> Gname;
			cout << "��ǰ ������ �Է��ϼ��� : "; cin >> Gprice;
			mn.addGoods(Goods(Gname, Gprice));
			cout << endl;
		}
		else if (sel == 2) {
			string goods;
			int i;
			cout << "������ ��ǰ �̸� : ";
			cin >> goods;
			for (i = 0; i < mn.getCnt(); i++) { // ���忡 �ش� ��ǰ�� �ִ���
				if (mn.g[i].getName() == goods) {
					mn.calcPrice(mn.g[i]);
					break;
				}
			}
			if (i == mn.getCnt()) { cout << "�����Ϸ��� ��ǰ�� �����ϴ�" << endl; }
			cout << "���� ���� : " << mn.getMoney() << endl << endl;
		}
	}
}