#include <stdio.h>
#include <iostream>
#include <cstring>
using namespace std;
void main()
{
    getchar();
    char nameAge0[30];                                 // �迭1 ����
    char nameAge1[30];                                 // �迭2 ����

    printf("�̸��� ���̸� ����� �����ؼ� �Է�: ");
    fgets(nameAge0, sizeof(nameAge0) - 1, stdin);            // ��������� Ű�����Է¹���/ �ΰ������� ���ܵѷ���
    nameAge0[strlen(nameAge0) - 1] = 0;                     // ������ ���ڸ� �ι��ڷ� ����

    printf("�̸��� ���̸� ����� �����ؼ� �Է�: ");
    fgets(nameAge1, sizeof(nameAge1) - 1, stdin);
    nameAge1[strlen(nameAge1) - 1] = 0;

    char name0[30] = { 0 };
    char age0[10] = { 0 };
    int cnt0 = 0;
    int flag0 = 0;   //0�̸� �̸�, 1�̸� ����
    for (int i = 0; i < strlen(nameAge0) + 1; i++)
    {
        if (nameAge0[i] != 0x20)   // ' '                     // �����̽��ٰ� �ƴϸ� if������
        {
            if (flag0 == 0)                                 // �����̽��ٰ� �ƴϸ鼭 ���ڸ�
                name0[cnt0++] = nameAge0[i];                     // i��° �迭�� ���ڸ� name�迭�� �ִ´�.
            else if (flag0 == 1)                              // �����̽��ٰ� �ƴϸ鼭 ���ڸ�
            {
                age0[cnt0++] = nameAge0[i];                     // i��° �迭�� ���ڸ� age�迭�� �ִ´�.
            }
        }
        else {                                          // �����̽��ٸ� �����ٸ�
            flag0 = 1;                                    // ���ڰ� ������ �������� age(����)�� �������ʱ� ������
            name0[cnt0] = 0;                                 // name(����)�迭�� ��. �ΰ��߰�
            cnt0 = 0;                                    // age���� ���ڸ� ī��Ʈ�ϱ����� �ʱ�ȭ
        }
    }

    char name1[30] = { 0 };
    char age1[10] = { 0 };
    int cnt1 = 0;
    int flag1 = 0;   //0�̸� �̸�, 1�̸� ����
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
                printf("�� ���ڿ��� ����ġ�մϴ�. ");
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
                    printf("�� ���ڿ��� ��ġ�մϴ�. ");
                }
                agecnt++;
                continue;
            }
            else if (age0[i] != age1[i])
            {
                printf("�� ���ڿ��� ����ġ�մϴ�. ");
                break;
            }
        }
    }
}