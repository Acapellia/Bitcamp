/*
������ �̿��� �˻�
select column as "����"
from table;
*/

-- 1) �� ����� �̸��� �������� �˻��϶�(���� ������ �ݵ�� "")
select eno as "���", ename as �̸�, job ���� from emp;

-- 2) �� ����� �޿��� 1�Ⱓ �����ϴ� �޿��� �˻��϶�
select eno ���, ename �̸�, sal*12 "�Ⱓ �޿�" from emp;

-- 3) �� ����� ������ �˻��϶�(12���� �޿� + ���ʽ�(comm))
select eno ���, ename �̸�, sal �޿�, comm ���ʽ�, sal*12+comm ���� from emp;