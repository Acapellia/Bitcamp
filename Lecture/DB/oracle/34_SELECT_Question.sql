--<���� ������ ����ϼ���>
--1) ���캸�� ������ ����� �л��� �й��� �̸��� �˻��ϼ���
select sno �й�, sname �̸� from student
where avr > (select avr from student where sname = '����');

--2) ����� ������ �г� �л� �߿� ������ �縶���� ������ �л��� �˻��ϼ���
select * from student
where syear = (select syear from student where sname = '����')
and avr = (select avr from student where sname = '�縶��');

--3) ���캸�� �Ϲ� ȭ�а����� ������ �� ���� �л��� ����� ������ �˻��ϼ���
select sname , avr, result 
from (select sname, avr, result from student natural join course natural join score where cname='�Ϲ�ȭ��')
where result < (select result from student natural join course natural join score where sname='����' and cname='�Ϲ�ȭ��')
order by sname;

--(select result from student natural join course natural join score where sname='����' and cname='�Ϲ�ȭ��');
--(select * from student natural join course natural join score where cname='�Ϲ�ȭ��');

--4) �ο����� ���� ���� �а��� �˻��ϼ���
select major �а�, count(sno) �ο���
from student
group by major
having count(sno) = (select max(count(sno)) from student group by major);

--5) �л� �� �⸻��� ������ ���� ���� �л��� ������ �˻��ϼ���
select *
from student
where avr = (select min(avr) from student);







