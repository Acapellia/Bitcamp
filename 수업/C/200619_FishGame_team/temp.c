#include "turboc.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#define DATA_NUM 50
#pragma warning(disable:4996)

enum {                                                                                      // ����
    // ������ �޴�
    IN_BITCAMP = 1,
    OUT_BITCAMP,
    SEARCH_DATA,
    EXIT_1,
    // ������ �޴�
    UPDATE_DATA = 1,
    DELETE_DATA,
    ADD_DATA,
    ALL_DATA,
    EXIT_2
};

// ������ ����
typedef struct students {
    char name[30];   // �̸�
    int tardy;      // ����
    int absent;      // �Ἦ
}Std;


Std _std[DATA_NUM] = {0};      // ������ ����ü �迭
int stdCnt = 0;         // ������ �ο���

// �����
void menu1();                           // ������ �޴���
void menu2();                           // ������ �޴���
int selFunction();                     // ���ϴ� ����� ��ȣ�� �Է¹޴� �Լ�

int funcExecution1(int selFunction);   // �������� ����� ���� �Լ�
time_t inBitcamp();                    // ���                                                       // ����
void outBitcamp(time_t b);             // ���                                                       // ����
void searchData();                     // ��ȸ

int funcExecution2(int selFunction);   // �������� ����� ���� �Լ�
void updateData();                     // ����
void deleteData();                     // ����
void addData();                        // �߰�

void saveData();
void showData();               // ��ü�����ֱ� �Լ�
void dataAll();                        // ??   


void menu1() {   // ������ �޴�

    printf("\t��������������������\n");
    printf("\t����1.    ���   ����\n");
    printf("\t����2.    ���   ����\n");
    printf("\t����3.    ��ȸ   ����\n");
    printf("\t����4.    ����   ����\n");
    printf("\t��������������������\n\n");

}

void menu2() {   // ������ �޴�

    printf("\t��������������������\n");
    printf("\t����1.    ����   ����\n");
    printf("\t����2.    ����   ����\n");
    printf("\t����3.    �߰�   ����\n");
    printf("\t����4.  ��ü��ȸ ����\n");
    printf("\t����5.    ����   ����\n");
    printf("\t��������������������\n\n");

}

int selFunction() {   // ���ϴ� ��� �Է�
    int num = 0;
    printf("���ϴ� ����� �Է����ּ��� >> ");
    scanf_s("%d", &num);
    getchar();

    return num;
}

int funcExecution1(int selFunction) {   // ����� ��� ����
    static time_t b = 0;                                                                // �߰�, static�ٿ��� �������°� ����
    switch (selFunction) {
    case IN_BITCAMP:
        b = inBitcamp();                                                                // ����
        break;
    case OUT_BITCAMP:
        outBitcamp(b);                                                                  // ����
        break;
    case SEARCH_DATA:
        dataAll();
        //searchData();
        break;
    case EXIT_1:
        return 0;
        break;
    default:
        printf("�߸��Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���.\n");
        break;
    }
    return 1;
}

int funcExecution2(int selFunction) {   // ������ ��� ����

    switch (selFunction) {
    case UPDATE_DATA:
        updateData();
        break;
    case DELETE_DATA:
        deleteData();
        break;
    case ADD_DATA:
        addData();
        break;
    case ALL_DATA:
        dataAll();
        break;
    case EXIT_2:
        return 0;
        break;
    default:
        printf("�߸��Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���.\n");
        break;
    }
}

time_t inBitcamp() {                                                                     // ����

    int a = 0;
    int tadry_ = 1;
    time_t ttime = 0;                                                                    // �߰�
    time_t* tm_hour = 0;                                                                 // �߰�

    while (1) {

        printf("\n");
        printf("��ٱ�� ����Դϴ�.\n\n");

        time_t t = time(NULL);
        struct tm tm = *localtime(&t);

        printf("����ð� : %d-%d-%d %d:%d:%d\n",
            tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday,
            tm.tm_hour, tm.tm_min, tm.tm_sec);

        ttime = tm.tm_hour;                                                              // �߰�


        Std std_ = {0};
        //std_ = &_std[stdCnt];
        printf("�̸� �Է�: ");
        fgets(std_.name, sizeof(std_.name), stdin);
        std_.name[strlen(std_.name) - 1] = '\0';

        
        printf("����Ͻðڽ��ϱ�? (YES = 1 / NO = 0)\n");
        scanf_s("%d", &a);

        if (a == 1) {
            int ts = 0;
            if (tm.tm_hour <= 9) {
                printf("��������ϼ̽��ϴ�. ������Դϴ�\n");
                break;
            }
            if (tm.tm_hour > 9) {
                printf("�����ϼ̽��ϴ�. �й��ϼ���\n");
                
                for (int i = 0; i < stdCnt; i++) {
                    if (!strcmp(_std[i].name, std_.name)) {
                        _std[i].tardy++; ts = 1; break;
                    }
                }
                printf("ts : %d\n", ts);
                if (ts == 0) {
                    _std[stdCnt].tardy++; strcpy(_std[stdCnt].name, std_.name);
                    printf("tardy : %d\n", _std[stdCnt].tardy);
                    stdCnt++;
                }
                /*std_[stdCnt].tardy += tadry_;
                printf("%d\n", std_[stdCnt].tardy);*/
               
                
                break;
            }
            return ttime;                                                               // �߰�
        }

        if (a == 0) {
            break;
        }

    }
}

