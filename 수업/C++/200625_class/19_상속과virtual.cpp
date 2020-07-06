#include<iostream>
#include "Human.h"
#include "ComputerEngineer.h"
#include "Programmer.h"
#include "ServerManager.h"

using namespace std;


int main()
{
	Human human(30, "홍길동");
	ComputerEngineer comEng(24, "임꺽정",3);
	Programmer prog(32, "장길산", 5, 10);
	ServerManager serv(33, "일지매", 2, 28);
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