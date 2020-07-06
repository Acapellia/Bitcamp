// 시간차를 이용한 서로 다른 움직임
// 시분할
#include "turboc.h"
void init()
{
	setcursortype(NOCURSOR);
	clrscr();
}
// clock_t == long 
// clock() : cpu로부터 현재 시간을 ms로 얻어온다.
// static 지역 변수 : 
// 지역에 위치해 있지만 소속은 프로그램 소속
// 프로그램이 생성될 때 메모리에 로딩되고
// 프로그램이 소멸될 때 메모리에서 사라진다
clock_t runFirst(char* str, clock_t delaytime, clock_t preTime)	   // #을 움직임
{
	static int xpos0 = 0, ypos0 = 6;
	static int dir0 = 1;
	gotoxy(xpos0, ypos0);
	printf(str);
	if (clock() - preTime >= delaytime)
	{
		gotoxy(xpos0, ypos0);
		printf("      ");
		xpos0 += dir0;
		if (xpos0 == 0 || xpos0 == 80)
			dir0 *= -1;
		preTime = clock();
	}
	return preTime;
}
clock_t runSecond(char* str, clock_t delaytime, clock_t preTime)	// @을 움직임
{
	static int xpos1 = 0, ypos1 = 12;
	static int dir1 = 1;
	gotoxy(xpos1, ypos1);
	printf(str);
	if (clock() - preTime >= delaytime)
	{
		gotoxy(xpos1, ypos1);
		printf("      ");
		xpos1 += dir1;
		if (xpos1 == 0 || xpos1 == 80)
			dir1 *= -1;
		preTime = clock();
	}
	return preTime;
}
clock_t runThird(char* str, clock_t delaytime, clock_t preTime)	// @을 움직임
{
	static int xpos2 = 0, ypos2 = 18;
	static int dir2 = 1;
	gotoxy(xpos2, ypos2);
	printf(str);
	if (clock() - preTime >= delaytime)
	{
		gotoxy(xpos2, ypos2);
		printf("      ");
		xpos2 += dir2;
		if (xpos2 == 0 || xpos2 == 80)
			dir2 *= -1;
		preTime = clock();
	}
	return preTime;
}
void main2()
{
	init();
	clock_t preTime0 = clock();
	clock_t preTime1 = clock();
	clock_t preTime2 = clock();
	while (1)
	{
		preTime0 = runFirst("▣▣▶", 10L, preTime0);	// 100ms -> 0.1초마다 움직임
		preTime1 = runSecond("★☆@", 20L, preTime1); // 200ms -> 0.2초마다 움직임
		preTime2 = runThird("◎♧♡", 30L, preTime2); // 200ms -> 0.2초마다 움직임
	}
}