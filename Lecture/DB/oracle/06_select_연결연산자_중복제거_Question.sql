--1) '__�а��� __�л��� ���� ������ __�Դϴ�' ���·� �л��� ������ ����϶�
select major || ' �а��� ' || sname || '�л��� ���� ������ ' || avr || '�Դϴ�.' as "����" from student;
--2) '__������ __���� �����Դϴ�.' ���·� ������ ������ ����϶�
select cname || ' ������ ' || st_num || '���� �����Դϴ�.' as "���� ����" from course;
--3) '__������ __�а� �Ҽ��Դϴ�.' ���·� ������ ������ ����϶�
select pname || ' ������ ' || section || ' �а� �Ҽ��Դϴ�.' as "���� �а�" from professor;
--4) �б����� � �а��� �ִ��� �˻��Ѵ�(�л� ���̺� ������� �˻��Ѵ�)
select distinct major as "�а�" from student;
--5) �б����� � �а��� �ִ��� �˻��Ѵ�(���� ���̺� ������� �˻��Ѵ�)
select distinct section as "�а�" from professor;
--6) ������ ������ � �͵��� �ִ��� �˻��Ѵ�
select distinct orders as "���� ����" from professor;