/*
<���� ���� ����>
1. #define��, enum��, ����ü�� h(�������)�� ����� �ű��.
2. ������ ������Ͽ��� #pragma once �ɼ��� �־�� �Ѵ�.
   �ش� �ɼ��� �ߺ� ���Ǹ� �������ش�.
3. ������ ��������� include ���ش�.
4. �Լ��� ����δ� h(�������)�� �����δ� c(�ҽ�����)�� �̵���Ų��.
5. c���Ͽ� �ش� h������ include�Ѵ�.
6. c���Ͽ� �����ϴ� ���������� �ٸ� ���Ͽ��� ����Ϸ��� extern Ű����� �������̾� �Ѵ�
   �ٸ� ���Ͽ��� ������ �ʱ�ȭ�� �ϸ� �ȵȴ�(���� �����ϴ� ������ �ν��ؼ� �ߺ� �������� ����)
*/

#include "addressDefine.h"

Address g_Address[ADDR_LEN];
int g_addrCnt = 0;

int main()
{
	int isRun = 1;
	loadAllAddress();
	while (isRun) {
		showMenu();
		int sel = selMenu();
		isRun = processAddress(sel);
	}
	return 0;
}



