--1) �� ������ ������ ��� ������ �������� �˻��϶�
select cname ����, pname ��米�� from professor p join course c on p.pno = c.pno;

--2) ȭ�а� �л��� �⸻��� ������ ��� �˻��϶�
select sname �л��̸�, cname ����, result ���� from student st join score sr on st.sno = sr.sno join course c on c.cno=sr.cno 
where major = 'ȭ��'; 

--3) ����ȭ�а��� �������� �⸻��� ���������� �˻��϶�
--4) ȭ�а� �л��� �����ϴ� ������ ����ϴ� ������ ����� �˻��϶�
--5) ��� ������ ��ܰ� ��� ������ �˻��Ѵ�
--6) ��� ������ ��ܰ� ��� ������ �˻��Ѵ�(�� ��� ���� ���� �˻��Ѵ�)