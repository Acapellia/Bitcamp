/*
<파일 분할 절차>
1. #define문, enum형, 구조체를 h(헤더파일)을 만들어 옮긴다.
2. 생성된 헤더파일에는 #pragma once 옵션이 있어야 한다.
   해당 옵션은 중복 정의를 방지해준다.
3. 생성한 헤더파일을 include 해준다.
4. 함수의 선언부는 h(헤더파일)에 구현부는 c(소스파일)에 이동시킨다.
5. c파일에 해당 h파일을 include한다.
6. c파일에 존재하는 전역변수를 다른 파일에서 사용하려면 extern 키워드로 공유빋이야 한다
   다른 파일에서 공유시 초기화를 하면 안된다(새로 선언하는 것으로 인식해서 중복 선언으로 간주)
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



