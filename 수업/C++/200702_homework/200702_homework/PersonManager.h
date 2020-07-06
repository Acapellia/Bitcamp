#pragma once
#include "Telinfo.h"
class PersonManager
{
private:
	Person* per;   // Person의 동적배열을 저장하는 포인터 변수
	int pnum;      // 현재 저장인원을 나타내는 변수
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

