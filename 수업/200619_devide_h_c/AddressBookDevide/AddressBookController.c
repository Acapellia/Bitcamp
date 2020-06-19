#pragma once
#include "turboc.h"
#include "AddressBookController.h"
#include "AddressBookView.h"
#include "AddressBookModel.h"

extern AddressBook addressBook[ADDR_NUM];	// 주소록 정보 저장 배열
extern int g_nAddrCnt;	   // 저장 인원수/다음 저장 위치

void inputAddress()
{
	AddressBook* pAddr = &addressBook[g_nAddrCnt];
	userInputAddress(pAddr);
	g_nAddrCnt++;
	printf("입력처리하였습니다~\n");
}

void searchAddress()
{
	char name[20] = { 0 };
	printf("검색할 이름 입력: ");
	fgets(name, sizeof(name) - 1, stdin);
	name[strlen(name) - 1] = 0;
	for (int i = 0; i < g_nAddrCnt; i++)
	{
		// 동명이인은 신경쓰지 않겠다.
		if (strncmp(name, addressBook[i].name,
			strlen(name)) == 0)	// 같다
		{
			showAddress(&addressBook[i]);
			break;
		}
	}
	printf("검색처리하였습니다~\n");
}

void updateAddress()
{
	char name[20] = { 0 };
	printf("수정할 이름 입력: ");
	fgets(name, sizeof(name) - 1, stdin);
	name[strlen(name) - 1] = 0;
	for (int i = 0; i < g_nAddrCnt; i++)
	{
		// 동명이인은 신경쓰지 않겠다.
		if (strncmp(name, addressBook[i].name,
			strlen(name)) == 0)	// 같다
		{
			printf("[수정할 데이터를 새로 입력]\n");
			userInputAddress(&addressBook[i]);
			showAddress(&addressBook[i]);
			break;
		}
	}
	printf("수정처리하였습니다~\n");
}

void deleteAddress()
{
	char name[20] = { 0 };
	printf("삭제할 이름 입력: ");
	fgets(name, sizeof(name) - 1, stdin);
	name[strlen(name) - 1] = 0;
	for (int i = 0; i < g_nAddrCnt; i++)
	{
		// 동명이인은 신경쓰지 않겠다.
		if (strncmp(name, addressBook[i].name,
			strlen(name)) == 0)	// 같다
		{
			showAddress(&addressBook[i]);
			printf("Really(Y/N)? ");
			char ch = getchar();
			getchar();			// '\n'값 삭제
			if (ch == 'Y' || ch == 'y')
			{
				for (int j = i + 1; j < g_nAddrCnt; j++)
				{
					addressBook[j - 1] = addressBook[j];
				}
				g_nAddrCnt--;
				printf("삭제처리하였습니다~\n");
			}
			break;
		}
	}
}

void printAllAddress()
{
	for (int i = 0; i < g_nAddrCnt; i++)
	{
		showAddress(&addressBook[i]);
	}
	printf("전체출력처리하였습니다~\n");
}

void exitApp()
{
	saveAddressBook();

	printf("프로그램 종료하겠습니다~\n");
}

int processWork(int selNum)
{
	int ret = 1;

	switch (selNum)
	{
	case INPUT_ADDR:
		inputAddress();
		break;
	case SEARCH_ADDR:
		searchAddress();
		break;
	case UPDATE_ADDR:
		updateAddress();
		break;
	case DELETE_ADDR:
		deleteAddress();
		break;
	case PRINTALL_ADDR:
		printAllAddress();
		break;
	case EXIT_ADDR:
		exitApp();
		ret = 0;
		break;
	default:
		printf("잘 못 입력하셨습니다!\n");
		break;
	}

	return ret;
}