--1) �Ϲ� ȭ�� ������ �����ϴ� �л��� ������ 4.5���� �������� �����ϼ���
update student
set avr = avr*4.5/4.0
where sno in (select st.sno from student st, score sr, course c where st.sno = sr.sno and sr.cno = c.cno and cname='�Ϲ�ȭ��');

select sno, sname, avr from student;
rollback;
select sno, sname, avr from student;

--2) ȭ�а� ������ ���� �߿� ������ 3���� �̸��� ������ ��� 3��������
--   ������ ���� �̸� Ȯ���ϼ���
select * from course;

update course
set st_num = 3
where cno in (select cno from course c natural join professor p where p.section = 'ȭ��');

select * from course;
rollback;

--3) �л��� �⸻��� ������ ��� st_score ���̺� �����ϼ���.
--  st_score���̺� ������ ���� �ľ��� ������
desc st_score;
insert /*+ append*/ into st_score nologging(sno,sname,major,syear,cno,cname,result)
select sno,sname,major,syear,cno,cname,result
from student s natural join score natural join course;
commit;
select * from st_score;
rollback;












