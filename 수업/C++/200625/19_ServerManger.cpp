#include<iostream>
#include "ServerManager.h"
using namespace std;

ServerManager::ServerManager(int age, char* Name, int nComputer, int nManagedComputer) :ComputerEngineer(age, Name, nComputer) {
	m_nManagedComputer = nManagedComputer;
	cout << "ServerManager ������ ȣ��" << endl;
}
ServerManager::~ServerManager() {
	cout << "ServerManger �Ҹ��� ȣ��" << endl;
}

void ServerManager::Work() { cout << m_strName << "�� ���� �ҽÿ� ���ϱ�" << endl; }
void ServerManager::Info() {
	ComputerEngineer::Info();
	cout << m_strName << "�� �����ϴ� ��ǻ�� ����" << m_nManagedComputer << "�� �̴�." << endl;
}
void ServerManager::Play() {
	cout << "Server Manager Play() :" << endl;
}