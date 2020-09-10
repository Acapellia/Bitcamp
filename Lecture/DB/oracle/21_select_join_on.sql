--on ���� �̿��� ����
--select table1.column, ..., table2.column, ...
--from table 1 
--join table2 on JoinCondition
--where SearchCondition;
--a) ��� ������ ������ ǥ���� �� �ִ�.

--1) �� ����� �ٹ� �μ��� �˻��Ѵ�
select eno ���, ename �̸�, d.dno �μ���ȣ, dname �μ���
from emp e
join dept d on e.dno=d.dno;

--2) ���� ������ ����ϴ� ����� �޿� ���
select eno ���, ename �̸�, dname �μ���, grade "�޿� ���"
from emp
join salgrade on sal between losal and hisal
where job = '����';

--3) ������ �μ���� �޿� ����� �˻��Ѵ�
select eno ���, ename �̸�, dname �μ���, grade "�޿� ���"
from emp e
join dept d on e.dno=d.dno
join salgrade on sal between losal and hisal;

--<left/right outer join>
--+ ��ȸ�� �̿��ϴ� �ܺ� ������ �ٸ� ǥ����
--������ �ܺ������� ���ʿ��� +�� ���̴µ� 
--���⿡���� ��� +�� �߰��� �Ͱ� ������ ǥ���� �����ϴ�
--select table.column, ... table2.column, ...
--from table
--[left|right|full] [outer] join table2 [on condition | using (join column)]
--where SearchCondition;
--a) left : '���̺�1'�� ���� ���̺��̶� �θ��� ���� ���̺� �������ǰ� ��ġ���� ���� �൵ �˻��� �����Ѵ�.
--b) right : '���̺�2'�� ������ ���̺��̶� �θ��� ������ ���̺� �������ǰ� ��ġ���� ���� �൵ �˻��� �����Ѵ�.
--c) full : ���� ���̺� ��ο��� �������ǿ� ��ġ���� ���� ���� �˻��� �����Ѵ�. ���� (+) ��ȣ�� �̿��� �ܺ��������δ� �Ұ����� ǥ���̴�.
--d) on ���̳� using ���� ��� ����� �� �ִ�.

--4) ����� �̸��� �Ҽ� �μ��� �˻��϶�
SELECT eno ���, ename �̸�, dno �μ���ȣ, dname �μ���
FROM emp
RIGHT JOIN dept USING(dno);

SELECT eno ���, ename �̸�, dno �μ���ȣ, dname �μ���
FROM emp
RIGHT OUTER JOIN dept USING(dno);

SELECT eno ���, ename �̸�, dno �μ���ȣ, dname �μ���
FROM emp
LEFT JOIN dept USING(dno);

SELECT eno ���, ename �̸�, dno �μ���ȣ, dname �μ���
FROM emp
FULL JOIN dept USING(dno);
