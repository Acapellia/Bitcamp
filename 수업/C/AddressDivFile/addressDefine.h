#pragma once
#include<stdio.h>
#define ADDR_LEN 10
enum {
	INSERT = 1, PRINT = 2, EXIT = 3
};
typedef struct _Address {
	char name[20];
	char address[30];
	int age;
}Address;

void showMenu();
int selMenu();
void insertAddress();
void printAllAddress();
void saveAllAddress();
void loadAllAddress();
int processAddress(int sel);