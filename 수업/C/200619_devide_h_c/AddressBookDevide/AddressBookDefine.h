// ��������� �ߺ����� include�Ǹ� ������ �߻��Ѵ�
// �Ʒ�ó�� ó���ϸ� �ߺ��� �߻����� �ʴ´�.
// ���� ���
/*#ifndef _ADDRESSBOOKDEFINE_H__
#define _ADDRESSBOOKDEFINE_H__
#endif*/
// visual studio c++ ���(�ٸ��� �ȵ�)
#pragma once

#define ADDR_NUM	100

enum {
	INPUT_ADDR = 1,
	SEARCH_ADDR,
	UPDATE_ADDR,
	DELETE_ADDR,
	PRINTALL_ADDR,
	EXIT_ADDR
};

typedef struct _AddressBook
{
	char name[20];
	char address[30];
	int age;
	float height;
	float weight;
}AddressBook;