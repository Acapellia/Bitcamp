-- order by column
--1) ����߿� �޿��� 4000 �̻��� ����� �˻��϶�
select eno ���, ename �̸�, sal �޿� from emp where sal>=4000;

--2) �̸��� '�迬��'�� ����� ������ �˻��϶�
select * from emp where ename = '�迬��';

--3) 10�� �μ��� ������ ����� ����� �˻��϶�
select ename �̸�, dno �μ� from emp where dno != 10;
--dno�� varchar2 Ÿ���̹Ƿ� '10'���� �˻����� ������ ������ ��뷮 ���̺��� ��� 1�ึ�� ����ȯ�� ����ǹǷ� �˻��ӵ��� ���̰� ũ�� ����.

--4) ������ 30,000 �̻��� ����� �̸��� �˻��϶�
select eno ���, ename �̸�,  sal*12+nvl(comm,0) ���� from emp where sal*12+nvl(comm,0) >= 30000;

--5) ���ʽ��� 200 ������ ����� �˻��϶�
select eno ���, ename �̸�, comm ���ʽ� from emp where comm<=200;

select eno ���, ename �̸�, comm ���ʽ� from emp where nvl(comm,0)<=200;

--6) �Ի����� 1996�� ������ ����� ������ �˻��϶�
select * from emp where hdate > '1995/12/31';

-- alter session set nls_date_format='YYYY/MM/DD';
-- ��¥ ���� ����

--7) ���ʽ� �÷��� �� ���� ����� �˻��϶�
select * from emp where comm is null;

--8) ���ʽ� �÷��� ���� �ƴ� ����� �˻��϶�
select * from emp where comm is not null;

