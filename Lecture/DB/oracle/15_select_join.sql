--<����ΰ� ������>
--SELECT ���̺�1.�÷�, ... ���̺�2.�÷�, ...
--FROM ���̺�1, ���̺�2, ...
--WHERE ��������
--AND �Ϲ�����;
--a) �������ǿ� '='�� ����ϴ� ���� �����
--   �ε�ȣ�� ����ϴ� ���� �������̶� �Ѵ�

--1) �� ����� �ٹ� �μ��� �˻��Ѵ�
select ename, dname from emp, dept where emp.dno = dept.dno;  

--2) �λ꿡�� �ٹ��ϴ� ������ ���(�μ���ȣ�� �μ��� �˻�)
select loc �ٹ�ó, dept.dno �μ���ȣ, dname �μ���, eno ���, ename �̸� 
from dept, emp
where dept.dno = emp.dno and loc='�λ�';

select loc �ٹ�ó, d.dno �μ���ȣ, dname �μ���, eno ���, ename �̸� 
from dept d, emp e
where d.dno = e.dno and loc='�λ�';

--3) �� ������ �޿� ����� �˻�
select ename �̸�, grade "�޿� ���" from emp e ,salgrade sg where e.sal between sg.losal and sg.hisal; 
select ename �̸�, grade "�޿� ���" from emp e ,salgrade sg where e.sal >= sg.losal and  e.sal <= sg.hisal;

--4) �� ������ �޿��� 10% �λ��� ��� �޿� ����� �˻�
select ename �̸�, sal �޿�, (sal+sal*0.1) "�λ��� �޿�", grade "�޿� ���" from emp e ,salgrade sg where (e.sal + e.sal*0.1) between sg.losal and sg.hisal;

--5) �߸��� ���� ����
select d.dno, dname, e.dno, ename from dept d, emp e;
-- join ������ ������ ��� ���� 1:1 ������ Catersian Product�� ��� �ȴ�.
-- cross join�� �Ϲ������� �߸��� ����̴�.


















