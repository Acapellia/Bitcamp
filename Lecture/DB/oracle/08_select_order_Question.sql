--1) ���������� �л��� �̸��� �˻��϶�
select sname �̸�, avr ���� from student order by avr desc;
--2) �а��� ���������� �л��� ������ �˻��϶�
select major �а�, sno �й�, sname �̸�, avr ����  from student order by major, avr desc;
--3) �г⺰ ���������� �л��� ������ �˻��϶�
select syear �г�, sno �й�, sname �̸�, major �а�, avr ����  from student order by syear, avr desc;
--4) �а��� �г⺰�� �л��� ������ ���������� �˻��϶�
select major �а�, syear �г�, sno �й�, sname �̸�, avr ����  from student order by major, syear, avr desc;
--5) ���������� ���� �̸��� �˻��϶�
select cname ����, st_num ���� from course order by st_num desc;
--6) �� �а����� ������ ������ �˻��϶�
select section �а�, pname �����̸� from professor order by section;
--7) �������� ������ ������ �˻��϶�
select orders ����, pname �����̸�, section �а� from professor order by orders;
--8) �� �а����� ������ ������ �������� ������ �˻��϶�
select section �а�, pname �����̸� ,orders ����, hiredate "��������" from professor order by section, HIREDATE;