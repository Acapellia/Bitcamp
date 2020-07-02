#pragma once
class Person
{
private:
	char* name;
	char* phone;

public:
	Person();
	Person(const Person& p);
	~Person();

public:
	// getter
	char* getName();
	// setter
	void setName(char* _name);
	char* getPhone();
	void setPhone(char* _phone);
	void showPerson();
	Person getPerson();
};