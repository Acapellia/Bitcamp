--<���� �� �Լ��� ����ϼ���>
--1) �̸��� �� ������ �л��� �̸��� �˻��ϼ���
select sname from student where length(sname) = 2;
--2) '��'�� ���� ���� �л��� �̸��� �˻��ϼ���
select sname from student where substr(sname,1,1) = '��';
--3) ������ ������ �ѱ��ڷ� �˻��ϼ���(ex. ������ -> ��)
select pname �����̸�, substr(orders,1,1) ���� from professor;
--4) �Ϲ� ������ ���� �������� �����ؼ� ��� ������ �˻��ϼ���
--   (ex. �Ϲ�ȭ�� -> ����ȭ��)
select cname "���� ������", replace(cname,'�Ϲ�','����') "���� ������" from course;
--5) ���� �Է� �Ǽ��� student���̺��� sname�÷��� �����Ͱ� �Էµ� ��
--   ���ڿ� �������� ������ �߰��Ǿ��ٸ� �˻��� �� �̸� �����ϰ�
--   �˻��ϴ� SELECT ���� �ۼ��ϼ���
select replace(sname,' ','') �̸�, length(replace(sname,' ','')) ���� from student;
select trim(trailing ' ' from sname) from student;