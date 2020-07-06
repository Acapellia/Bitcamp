#include "turboc.h"
/*
2개의 문자를 이동시키자
*/
void main()
{
	setcursortype(NOCURSOR);	// No 커서

	int x = 0, y = 0;
	for (x = 0, y = 0; y <= 40; x++)
	{
		gotoxy(x - 1, 12); puts(" ");
		gotoxy(x, 12); puts("#");
		if (x % 2 == 1) {
			gotoxy(y - 1, 13); puts(" ");
			gotoxy(y, 13); puts("*");
			y++;
		}
		delay(100);
	}
	gotoxy(0, 20);
}