--1) ȭ�а� �л��� �˻��϶�
select * from student where major = 'ȭ��';
--2) ������ 2.0 �̸��� �л��� �˻��϶�
select * from student where avr<2.0;
--3) ���� �л��� ������ �˻��϶�
select sname �̸�, avr ���� from student where sname = '����';
--4) ������ ����� �˻��϶�
select pname �����̸� from professor where orders='������';
--5) ȭ�а� �Ҽ� ������ ����� �˻��϶�
select pname �����̸� from professor where section = 'ȭ��';
--6) �۰� ������ ������ �˻��϶�
select * from professor where pname = '�۰�';
--7) �г⺰�� ȭ�а� �л��� ������ �˻��϶�
select syear �г�, sname �̸�, major �а�, avr ���� from student where major='ȭ��'; 
--8) 2000�� ������ ������ ������ ������ �����ϼ����� �˻��϶�
select * from professor where hiredate<'20/12/31' order by hiredate ;
--9) ��� ������ ���� ������ ������ �˻��϶�
select * from course where pno is null;