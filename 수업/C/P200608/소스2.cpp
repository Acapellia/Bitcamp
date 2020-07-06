#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<windows.h>
#include<algorithm>
#include<string.h>

struct Dict {
	char key[10] = {0};
	char value[10] = {0};
};
int main() {
	char str[100] = "{'name' : 'jangs', 'type' : '10', 'alpha' : 'abcde', 'color' : 'white', 'animal' : 'dog'}";
	char text[10][100] = {0};
	struct Dict dict[20];

	int s = 0, e = 0, state = 0, count = 0;;
	printf("%s\n", str);
	for (int i = 0; i < strlen(str); i++) {
		
		if (state == 0 && str[i] == '\'') {
			state = 1; s = i;
		}
		if (state == 1 && (str[i] == ',' || str[i]=='}') ) {
			state = 0; e = i;
			strncpy(text[count], (str + s), e - s); text[count][e-s] = 0;
			count++;
			if (str[i] == '}') { break; }
		}
		
	}
	printf("------------------------------------------------------------\n");
	char Ans[20][100] = { 0 };
	s = 0; e = 0; state = 0;
	int ac = 0, dc=0;

	for (int i = 0; i < count; i++) {
		s = 0;
		for (int j = 0;; j++) {
			if (text[i][j] == ':' && state==0) { 
				e = j; 
				strncpy(Ans[ac], (text[i] + s), e - s); Ans[ac][e - s] = 0; 
				strncpy(dict[dc].key, Ans[ac], strlen(Ans[ac]));
				ac++; state = 1; continue;
			}

			if (text[i][j] != ' ' && state == 1) {
				s = j; e = strlen(text[i]);
				strncpy(Ans[ac], (text[i] + s), e - s); Ans[ac][e] = 0; 
				strncpy(dict[dc++].value, Ans[ac], strlen(Ans[ac]));
				state = 0; ac++; break;
			}
		}
	}
	for (int i = 0; i < dc; i++)
		printf("{ key : %s value : %s }\n",dict[i].key,dict[i].value);
	return 0;
}

/*void string_array();
void string_loop();
void string_pointer();
void string_dynamic();
char* toString() {
	char* name = (char*)malloc(sizeof(name)*80);
	strncpy(name,"lost",80);
	return name;
}
void getString(char* param,int size) {
	int i;
	for (i = 0; i < size-1; i++) {
		param[i] = '0'+i;
	}
	param[i] = 0;
}
int main4()
{
	// 문자열 3개를 입력받아 출력하세요.
	char* p = toString();
	//char* p = (char*)malloc(sizeof(char *));
	if (p == NULL) {
		printf("문자열이 없다.\n");
	}
	else {
		printf("%s\n", p);
		free(p);
	}
	getString(p, 80);
	printf("%s", p);
	return 0;
}*/

/*void string_array() {
	char s1[80], s2[80], s3[80];
	printf("string > ");
	scanf("%s %s %s", s1, s2, s3);
	// fgets(s1,sizeof(s1),stdin);
	printf("s1 : %s\n", s1);
	printf("s2 : %s\n", s2);
	printf("s3 : %s\n", s3);
}
void string_loop() {
	char list[5][80] = { 0 };

	for (int i = 0; i < 5; i++) {
		printf("string : ");
		scanf("%s", list[i]);

	}
}
void string_pointer() {
	char* p1[5];
	char s[5][80];
	// p1[0] = s[0];
	for (int i = 0; i < 5; i++) {
		printf("string : ");
		p1[i] = (char*)malloc(sizeof(char) * 80);
		scanf("%s", p1[i]);
	}
	for (int i = 0; i < 5; i++) {
		printf("str%d : %s\n", i + 1, p1[i]);
		free(p1[i]);
	}
}
void string_dynamic() {
	char** ap = NULL;
	int count = 0;
	printf("문자열 입력 개수 : ");
	scanf("%d", &count);
	ap = (char**)malloc(sizeof(*ap) * count);
	for (int i = 0; i < count; i++) {
		printf("string : ");
		ap[i] = (char*)malloc(sizeof(char*) * count);
		scanf("%s", ap[i]);
		printf("%s\n", ap[i]);
	}
	free(ap);
}*/

/*
#pragma pack(1)
typedef struct _Fileheader {
	char data[14];
}BFH;
typedef struct _Infoheader {
	char data[40];
}BIH;
typedef struct _RGB {
	char data[3];
}RGB;
typedef struct _bmpImage {
	BFH fh;
	BIH ih;
	RGB* table;
}BMP;
int main3()
{
	BMP bmp = { 0 };
	//RGB pixel[512];
	//bmp.table = pixel;
	int countsOfpixel = 1024 * 768;


	bmp.table = (RGB*)malloc(countsOfpixel * sizeof(RGB));
	free(bmp.table);
	return 0;
}*/

// 동적할당
/*int main02()
{
	int length = 60;
	char* p = (char*)malloc(length * sizeof(char));
	
	for (int i = 0; i < length; i++) {
		p[i] = 'a' + 1;
	}
	length = length * 200 * sizeof(char);
	
	p = (char *)realloc(p, length * 200 * sizeof(char));

	if (p != NULL) {
		free(p);
		p = NULL;
	}
	return 0;
}*/

// 포인터와 구조체 (메모리 할당법이 같음)
/*struct Student {
	char name[80] = {0};
	int kor;
	int eng;
	int math;
};
int main1(int argc, char** argv)
{
	char student[80] = { 0 };
	char* name = student;
	int* kor = (int*)(student + 60);
	int* eng = (int*)(student + 64);
	int* math = (int*)(student + 68);
	int* score = (int *)(student + 60);

	scanf_s("%s %d %d %d", name, 60,score + 0, score + 1, score + 2);
	printf("%s :  { kor : %d / eng : %d / math : %d }\n",name,score[0],score[1],score[2]);
	return 0;
}*/