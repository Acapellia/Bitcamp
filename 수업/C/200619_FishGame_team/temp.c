#include "turboc.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#define DATA_NUM 50
#pragma warning(disable:4996)

enum {                                                                                      // 변경
    // 수강생 메뉴
    IN_BITCAMP = 1,
    OUT_BITCAMP,
    SEARCH_DATA,
    EXIT_1,
    // 관리자 메뉴
    UPDATE_DATA = 1,
    DELETE_DATA,
    ADD_DATA,
    ALL_DATA,
    EXIT_2
};

// 수강생 정보
typedef struct students {
    char name[30];   // 이름
    int tardy;      // 지각
    int absent;      // 결석
}Std;


Std _std[DATA_NUM] = {0};      // 수강생 구조체 배열
int stdCnt = 0;         // 수강생 인원수

// 선언부
void menu1();                           // 수강생 메뉴얼
void menu2();                           // 관리자 메뉴얼
int selFunction();                     // 원하는 기능의 번호를 입력받는 함수

int funcExecution1(int selFunction);   // 수강생의 기능을 가진 함수
time_t inBitcamp();                    // 출근                                                       // 변경
void outBitcamp(time_t b);             // 퇴근                                                       // 변경
void searchData();                     // 조회

int funcExecution2(int selFunction);   // 관리자의 기능을 가진 함수
void updateData();                     // 수정
void deleteData();                     // 삭제
void addData();                        // 추가

void saveData();
void showData();               // 전체보여주기 함수
void dataAll();                        // ??   


void menu1() {   // 수강생 메뉴

    printf("\t――――――――――\n");
    printf("\t｜｜1.    출근   ｜｜\n");
    printf("\t｜｜2.    퇴근   ｜｜\n");
    printf("\t｜｜3.    조회   ｜｜\n");
    printf("\t｜｜4.    종료   ｜｜\n");
    printf("\t――――――――――\n\n");

}

void menu2() {   // 관리자 메뉴

    printf("\t――――――――――\n");
    printf("\t｜｜1.    수정   ｜｜\n");
    printf("\t｜｜2.    삭제   ｜｜\n");
    printf("\t｜｜3.    추가   ｜｜\n");
    printf("\t｜｜4.  전체조회 ｜｜\n");
    printf("\t｜｜5.    종료   ｜｜\n");
    printf("\t――――――――――\n\n");

}

int selFunction() {   // 원하는 기능 입력
    int num = 0;
    printf("원하는 기능을 입력해주세요 >> ");
    scanf_s("%d", &num);
    getchar();

    return num;
}

int funcExecution1(int selFunction) {   // 사용자 기능 고르기
    static time_t b = 0;                                                                // 추가, static붙여서 없어지는거 막음
    switch (selFunction) {
    case IN_BITCAMP:
        b = inBitcamp();                                                                // 변경
        break;
    case OUT_BITCAMP:
        outBitcamp(b);                                                                  // 변경
        break;
    case SEARCH_DATA:
        dataAll();
        //searchData();
        break;
    case EXIT_1:
        return 0;
        break;
    default:
        printf("잘못입력하셨습니다. 다시 입력해주세요.\n");
        break;
    }
    return 1;
}

int funcExecution2(int selFunction) {   // 관리자 기능 고르기

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
        printf("잘못입력하셨습니다. 다시 입력해주세요.\n");
        break;
    }
}

