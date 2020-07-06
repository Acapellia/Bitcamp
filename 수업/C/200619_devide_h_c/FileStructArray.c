#include<stdio.h>

#define ST_NUM 3
typedef struct _Student {
	char name[20];
	char addr[30];
	int age;
	double height, weight;
}Student;
void main()
{
	FILE* fp = NULL;
	fopen_s(&fp, "student.bin", "wb");

	Student st[ST_NUM] = { 0 };
	for (int i = 0; i < ST_NUM; i++) {
		printf("이름 주소 나이 키 몸무게를 입력하세요 : ");
		scanf("%s %s %d %lf %lf", st[i].name, st[i].addr, &st[i].age, &st[i].height, &st[i].weight);
	}
	fwrite(&st, sizeof(Student), 3, fp);

	fclose(fp);

	fp = NULL;
	fopen_s(&fp, "student.bin", "rb");
	Student rst[ST_NUM] = {0};
	fread(&rst, sizeof(Student), 3, fp);
	for (int i = 0; i < ST_NUM; i++) {
		printf("%s %s %d %.1lf %.1lf\n", rst[i].name, rst[i].addr, rst[i].age, rst[i].height, rst[i].weight);
	}
	fclose(fp);
}