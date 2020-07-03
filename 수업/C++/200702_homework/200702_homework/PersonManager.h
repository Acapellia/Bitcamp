#pragma once
#include "Telinfo.h"
class PersonManager
{
private:
	Person* per;   // Person�� �����迭�� �����ϴ� ������ ����
	int pnum;      // ���� �����ο��� ��Ÿ���� ����
public:
    PersonManager();
    PersonManager(int n);
    Person* getPersonArr();
    int* getPnum();
    void ShowMenu();
    void InsertTelInfo(Person* par, int* pnum);
    void DeleteTelInfo(Person* par, int* pnum);
    void SearchTelInfo(Person* par, int num);
    void PrintAll(Person* par, int num);
    void ClearScreen();
};