void outBitcamp(time_t b) {                                                              // ����

    time_t intime = b;                                                                  // �߰�

    while (1) {

        int a = 0;

        printf("\n");
        printf("��ٱ�� ����Դϴ�.\n\n");

        time_t t = time(NULL);
        struct tm tm = *localtime(&t);

        printf("����ð� : %d-%d-%d %d:%d:%d\n",
            tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday,
            tm.tm_hour, tm.tm_min, tm.tm_sec);

        // ������ �̸��� ���� ��¹�
        // ������ �̸��� ����� ���Ͽ� �ִ��� Ȯ���ؾ���.


        printf("����Ͻðڽ��ϱ�? (YES = 1 / NO = 0)\n");
        scanf_s("%d", &a);

        if (a == 1) {

            time_t outtime = tm.tm_hour;                                                // ���� ����� �� �ð�
            time_t result = outtime - intime;                                           // ��ٽð� - ��ٽð�
            if (result < 5) {                                                           // ����
                printf("�ð��� ������� �ʽ��ϴ�. �Ἦ�Դϴ�\n");
                break;
            }
            if (outtime - intime >= 5) {                                                   // ����
                printf("��� ���°�����?. �����Դϴ�\n");
                break;
            }
            if (outtime - intime >= 9) {                                                   // ����
                printf("��������ϼ̽��ϴ�. ������Դϴ�\n");
                break;
            }
        }

        if (a == 0) {
            break;
        }

    }


}

void searchData() {
    printf("\n");
    printf("��ȸ ����Դϴ�.\n\n");
}


void updateData() {
    printf("\n");
    printf("���� ����Դϴ�.\n\n");
}

void deleteData() {
    printf("\n");
    printf("���� ����Դϴ�.\n\n");
}

void addData() {

    Std* std_ = NULL;
    std_ = &_std[stdCnt];
    printf("�̸� �Է�: ");
    fgets(std_->name, sizeof(std_->name), stdin);
    std_->name[strlen(std_->name) - 1] = '\0';
    stdCnt++;

    FILE* fp = NULL;
    fopen_s(&fp, "students.txt", "a+t");
    printf("�߰��� ������ �̸��� �Է����ּ��� : ");                                       // �߰�
    fputs(std_->name, fp);
    fputc('\n', fp);
    fclose(fp);

    printf("\n");
    printf("������ ������ �߰��Ǿ����ϴ�.\n\n");

}


void showData() {
    for (int i = 0; i < stdCnt; i++) {
        printf("\n--------------------------\n");
        printf("�̸� : %s\n", _std[i].name);
        printf("����Ƚ�� : %d\n", _std[i].tardy);
        printf("�ἮȽ�� : %d\n", _std[i].absent);
        printf("\n--------------------------\n");
    }

}

void dataAll() {
     showData();
}

void main() {

    int selNum1 = 0;

    int runTime = 1;      // 1�̸� �ݺ�, 0�̸� ����
    int x = 0;            // ������ & ������ ���� ����
    char ch = 0;

    int a = 0;            // ��й�ȣ�� �Է¹޴� �Լ�
    int passWord = 1234;   // �������� �н�����
    int isPassword = 0;      // �н����� ������� ����

    printf("��Ʈķ�� ������ ���α׷��Դϴ� ! \n");
    printf("������ �������̸� 1(������) / �����ڸ� 2(������) ���� �Է����ּ��� : ");
    scanf_s("%d", &x);

    while (runTime) {

        if (x == 1) {      // ������
            menu1();
            selNum1 = selFunction();
            runTime = funcExecution1(selNum1);
        }

        if (x == 2) {      // ������

            if (isPassword == 0)
            {
                printf("��й�ȣ �Է��ϼ��� : ");

                scanf_s("%d", &a);
                if (a == passWord)
                    isPassword = 1;      // ��й�ȣ�� �ѹ� ����Ǹ� �׵ڷ� else ������ ����ؼ� ����
                else {
                    printf("��й�ȣ Ʋ�Ƚ��ϴ� !\n");
                }
            }
            else
            {
                menu2();
                selNum1 = selFunction();
                runTime = funcExecution2(selNum1);
            }

        }

    }


}