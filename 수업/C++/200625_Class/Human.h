#pragma once
class Human {
protected:
	int m_nAge;
	char* m_strName;
public:
	Human(int age, char* Name);
	~Human();
public:
	void Eat();
	void Sleep();
	void Work();
	void Info();
	virtual void Play();
};