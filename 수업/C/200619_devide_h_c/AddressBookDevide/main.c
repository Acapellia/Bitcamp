#pragma once
#include "AddressBookDefine.h"
#include "AddressBookModel.h"
#include "AddressBookView.h"
#include "AddressBookController.h"

AddressBook addressBook[ADDR_NUM];
int g_nAddrCnt = 0;

void main()
{
	int selNum = 0;
	int isRun = 1;	// 1이면 반복, 0이면 종료
	loadAddressBook();
	while (isRun)
	{
		viewMenu();						// 1. 메뉴 보여주기
		selNum = getSelNum();			// 2. 사용자 입력
		isRun = processWork(selNum);	// 3. 처리
		laterProcess();					// 4. 후처리
	}
}