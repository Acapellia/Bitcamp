#include "Human.h"
#include "ComputerEngineer.h"
#include "Developer.h"
#include "ServerManager.h"
// 오버로딩 : 같은이름(매개변수, 리턴형 다름)으로 여러 기능
// 오버라이딩 : 함수 재정의(함수형이 같음)으로 여러 기능
void main()
{
	Developer dev("홍길동", 24, 3, 12);
	dev.overTime();
	dev.info();
	dev.neverEndingStudy();
	dev.sleep();
}