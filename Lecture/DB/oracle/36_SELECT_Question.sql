--1) ȭ�а� �л��� ������ ������ �л����� �˻��ϼ���
select *
from student 
where avr in (select distinct avr from student where major = 'ȭ��') and major != 'ȭ��';

--2) ȭ�а� ������ �������� ���� ������ �˻��ϼ���
select *
from emp
where hdate in (select distinct hiredate from professor where section = 'ȭ��');

--3) ȭ�а� �л��� ���� �г⿡�� ������ ������ �л����� �˻��ϼ���
select *
from student 
where syear in (select syear from student where major = 'ȭ��')
and avr in (select avr from student where major = 'ȭ��');