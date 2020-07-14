#include<iostream>
#include<vector>
#include<set>
using namespace std;
class Conv {
	string convName;
	int convNum;
	int convPrice;
public:
	Conv() {}
	Conv(string cName, int cPrice, int cNum ) {
		convName = cName; convPrice = cPrice; convNum = cNum;
	}
	string getName() { return convName; }
	int getNum() { return convNum; }
	void setNum(int cNum) { convNum = cNum; }
	int getPrice() { return convPrice; }
};
class ConvManage {
private:
	vector<Conv> conv;
public:
	void showMenu() {
		cout << "---<메뉴>---" << endl;
		cout << "1. 상품 추가" << endl;
		cout << "2. 재고 추가" << endl;
		cout << "3. 상품 검색" << endl;
		cout << "0. 종료" << endl;
		cout << "------------" << endl;
	}
	void addConv(string cName, int cPrice, int cNum) {
		conv.push_back(Conv(cName, cPrice, cNum));
	}
	void addConvStock(string cName, int cNum) {
		if (!findConv(cName)) { cout << "해당 상품이 없어 재고를 추가할 수 없습니다." << endl; return; }
		int idx = 0;
		vector<Conv>::iterator it = conv.begin();
		while (it != conv.end()) {
			if (it->getName() == cName) {
				break;
			}
			it++; idx++;
		}
		conv[idx].setNum(conv[idx].getNum()+cNum);
		cout << cName << " 상품의 개수가 " << conv[idx].getNum() << "개가 되었습니다." << endl;
	}
	bool findConv(string cName) {
		vector<Conv>::iterator it = conv.begin();
		while (it != conv.end()) {
			if (it->getName() == cName) { cout << cName << " 상품이 있습니다" << endl; return true; }
		}
		cout << cName << " 상품이 없습니다" << endl;
		return false;
	}
};
/*
// set에 class를 넣는 경우 포인터를 써야한다.
	set<Conv*> co;
	co.insert(new Conv("as", 3, 3));
	set<Conv*>::iterator iter = co.begin();
	cout << (*iter)->getName() << endl;
*/
void main() {
	ConvManage cm;

	while (true) {
		cm.showMenu();
		int sel;
		cout << "메뉴를 선택하세요 : ";
		cin >> sel;
		cout << endl;
		if (sel == 1) {
			string convName;
			int convPrice, convNum;
			cout << "추가하고 싶은 상품 이름 : ";
			cin >> convName;
			cout << "추가하고 싶은 상품의 가격 : ";
			cin >> convPrice;
			cout << "추가하고 싶은 상품의 개수 : ";
			cin >> convNum;
			cm.addConv(convName, convPrice, convNum);
		}
		else if (sel == 2) {
			string convName;
			int convNum;
			cout << "재고를 추가하고 싶은 상품 이름 : ";
			cin >> convName;
			cout << "재고를 추가하고 싶은 상품의 개수 : ";
			cin >> convNum;
			cm.addConvStock(convName, convNum);
		}
		else if (sel == 3) {
			string temp;
			cout << "찾고 싶은 물품을 입력 : ";
			cin >> temp;
			cm.findConv(temp);
		}
		else if (sel == 0) {
			cout << "프로그램을 종료합니다." << endl;
			return;
		}
		else {
			cout << "다시 선택하세요." << endl;
		}
		cout << endl;
	}
}