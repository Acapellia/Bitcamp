#include <stdio.h>
#include <stdlib.h>
#define PAN_SIZE 19
static int mx, my, mp;
static int nx, ny, np;
static int stone, white, black;
// �浹 : -1 - > 0��
// �鵹 : 0  - > 1��
int team01(int pan[][PAN_SIZE], int* px, int* py)
{
	if (*px == -1) {
		black = 1;  white = 0;
		if (*py == -1) { // ��
			mp = 0; np = 1; stone = 0; 
			*px = 10; *py = 10;
		}
		else if (*py == 0) {// ��
			mp = 1; np = 0; stone = 1;
		}
	}
	else {
		if (pan[nx][ny] == np) {
			int cnt,idx=0;
			int Acnt[5] = { 0 };
			int point[5][2] = { 0 };
			Acnt[4] = -1; point[4][0] = rand() % 19; point[4][1] = rand() % 19;
			// ����
			cnt = 1;
			for (int i = nx; i < PAN_SIZE; i++) {
				if (pan[nx][ny] == pan[i][ny]) { cnt++; }
				else if (pan[i][ny] == mp) { break; }
				else if (pan[i][ny] != white && pan[i][ny] != black) { point[0][0] = i; point[0][1] = ny; break; }
			}
			for (int i = nx; i >0; i--) {
				if (pan[nx][ny] == pan[i][ny]) { cnt++; }
				else if (pan[i][ny] == mp) { break; }
				else if (pan[i][ny] != white && pan[i][ny] != black) { point[0][0] = i; point[0][1] = ny; break; }
			}
			Acnt[0] = cnt;
			// ����
			cnt = 1;
			for (int i = ny; i < PAN_SIZE; i++) {
				if (pan[nx][ny] == pan[nx][i]) { cnt++; }
				else if (pan[nx][i] == mp) { break; }
				else if (pan[nx][i] != white && pan[nx][i] != black) { point[0][0] = nx; point[0][1] = i; break; }
			}
			for (int i = ny; i >= 0; i--) {
				if (pan[nx][ny] == pan[nx][i]) { cnt++; }
				else if (pan[nx][i] == mp) { break; }
				else if (pan[nx][i] != white && pan[nx][i] != black) { point[0][0] = nx; point[0][1] = i; break; }
			}
			Acnt[1] = cnt;

			// ����
			int temp = -999;
			for (int i = 0; i < 4; i++) {
				if (Acnt[i] > temp) { temp = Acnt[i]; idx = i; }
			}
			*px = point[idx][0]; *py = point[idx][1];
		}
	}
	// ������ ���۵Ǿ���.
	// ���� �浹�̴�.
	// ���� �鵹�̴�.
	// ��밡 ���� ��� �ξ��°�
	// ���� ��� ���� �� ���ΰ�
	return 0;
}