time_t inBitcamp() {                                                                     // 변경

    int a = 0;
    int tadry_ = 1;
    time_t ttime = 0;                                                                    // 추가
    time_t* tm_hour = 0;                                                                 // 추가

    while (1) {

        printf("\n");
        printf("출근기록 기능입니다.\n\n");

        time_t t = time(NULL);
        struct tm tm = *localtime(&t);

        printf("현재시각 : %d-%d-%d %d:%d:%d\n",
            tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday,
            tm.tm_hour, tm.tm_min, tm.tm_sec);

        ttime = tm.tm_hour;                                                              // 추가


        Std std_ = {0};
        //std_ = &_std[stdCnt];
        printf("이름 입력: ");
        fgets(std_.name, sizeof(std_.name), stdin);
        std_.name[strlen(std_.name) - 1] = '\0';

        
        printf("출근하시겠습니까? (YES = 1 / NO = 0)\n");
        scanf_s("%d", &a);

        if (a == 1) {
            int ts = 0;
            if (tm.tm_hour <= 9) {
                printf("정상출근하셨습니다. 출근중입니다\n");
                break;
            }
            if (tm.tm_hour > 9) {
                printf("지각하셨습니다. 분발하세요\n");
                
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
            return ttime;                                                               // 추가
        }

        if (a == 0) {
            break;
        }

    }
}

void outBitcamp(time_t b) {                                                              // 변경

    time_t intime = b;                                                                  // 추가

    while (1) {

        int a = 0;

        printf("\n");
        printf("퇴근기록 기능입니다.\n\n");

        time_t t = time(NULL);
        struct tm tm = *localtime(&t);

        printf("현재시각 : %d-%d-%d %d:%d:%d\n",
            tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday,
            tm.tm_hour, tm.tm_min, tm.tm_sec);

        // 본인의 이름을 묻는 출력문
        // 본인의 이름이 저장된 파일에 있는지 확인해야함.


        printf("퇴근하시겠습니까? (YES = 1 / NO = 0)\n");
        scanf_s("%d", &a);

        if (a == 1) {

            time_t outtime = tm.tm_hour;                                                // 현재 퇴근할 때 시간
            time_t result = outtime - intime;                                           // 퇴근시간 - 출근시간
            if (result < 5) {                                                           // 변경
                printf("시간이 충분하지 않습니다. 결석입니다\n");
                break;
            }
            if (outtime - intime >= 5) {                                                   // 변경
                printf("어디 아픈가봐요?. 조퇴입니다\n");
                break;
            }
            if (outtime - intime >= 9) {                                                   // 변경
                printf("정상퇴근하셨습니다. 퇴근중입니다\n");
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
    printf("조회 기능입니다.\n\n");
}


void updateData() {
    printf("\n");
    printf("수정 기능입니다.\n\n");
}

void deleteData() {
    printf("\n");
    printf("삭제 기능입니다.\n\n");
}

void addData() {

    Std* std_ = NULL;
    std_ = &_std[stdCnt];
    printf("이름 입력: ");
    fgets(std_->name, sizeof(std_->name), stdin);
    std_->name[strlen(std_->name) - 1] = '\0';
    stdCnt++;

    FILE* fp = NULL;
    fopen_s(&fp, "students.txt", "a+t");
    printf("추가할 수강생 이름을 입력해주세요 : ");                                       // 추가
    fputs(std_->name, fp);
    fputc('\n', fp);
    fclose(fp);

    printf("\n");
    printf("수강생 정보가 추가되었습니다.\n\n");

}


void showData() {
    for (int i = 0; i < stdCnt; i++) {
        printf("\n--------------------------\n");
        printf("이름 : %s\n", _std[i].name);
        printf("지각횟수 : %d\n", _std[i].tardy);
        printf("결석횟수 : %d\n", _std[i].absent);
        printf("\n--------------------------\n");
    }

}

void dataAll() {
     showData();
}

void main() {

    int selNum1 = 0;

    int runTime = 1;      // 1이면 반복, 0이면 종료
    int x = 0;            // 수강생 & 관리자 구분 변수
    char ch = 0;

    int a = 0;            // 비밀번호를 입력받는 함수
    int passWord = 1234;   // 임의지정 패스워드
    int isPassword = 0;      // 패스워드 통과여부 변수

    printf("비트캠프 출결관리 프로그램입니다 ! \n");
    printf("본인이 수강생이면 1(수강생) / 관리자면 2(관리자) 번을 입력해주세요 : ");
    scanf_s("%d", &x);

    while (runTime) {

        if (x == 1) {      // 수강생
            menu1();
            selNum1 = selFunction();
            runTime = funcExecution1(selNum1);
        }

        if (x == 2) {      // 관리자

            if (isPassword == 0)
            {
                printf("비밀번호 입력하세요 : ");

                scanf_s("%d", &a);
                if (a == passWord)
                    isPassword = 1;      // 비밀번호가 한번 통과되면 그뒤로 else 구문을 계속해서 실행
                else {
                    printf("비밀번호 틀렸습니다 !\n");
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