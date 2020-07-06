// 헤더파일이 중복으로 include되면 에러가 발생한다
// 아래처럼 처리하면 중복이 발생하지 않는다.
// 원래 방식
/*#ifndef _ADDRESSBOOKDEFINE_H__
#define _ADDRESSBOOKDEFINE_H__
#endif*/
// visual studio c++ 방식(다른곳 안됨)
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