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
	int isRun = 1;	// 1�̸� �ݺ�, 0�̸� ����
	loadAddressBook();
	while (isRun)
	{
		viewMenu();						// 1. �޴� �����ֱ�
		selNum = getSelNum();			// 2. ����� �Է�
		isRun = processWork(selNum);	// 3. ó��
		laterProcess();					// 4. ��ó��
	}
}