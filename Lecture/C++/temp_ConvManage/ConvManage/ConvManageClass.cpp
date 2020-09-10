#include<iostream>
#include<vector>
#include<set>
using namespace std;

class ConvManage {
private:
	set<string> conv;
	vector<int> convNum;
	vector<int> convPrice;
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
		conv.insert(cName);
		convPrice.push_back(cPrice);
		convNum.push_back(cNum);
	}
	void addConvStock(string cName, int cNum) {
		if (!findConv(cName)) { cout << "해당 상품이 없어 재고를 추가할 수 없습니다." << endl; return; }
		int idx=0;
		set<string>::iterator it = conv.begin();
		while (it != conv.end()) {
			if (*it == cName) {
				break;
			}
			idx++;
		}
		convNum[idx] += cNum;
		cout << cName << " 상품의 개수가" << convNum[idx] << "개가 되었습니다." << endl;
	}
	bool findConv(string cName) {
		set<string>::iterator it = conv.find(cName);
		if (it != conv.end()) {
			cout << cName << "상품이 있습니다." << endl;
			return true;
		}
		else {
			cout << cName << "상품이 없습니다." << endl;
			return false;
		}
	}
};
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