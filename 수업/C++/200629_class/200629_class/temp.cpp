#include <stdio.h>
#include <iostream>
#include <cstring>
using namespace std;
void main()
{
    getchar();
    char nameAge0[30];                                 // 배열1 선언
    char nameAge1[30];                                 // 배열2 선언

    printf("이름과 나이를 띄어쓰기로 구분해서 입력: ");
    fgets(nameAge0, sizeof(nameAge0) - 1, stdin);            // 사용자한테 키보드입력받음/ 널값공간을 남겨둘려고
    nameAge0[strlen(nameAge0) - 1] = 0;                     // 마지막 문자를 널문자로 만듬

    printf("이름과 나이를 띄어쓰기로 구분해서 입력: ");
    fgets(nameAge1, sizeof(nameAge1) - 1, stdin);
    nameAge1[strlen(nameAge1) - 1] = 0;

    char name0[30] = { 0 };
    char age0[10] = { 0 };
    int cnt0 = 0;
    int flag0 = 0;   //0이면 이름, 1이면 나이
    for (int i = 0; i < strlen(nameAge0) + 1; i++)
    {
        if (nameAge0[i] != 0x20)   // ' '                     // 스페이스바가 아니면 if문으로
        {
            if (flag0 == 0)                                 // 스페이스바가 아니면서 문자면
                name0[cnt0++] = nameAge0[i];                     // i번째 배열의 문자를 name배열에 넣는다.
            else if (flag0 == 1)                              // 스페이스바가 아니면서 숫자면
            {
                age0[cnt0++] = nameAge0[i];                     // i번째 배열의 숫자를 age배열에 넣는다.
            }
        }
        else {                                          // 스페이스바를 만났다면
            flag0 = 1;                                    // 문자가 끝나고 다음으로 age(숫자)를 받을차례기 때문에
            name0[cnt0] = 0;                                 // name(문자)배열의 끝. 널값추가
            cnt0 = 0;                                    // age에서 숫자를 카운트하기위해 초기화
        }
    }

    char name1[30] = { 0 };
    char age1[10] = { 0 };
    int cnt1 = 0;
    int flag1 = 0;   //0이면 이름, 1이면 나이
    for (int i = 0; i < strlen(nameAge1) + 1; i++)
    {
        if (nameAge1[i] != 0x20)   // ' '
        {
            if (flag1 == 0)
                name1[cnt1++] = nameAge1[i];
            else if (flag1 == 1)
            {
                age1[cnt1++] = nameAge1[i];
            }
        }
        else {
            flag1 = 1;
            name1[cnt1] = 0;
            cnt1 = 0;
        }
    }

    if (strlen(nameAge0) != strlen(nameAge1))
    {
        return;
    }
    int namecnt = 0;
    int agecnt = 0;
    int g = 0;
    for (int i = 0; i < strlen(nameAge1) + 1; i++)
    {
        if (g == 0)
        {
            if (name0[i] == name1[i])
            {
                if (namecnt == strlen(name1))
                {
                    g = 1; i = -1;
                }
                namecnt++;
                continue;
            }
            else if (name0[i] != name1[i])
            {
                printf("두 문자열은 불일치합니다. ");
                break;
            }
        }

        if (g == 1)
        {
            cout << age0[i] << " " <<age1[i] << endl;
            if (age0[i] == age1[i])
            {
                if (agecnt == strlen(age1))
                {
                    printf("두 문자열은 일치합니다. ");
                }
                agecnt++;
                continue;
            }
            else if (age0[i] != age1[i])
            {
                printf("두 문자열은 불일치합니다. ");
                break;
            }
        }
    }
}