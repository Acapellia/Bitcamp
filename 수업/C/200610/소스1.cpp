#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <Windows.h>
#include <time.h>

#define WallH   22 // ��
#define WallC   22 // ��
#define EnemyCountt   3 //�� ����

int mapBack[WallH][WallC] = { 0 };
int mapWall[WallH][WallC] = { 0 };    // ���� ������ �Ǵ� �� �б�
const int MapWallH = 1;
const int MapWallH2 = 21;


int ShowMap(void)
{
    system("cls");

    for (int r = 1; r < WallH; ++r) // �� : H
    {
        for (int c = 1; c < WallC; ++c) // �� : W
        {
            mapWall[MapWallH][c] = -1; // �� ��Ŀ� 5 �ֱ�
            mapWall[MapWallH2][c] = -1; ////
        }
        mapWall[r][MapWallH] = -1; // �� ���� 5 �ֱ�
        mapWall[r][MapWallH2] = -1; ////
    }

    for (int r = 1; r < WallH; ++r) // �� : H
    {
        for (int c = 1; c < WallC; ++c) // �� : W
        {
            printf("%s", (mapWall[r][c] == -1) ? "��" : "��");
        }
        putchar('\n');
    }
    return 0;
}

int Move(void)
{
    int iy = 19, ix = 10;
    int biy = 0, bix = 0;
    int enemycount = 3;
    int stratEnemyLine = 2;
    srand(time(NULL));
    ShowMap();
    while (1)
    {
        system("cls");


        for (int r = 1; r < WallH; ++r) // �� �ȸ� ����
        {
            for (int c = 1; c < WallC; ++c) // �� �ȸ� ����
            {
                printf("%s", (mapWall[r][c] == 9) ? "��" :
                    (mapWall[r][c] == -1) ? "��" :
                    (mapWall[r][c] == 2) ? "��" : "��");
            }
            putchar('\n');
        }

        if (_kbhit())
        {
            char ch = _getch(); // ������ �ʴ� �Է�

            if (ch == '\r')
            {
                break;
            }

            if (ch == 'w' || ch == 'W') // ��
            {
                if (mapWall[iy - 1][ix] == -1)
                {

                }
                else
                {
                    mapWall[iy][ix] = 0;
                    --iy;
                }
            }
            if (ch == 's' || ch == 'S') // ��
            {
                if (mapWall[iy + 1][ix] == -1)
                {

                }
                else
                {
                    mapWall[iy][ix] = 0;
                    ++iy;
                }
            }
            if (ch == 'a' || ch == 'A') // ��
            {
                if (mapWall[iy][ix - 1] == -1)
                {

                }
                else
                {
                    mapWall[iy][ix] = 0;
                    --ix;
                }
            }
            if (ch == 'd' || ch == 'D') // ��
            {
                if (mapWall[iy][ix + 1] == -1)
                {

                }
                else
                {
                    mapWall[iy][ix] = 0;
                    ++ix;
                }
            }

            mapWall[iy][ix] = 9;

            
            static int movecount = 0;


            for (int i = 0; i < enemycount; ++i)
            {
                int o = rand() % 20 + 1;
                mapWall[stratEnemyLine][o] = 2;
            }
            if (movecount != 0)
            {
                for (int r = WallH; r > MapWallH - 1; --r)
                {
                    for (int c = WallC; c > MapWallH - 1; --c)
                    {
                        if (mapWall[r][c] == 2)
                        {
                            if (mapWall[r + 1][c] == -1)
                            {
                                mapWall[r][c] = 0;
                            }
                            else
                            {
                                mapWall[r][c] = 0;
                                mapWall[r + 1][c] = 2;
                                
                            }
                        }
                    }
                }
            }

            movecount = 1;
        }
    }
    printf("end drawMap()\n\n");
    return 0;
}

int main(int argc, char** argv)
{
    Move();
    return 0;
}