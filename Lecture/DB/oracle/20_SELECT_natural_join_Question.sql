--1) �۰� ������ �����ϴ� ������ �˻��Ѵ�
select * from professor natural join course where pname='�۰�';

--2) ȭ�� ���� ������ �����ϴ� ������ ����� �˻��Ѵ�
select pno ������ȣ, pname �����̸�, cname ���� from professor natural join course where cname like '%ȭ��%';

--3) ������ 2������ ����� �̸� �����ϴ� ������ �˻��Ѵ�
select pno ������ȣ, pname �����̸�, cname ���� from professor natural join course where st_num=2;

--4) ȭ�а� ������ �����ϴ� ������ �˻��Ѵ�
select pno ������ȣ, pname �����̸�, cname ���� from professor natural join course where section = 'ȭ��';

--5) ȭ�а� 1�г� �л��� �⸻��� ������ �˻��Ѵ�
select sno �й�, sname �̸�, result ���� from student natural join score where major='ȭ��' and syear = 1 order by result desc;

--6) �Ϲ�ȭ�� ������ �⸻��� ������ �˻��Ѵ�
select sno �й�, sname �̸�, result ���� from student natural join score natural join course where cname = '�Ϲ�ȭ��';

--7) ȭ�а� 1�г� �л��� �Ϲ�ȭ�� �⸻��� ������ �˻��Ѵ�
select sno �й�, sname �̸�, result ���� from student natural join score natural join course where cname = '�Ϲ�ȭ��' and major = 'ȭ��' and syear = 1;

--8) ȭ�а� 1�г� �л��� �����ϴ� ������ �˻��Ѵ�
select distinct cname ���� from student natural join score natural join course where major = 'ȭ��' and syear = 1;