#include<iostream>
#include "Human.h"
#include "ComputerEngineer.h"
#include "Programmer.h"
#include "ServerManager.h"

using namespace std;


int main()
{
	Human human(30, "ȫ�浿");
	ComputerEngineer comEng(24, "�Ӳ���",3);
	Programmer prog(32, "����", 5, 10);
	ServerManager serv(33, "������", 2, 28);
	Human* p = &human;
	p->Play();
	p = &comEng;
	p->Play();
	p = &prog;
	p->Play();
	p = &serv;
	p->Play();

	return 0;
}