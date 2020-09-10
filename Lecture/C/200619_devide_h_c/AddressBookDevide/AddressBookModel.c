#pragma once
#include "turboc.h"
#include "AddressBookDefine.h"

extern int g_nAddrCnt;
extern AddressBook addressBook[ADDR_NUM];

void saveAddressBook()
{
	FILE* fp = NULL;
	fopen_s(&fp, "addressBook.bin", "wb");
	fwrite(&g_nAddrCnt, sizeof(int), 1, fp);
	fwrite(addressBook, sizeof(AddressBook), g_nAddrCnt, fp);
	fclose(fp);
}

void loadAddressBook()
{
	FILE* fp = NULL;
	if (fopen_s(&fp, "addressBook.bin", "rb") == 0) {
		fread(&g_nAddrCnt, sizeof(int), 1, fp);
		fread(addressBook, sizeof(AddressBook), g_nAddrCnt, fp);
		fclose(fp);
	}
}