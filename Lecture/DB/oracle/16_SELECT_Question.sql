--1) �۰� ������ �����ϴ� ������ �˻��Ѵ�
select cname from course c, professor p where c.pno = p.pno and pname='�۰�'; 

--2) ȭ�� ���� ������ �����ϴ� ������ ����� �˻��Ѵ�
select pname ����, cname ���� from course c, professor p where c.pno = p.pno and cname like '%ȭ��%';

--3) ������ 2������ ����� �̸� �����ϴ� ������ �˻��Ѵ�
select cname ����, pname ���� from course c, professor p where c.pno = p.pno and st_num = 2;

--4) ȭ�а� ������ �����ϴ� ������ �˻��Ѵ�
select cname ����, pname ���� from course c, professor p where c.pno = p.pno and section = 'ȭ��';

--5) ȭ�а� 1�г� �л��� �⸻��� ������ �˻��Ѵ�
select sname �̸�, syear �г�, major �а�, cname ����, result ���� 
from student st, score sc, course c 
where (st.sno = sc.sno and sc.cno = c.cno) and major='ȭ��' and syear=1;

--6) �Ϲ�ȭ�� ������ �⸻��� ������ �˻��Ѵ�
select sname �̸�, syear �г�, major �а�, cname ����, result ���� 
from student st, score sc, course c 
where (st.sno = sc.sno and sc.cno = c.cno) and cname = '�Ϲ�ȭ��';

--7) ȭ�а� 1�г� �л��� �Ϲ�ȭ�� �⸻��� ������ �˻��Ѵ�
select sname �̸�, syear �г�, major �а�, cname ����, result ���� 
from student st, score sc, course c 
where (st.sno = sc.sno and sc.cno = c.cno) and (cname = '�Ϲ�ȭ��' and major = 'ȭ��' and syear = 1);

--8) ȭ�а� 1�г� �л��� �����ϴ� ������ �˻��Ѵ�
select distinct cname ���� from course c, student st, score sc where (st.sno = sc.sno and sc.cno = c.cno) and (major = 'ȭ��' and syear = 1); 

--9) ����ȭ�� ������ �������� F�� �л��� ����� �˻��Ѵ�
select sname 
from (select sname, result, cname from course c, student st, score sc where st.sno = sc.sno and sc.cno = c.cno) temp 
where (temp.result < 40) and cname = '����ȭ��'; 


select sno �й�, sname �̸�, cname ����, result from student natural join course natural join score natural join scgrade 
where result between loscore and hiscore and grade = 'F' and cname = '����ȭ��' order by result desc;





