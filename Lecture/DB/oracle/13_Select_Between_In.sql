--Between And Operator
--select column, column, ...
--from table
--where column between value1 and value2;
--�ش� column�� value1 value2 ����(value ����)�� �ִ��� �Ǵ�

--1) �޿��� 1000���� 2000���̿� �ִ� ��� 
select * from emp where sal between 1000 and 2000;

--2) 10��, 20�� �μ� ���
select * from emp where dno between 10 and 20;

--3) 1992�⿡�� 1996�� ���̿� �Ի��� ���
select * from emp where hdate between '1992/01/01' and '1996/12/31' order by hdate;
-- alter session set nls_date_format="YYYY/MM/DD:HH24/MI:SS";
--select * from emp where hdate between '1992/01/01:00:00:00' and '1996/12/31:23:59:59' order by hdate;

--4) �޿��� 2000���� 1000������ ���
select * from emp where sal between 2000 and 1000;
-- ������ �׻� ���� �;� �Ѵ�

--in operator
--select column, column, ...
--from table
--where column in (value1, value2, ...)
--order by column;
--������ �� �߿� ��ġ�ϴ� ���� �ϳ��� ������ �˻��ȴ�.

--5) �����̳� ���� ������ ����ϴ� ���
select * from emp where job in ('����', 'ȸ��') order by job;

--6) 10��, 20�� �μ����
select * from emp where dno in ('10', '20');
--select * from emp where dno = '10' or dno = '20';




























