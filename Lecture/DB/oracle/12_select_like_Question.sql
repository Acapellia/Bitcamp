--1) �������� ������, �Ŀ��� �л��� �˻��϶�
select * from student where major='����' or major='�Ŀ�';
--2) ȭ�а��� �ƴ� �л��߿� 1�г� �л��� �˻��϶�
select * from student where major != 'ȭ��' and syear=1;
--3) �����а� 3�г� �л��� �˻��϶�
select * from student where major = '����' and syear=3;
--4) ������ 2.0���� 3.0������ �л��� �˻��϶�
select * from student where avr>=2.0 and avr<=3.0;
--5) ������ �������� ���� �����߿� ������ 3������ ������ �˻��϶�
select * from course where pno is null and st_num=3;
--6) ȭ�а� ���õ� ������ ������ 2���� ������ ������ �˻��϶�
select * from course where st_num<=2 and cname like '%ȭ��%';
--7) ȭ�а� �������� �˻��϶�
select * from professor where section='ȭ��' and orders = '������';
--8) �����а� �л��߿� ���� �縶���� �л��� �˻��϶�
select * from student where major='����' and sname like '�縶%';
--9) �������� 1995�� ������ �������� �˻��϶�
select * from professor where hiredate<'1995/01/01' and orders='������';
--10) ���� �̸��� ���� 1������ ������ �˻��϶�
select * from professor where pname like '__';