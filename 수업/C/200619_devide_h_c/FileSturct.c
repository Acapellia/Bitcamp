#include<stdio.h>
typedef struct _Student {
	char name[20];
	char addr[30]; 
	int age;
	float height, weight;
}Student;
void main()
{
	FILE* fp = NULL;
	fopen_s(&fp, "student.bin", "wb");
	
	Student st = {"ȫ�浿","������ ��ä", 24, 174.5f,75.5f};
	fwrite(&st, sizeof(st), 1, fp);
	
	fclose(fp);

	fp = NULL;
	fopen_s(&fp, "student.bin", "rb");
	Student rst;
	fread(&rst, sizeof(rst), 1, fp);
	printf("%s %s %d %.1lf %.1lf", rst.name, rst.addr, rst.age, rst.height, rst.weight);
	fclose(fp);
}