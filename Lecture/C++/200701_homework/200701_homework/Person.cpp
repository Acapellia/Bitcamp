#include <cstdio>
#include <cstring>
#include <Windows.h>
#include "Person.h"
#include "Define.h"


Person::Person() {
	name = new char[NAME_LEN];
	phone = new char[TEL_LEN];
}
Person::Person(const Person& p) {
	name = new char[NAME_LEN + 1];
	phone = new char[TEL_LEN + 1];
	strcpy(name, p.name);
	strcpy(phone, p.phone);
}
Person::~Person() {
	delete[] name;
	delete[] phone;
}

// getter
char* Person::getName() {
	return name;
}
// setter
void Person::setName(char* _name)
{
	strncpy(name, _name, strlen(_name));
	name[strlen(_name)] = '\0';// 0, NULL
}
char* Person::getPhone()
{
	return phone;
}
void Person::setPhone(char* _phone)
{
	strncpy(phone, _phone, strlen(_phone));
	phone[strlen(_phone)] = '\0';
}
void Person::showPerson()
{
	printf("name: %s\n", name);
	printf("phone: %s\n", phone);
}
Person Person::getPerson()
{
	return *this;
}