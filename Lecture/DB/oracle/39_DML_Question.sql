--1) ��� �л��� ������ 4.5���� �������� �����ϼ���
select sname, avr from student;
update student set avr=avr*4.5/4.0;
select sname, avr from student;
rollback;
select sname, avr from student;
--2) ��� ������ �������ڸ� 100�� ������ �����ϼ���
select pname, hiredate from professor;
update professor set hiredate = hiredate - 100;
select pname, hiredate from professor;
rollback;
--3) ȭ�а� 2�г� �л��� ������ �����ϼ���
delete from student where major='ȭ��' and syear = 2 ;
select * from student;
rollback;
--4) �������� ������ �����ϼ���
delete from professor where orders='������';
select * from professor;
rollback;