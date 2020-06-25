#include<iostream>
#include "Exception.h"
using namespace std;

Exception::Exception(char* name, int line) {
	m_pStrName = new char[strlen(name) + 1];
	strcpy(m_pStrName, name);
	m_nLine = line;
}
Exception::~Exception() {
	delete[] m_pStrName;
}
char* Exception::GetName() {
	return m_pStrName;
}
int Exception::GetLine() {
	return m_nLine;
}
