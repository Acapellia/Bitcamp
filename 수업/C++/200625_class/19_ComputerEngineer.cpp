#include<iostream>
#include"ComputerEngineer.h"
using namespace std;

ComputerEngineer::ComputerEngineer(int age, char* Name, int nComputer) :Human(age, Name) {
	m_nComputer = nComputer;
	cout << "computerEngineer 생성자 호출" << endl;
}
ComputerEngineer ::~ComputerEngineer() {
	cout << "ComputerEngineer 소멸자 호출" << endl;
}

void ComputerEngineer :: Overtime() { cout << m_strName << "는 야근을 한다." << endl;; }
void ComputerEngineer::Info() {
	Human::Info();
	cout << m_strName << "는 컴퓨터를" << m_nComputer << "대를 가지고 있다." << endl;
}
void ComputerEngineer::Play() {
	cout << "Computer Engineer Play()" << endl;
}
