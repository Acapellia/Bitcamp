--���Ῥ������ ���
--select column || literal || ...
--from table


-- 1) ����� �̸��� �޿� �Ǵ� ������ �Բ� �˻�
select ename ||' '|| sal "�̸�_�޿�" from emp;

select ename || '�� ������' || job || '�Դϴ�.' ������ from emp;

-- 2) �����ؾ� �� ���Ῥ���� -> �켱���� ����
select ename || ' ' || (sal+100) "�̸�_�޿�+100" from emp;

--�ߺ�����
--select [distinct | all] column, column, ... from tabel

--3) ���� ���� �˻�
select  job ���� from emp;
select distinct job ���� from emp;

