--���ĵ� ������ �˻�
--select [distinct | all] column, column, ...
--from table
--order by column [asc/desc], ...;

--1) ����� �̸��� �޿� ������ �˻�
select eno ���, ename �̸�, sal �޿� from emp order by sal desc;

--2) ����� ����� �̸��� ���� ������ �˻�
select eno ���, ename �̸� from emp order by sal*12+nvl(comm,0) desc;

select eno ���, ename �̸�, sal*12+nvl(comm,0) ���� from emp order by ���� desc;

select eno ���, ename �̸�, sal*12+nvl(comm,0) ���� from emp order by 3 desc;
-- column�� 1���� ����

--������ �̿��� ���� �˻�

--3) �������� ����� ������ �˻�
select job ����, eno ���, ename �̸�, sal �޿� from emp order by ����;

--4) �� �μ����� ����� �޿��� �˻� / �޿��� ���� �޴� ������� �˻�
select dno �μ���ȣ, eno ���, ename �̸�, sal �޿� from emp order by �μ���ȣ asc, �޿� desc ;


