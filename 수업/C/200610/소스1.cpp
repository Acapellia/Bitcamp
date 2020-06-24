#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <Windows.h>
#include <time.h>

#define WallH   22 // 행
#define WallC   22 // 열
#define EnemyCountt   3 //적 개수

int mapBack[WallH][WallC] = { 0 };
int mapWall[WallH][WallC] = { 0 };    // 벽을 세워야 되는 맵 읽기
const int MapWallH = 1;
const int MapWallH2 = 21;


int ShowMap(void)
{
    system("cls");

    for (int r = 1; r < WallH; ++r) // 행 : H
    {
        for (int c = 1; c < WallC; ++c) // 열 : W
        {
            mapWall[MapWallH][c] = -1; // 벽 행렬에 5 넣기
            mapWall[MapWallH2][c] = -1; ////
        }
        mapWall[r][MapWallH] = -1; // 벽 열에 5 넣기
        mapWall[r][MapWallH2] = -1; ////
    }

    for (int r = 1; r < WallH; ++r) // 행 : H
    {
        for (int c = 1; c < WallC; ++c) // 열 : W
        {
            printf("%s", (mapWall[r][c] == -1) ? "■" : "□");
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


        for (int r = 1; r < WallH; ++r) // 벽 안만 리필
        {
            for (int c = 1; c < WallC; ++c) // 벽 안만 리필
            {
                printf("%s", (mapWall[r][c] == 9) ? "◈" :
                    (mapWall[r][c] == -1) ? "■" :
                    (mapWall[r][c] == 2) ? "♣" : "□");
            }
            putchar('\n');
        }

        if (_kbhit())
        {
            char ch = _getch(); // 보이지 않는 입력

            if (ch == '\r')
            {
                break;
            }

            if (ch == 'w' || ch == 'W') // 위
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
            if (ch == 's' || ch == 'S') // 아
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
            if (ch == 'a' || ch == 'A') // 왼
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
            if (ch == 'd' || ch == 'D') // 오
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