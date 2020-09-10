#pragma once
class Exception {
private :
	char* m_pStrName;
	int m_nLine;
public:
	Exception(char* name, int line);
	virtual ~Exception();
public:
	char* GetName();
	int GetLine();
};