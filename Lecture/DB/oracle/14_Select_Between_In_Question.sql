--1) ������ 3.0���� 4.0������ �л��� �˻��϶�
select * from student where avr between 3.0 and 4.0;

--2) 1994�⿡�� 1995����� ������ ������ ����� �˻��϶�
select * from professor where hiredate between '1994/01/01' and '1995/12/31';

--3) ȭ�а��� �����а�, �����а� �л��� �˻��϶�
select * from student where major in ('ȭ��', '����', '����');

--4) �������� �������� �˻��϶�
select * from professor where orders in ('������', '������');

--5) �������� 1����, 2������ ������ �˻��϶�
select * from course where st_num in (1, 2);

--6) 1, 2�г� �л� �߿� ������ 2.0���� 3.0������ �л��� �˻��϶�
select * from student where (syear in (1, 2) and (avr between 2.0 and 3.0)) order by syear, avr;

--7) ȭ��, �����а� �л� �� 1, 2 �г� �л��� ���������� �˻��϶�
select * from student where (major in ('ȭ��', '����')) and (syear in (1, 2)) order by avr;
