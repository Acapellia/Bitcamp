 
 --1)student ���̺� ������ �˻��ض�(��ٵ�)
desc student;

-- 2)course ���̺� ������ �˻��ض�
desc course;

-- 3)professor ���̺� ������ �˻��ض�
desc PROFESSOR;

-- 4)score ���̺� ������ �˻��ض�
desc SCORE;

-- 5) ��� �л��� ������ �˻��ض�
select * from student;

-- 7) ��� ������ ������ �˻��ض�
select * from course;

-- 8) �⸻��� ���������� �˻��ض�
select * from st_score;

-- 9) �л����� �а��� �г��� �˻��ض�
select sno, sname, major, syear from student;

-- 10) �� ������ �̸��� ������ �˻��ض�
select cname, st_num from course;

-- 11) ��� ������ ������ �˻��ض�
select pno, pname, orders from professor;
 
 