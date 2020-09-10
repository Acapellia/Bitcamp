#include<iostream>
#include "ServerManager.h"
using namespace std;

ServerManager::ServerManager(int age, char* Name, int nComputer, int nManagedComputer) :ComputerEngineer(age, Name, nComputer) {
	m_nManagedComputer = nManagedComputer;
	cout << "ServerManager 생성자 호출" << endl;
}
ServerManager::~ServerManager() {
	cout << "ServerManger 소멸자 호출" << endl;
}

void ServerManager::Work() { cout << m_strName << "는 종종 불시에 일하기" << endl; }
void ServerManager::Info() {
	ComputerEngineer::Info();
	cout << m_strName << "는 관리하는 컴퓨터 수가" << m_nManagedComputer << "대 이다." << endl;
}
void ServerManager::Play() {
	cout << "Server Manager Play() :" << endl;
}