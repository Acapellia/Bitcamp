--�ڱ���������(self join)
--�ڽ��� ���̺��� �÷����� �����ϴ� ��

--1) �� ����� �����ϴ� �������� �̸��� �˻�����
select e1.eno ���, e1.ename �̸�, e1.mgr �����ڻ��, e2.eno "������ ���", e2.ename "������ �̸�"
from emp e1, emp e2
where e1.mgr = e2.eno;

--2) �� �μ����� ����� �˻��Ѵ�
-- �Ϲ� ����
select d.dno �μ���ȣ, dname �μ���, ename �����
from dept d, emp e
where d.dno=e.dno
order by 1;

-- �ܺ�����
select d.dno �μ���ȣ, dname �μ���, ename �����
from dept d, emp e
where d.dno=e.dno(+)
order by 1;
