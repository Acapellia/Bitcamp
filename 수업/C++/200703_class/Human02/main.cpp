#include "Human.h"
#include "ComputerEngineer.h"
#include "Developer.h"
#include "ServerManager.h"
// �����ε� : �����̸�(�Ű�����, ������ �ٸ�)���� ���� ���
// �������̵� : �Լ� ������(�Լ����� ����)���� ���� ���
void main()
{
	Developer dev("ȫ�浿", 24, 3, 12);
	dev.overTime();
	dev.info();
	dev.neverEndingStudy();
	dev.sleep();
}