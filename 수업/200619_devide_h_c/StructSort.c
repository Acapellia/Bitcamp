#include<stdio.h>
// ��ó�������� 1����Ʈ ������ 
#pragma pack(push,1)
typedef struct st1 {
	char ch, ch2;
	short s;
	int i;
}St1;
#pragma pack(pop)
#pragma pack(push,1)
typedef struct st2 {
	char ch;
	short s;
	int i;
	char ch2;
}St2;
#pragma pack(pop)
void main()
{

}