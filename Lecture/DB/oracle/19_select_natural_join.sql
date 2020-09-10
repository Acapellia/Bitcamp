--natural join
--select column, column, ...
--from table1
--natural join table2
--where condition;
--a) ������ �̸�/Ÿ���� �÷��� ������ �� ���������� ������� �ʾƵ� �ڵ����� ã�Ƽ� ������ ���ش�.
--b) ���� �÷��� �ݵ�� �ϳ��� �����ؾ� �Ѵ�.
  -- �� �̻��� ���� ����� �� ���� using ���� ����ؾ� �Ѵ�.

--1) �ڿ� �������� �� ����� �ٹ� �μ��� �˻��϶�
select ename �̸�, dname �μ� from emp natural join dept;

select e.eno ���, ename �̸�, d.dno �μ���ȣ, dname �μ���
from emp e, dept d
where e.dno = d.dno;

--2) '����'���� �ٹ��ϴ� ������ ����� �˻��϶�(�μ���ȣ�� �μ��� �˻�)
SELECT loc �ٹ�ó, dno �μ���ȣ, dname �μ���, eno ���, ename �̸�
FROM emp
NATURAL JOIN dept
WHERE loc='����';

SELECT loc �ٹ�ó, dno �μ���ȣ, dname �μ���, eno ���, ename �̸�
FROM dept
NATURAL JOIN emp
WHERE loc='����';
   
   
--<USING ��>
--SELECT �÷�, �÷�, ...
--FROM ���̺�1
--JOIN ���̺�2 USING (���� �÷�)
--WHERE �˻�����;

--3) USING���� ����� JOIN���� �� ����� �ٹ� �μ��� �˻��϶�
select eno ���, ename �̸�, dno �μ���ȣ, dname �μ��� from emp join dept using(dno);   

--4) '����'���� �ٹ��ϴ� ������ ����� �˻��϶�(�μ���ȣ�� �μ��� �˻�)   
select loc �ٹ�ó, dno �μ���ȣ, dname �μ���, eno ���, ename �̸� from dept join emp using(dno) where loc = '����'; 

--5) ȭ�а� 1�г� �л����� '����ȭ��' ������ �˻��϶�
select *
from student join score using (sno) join course using (cno)
where major = 'ȭ��' and syear = 1 and cname = '����ȭ��'
order by result desc;

select *
from student natural join score natural join course
where major = 'ȭ��' and syear = 1 and cname = '����ȭ��'
order by result desc;



