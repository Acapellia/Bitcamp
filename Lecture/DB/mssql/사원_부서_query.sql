--select * from emp

--select * from emp, dept where emp.dno=dept.dno;

--select * from emp join dept on emp.dno=dept.dno;

--select ename from emp join dept on emp.dno=dept.dno and loc='�λ�';

-- ȸ��μ� ����� �˻�
select ename from emp, dept where emp.dno=dept.dno and dept.dname='ȸ��';

-- ������ '�𵨸�'�� ����� �μ� ������ �˻�
select ename, dept.* from emp join dept on emp.dno=dept.dno and job='�𵨸�';