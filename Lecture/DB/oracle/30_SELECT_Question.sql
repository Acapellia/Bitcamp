--1) 3�г� �л��� �а��� ���� ��հ� �л� �� ������ �˻��ϼ���
select major �а�, avg(avr) ���, trunc(stddev(avr),3) ����, trunc(variance(avr),3) �л�
from student
where syear=3
group by major;

--2) ȭ�а� �г⺰ ��� ������ �˻��ϼ���
select syear �г�, avg(avr) ���
from student
where major = 'ȭ��'
group by syear;

--3) �� �л��� �⸻��� ����� �˻��ϼ���
select st.sno �й�, sname �̸�, avg(result) ���
from student st, score sr
where st.sno = sr.sno
group by st.sname, st.sno;

--4) �� �а��� �л� ���� �˻��ϼ���
select major �а�, count(sno)
from student
group by major;

--5) ȭ�а��� �����а� �л� 4.5 ȯ�� ������ ����� ���� �˻��ϼ���
select major �а�, trunc(avg(avr*4.5/4.0),3) ���
from student
where major = 'ȭ��' or major = '����'
group by major;

--6) �������� 10�� �̻� �� ���޺�(������, ������, �α���) ������ ���� �˻��ϼ���
select orders ����, count(pno)
from professor
where trunc(sysdate - hiredate)>=3650
group by orders;

--7) ����� ȭ���� ���Ե� ������ ������ ������ �˻��ϼ���
select sum(st_num) ��������
from course
where cname like '%ȭ��%';


--8) ȭ�а� �л����� �⸻��� ������ ���������� �˻��ϼ���
select sno �й�, sname �̸�, avr ����
from student
where major = 'ȭ��'
order by avr;

--9) �а��� �⸻��� ����� ���������� �˻��ϼ���
select major �а�, trunc(avg(avr),2)
from student
group by major
order by avg(avr);

