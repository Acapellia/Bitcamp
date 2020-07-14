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
		cout << "---<�޴�>---" << endl;
		cout << "1. ��ǰ �߰�" << endl;
		cout << "2. ��� �߰�" << endl;
		cout << "3. ��ǰ �˻�" << endl;
		cout << "0. ����" << endl;
		cout << "------------" << endl;
	}
	void addConv(string cName, int cPrice, int cNum) {
		conv.push_back(Conv(cName, cPrice, cNum));
	}
	void addConvStock(string cName, int cNum) {
		if (!findConv(cName)) { cout << "�ش� ��ǰ�� ���� ��� �߰��� �� �����ϴ�." << endl; return; }
		int idx = 0;
		vector<Conv>::iterator it = conv.begin();
		while (it != conv.end()) {
			if (it->getName() == cName) {
				break;
			}
			it++; idx++;
		}
		conv[idx].setNum(conv[idx].getNum()+cNum);
		cout << cName << " ��ǰ�� ������ " << conv[idx].getNum() << "���� �Ǿ����ϴ�." << endl;
	}
	bool findConv(string cName) {
		vector<Conv>::iterator it = conv.begin();
		while (it != conv.end()) {
			if (it->getName() == cName) { cout << cName << " ��ǰ�� �ֽ��ϴ�" << endl; return true; }
		}
		cout << cName << " ��ǰ�� �����ϴ�" << endl;
		return false;
	}
};
/*
// set�� class�� �ִ� ��� �����͸� ����Ѵ�.
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
		cout << "�޴��� �����ϼ��� : ";
		cin >> sel;
		cout << endl;
		if (sel == 1) {
			string convName;
			int convPrice, convNum;
			cout << "�߰��ϰ� ���� ��ǰ �̸� : ";
			cin >> convName;
			cout << "�߰��ϰ� ���� ��ǰ�� ���� : ";
			cin >> convPrice;
			cout << "�߰��ϰ� ���� ��ǰ�� ���� : ";
			cin >> convNum;
			cm.addConv(convName, convPrice, convNum);
		}
		else if (sel == 2) {
			string convName;
			int convNum;
			cout << "��� �߰��ϰ� ���� ��ǰ �̸� : ";
			cin >> convName;
			cout << "��� �߰��ϰ� ���� ��ǰ�� ���� : ";
			cin >> convNum;
			cm.addConvStock(convName, convNum);
		}
		else if (sel == 3) {
			string temp;
			cout << "ã�� ���� ��ǰ�� �Է� : ";
			cin >> temp;
			cm.findConv(temp);
		}
		else if (sel == 0) {
			cout << "���α׷��� �����մϴ�." << endl;
			return;
		}
		else {
			cout << "�ٽ� �����ϼ���." << endl;
		}
		cout << endl;
	}
}