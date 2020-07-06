#pragma once
#include<iostream>
using namespace std;
class Human
{
protected:
	string name;
	int age;
public:
	Human(string n = "»ç¶÷", int a = 0);
	~Human();
	void eat();
	void sleep();
	void work();
	void info();
};

