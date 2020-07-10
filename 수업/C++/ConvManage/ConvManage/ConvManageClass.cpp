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
		cout << "---<�޴�>---" << endl;
		cout << "1. ��ǰ �߰�" << endl;
		cout << "2. ��� �߰�" << endl;
		cout << "3. ��ǰ �˻�" << endl;
		cout << "0. ����" << endl;
		cout << "------------" << endl;
	}
	void addConv(string cName, int cPrice, int cNum) {
		conv.insert(cName);
		convPrice.push_back(cPrice);
		convNum.push_back(cNum);
	}
	void addConvStock(string cName, int cNum) {
		if (!findConv(cName)) { cout << "�ش� ��ǰ�� ���� ��� �߰��� �� �����ϴ�." << endl; return; }
		int idx=0;
		set<string>::iterator it = conv.begin();
		while (it != conv.end()) {
			if (*it == cName) {
				break;
			}
			idx++;
		}
		convNum[idx] += cNum;
		cout << cName << " ��ǰ�� ������" << convNum[idx] << "���� �Ǿ����ϴ�." << endl;
	}
	bool findConv(string cName) {
		set<string>::iterator it = conv.find(cName);
		if (it != conv.end()) {
			cout << cName << "��ǰ�� �ֽ��ϴ�." << endl;
			return true;
		}
		else {
			cout << cName << "��ǰ�� �����ϴ�." << endl;
			return false;
		}
	}
};
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