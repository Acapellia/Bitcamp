#include "ServerManager.h"
ServerManager::ServerManager(string n, int a, int nc, int ns) \
	: ComputerEngineer(n, a, nc) {
	this->nManagedServer = ns;
	cout << "ServerManager ������ ȣ��" << endl;
}
ServerManager::~ServerManager() {
	cout << "ServerManager �Ҹ��� ȣ��" << endl;
}
void ServerManager::work() {
	cout << name << "�� ���� �ҽÿ� ���ϱ�" << endl;
}
void ServerManager::info() {
	ComputerEngineer::info();
	cout << name << "�� �����ϴ� ������ " << nManagedServer << "�� �̴�." << endl;
}