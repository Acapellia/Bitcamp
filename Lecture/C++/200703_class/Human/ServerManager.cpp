#include "ServerManager.h"
ServerManager::ServerManager(string n, int a, int nc, int ns) \
	: ComputerEngineer(n, a, nc) {
	this->nManagedServer = ns;
	cout << "ServerManager 생성자 호출" << endl;
}
ServerManager::~ServerManager() {
	cout << "ServerManager 소멸자 호출" << endl;
}
void ServerManager::work() {
	cout << name << "은 종종 불시에 일하기" << endl;
}
void ServerManager::info() {
	ComputerEngineer::info();
	cout << name << "이 관리하는 서버는 " << nManagedServer << "대 이다." << endl;
}