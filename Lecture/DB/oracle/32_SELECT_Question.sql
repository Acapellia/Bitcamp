--1) ȭ�а��� �����ϰ� �л����� ���� ����� �˻��ϼ���
select major �а�, trunc(avg(avr),2) ���
from student
--where major != 'ȭ��'
group by major
having major != 'ȭ��';

--2) ȭ�а��� ������ �� �а��� ��� ���� �߿� ������ 2.0 �̻��� ������ �˻��ϼ���
select major �а�, trunc(avg(avr),2) ���
from student
--where major != 'ȭ��'
group by major
having major != 'ȭ��' and trunc(avg(avr),2) >= 2.0;

--3) �⸻��� ����� 60�� �̻��� �л��� ������ �˻��ϼ���(�й��� �⸻��� ���)
select sno �й�, trunc(avg(result),2) ���
from score
group by sno
having trunc(avg(result),2) >= 60;

--4) ���� �������� 3���� �̻��� ������ ������ �˻��ϼ���(������ȣ, �̸��� ��� ������)
select pno ����, pname �����̸�,  cname ����, sum(st_num) �������
from professor natural join course
group by pno, pname, cname
having sum(st_num) >= 3;

--<������ ����>
--1) �׻� �����ϵ��� ����� ��(�̼����� ����)
--   �̼Ҵ� ������ �ſ� ������
--   (���� ��Ȳ���� ������ ã������ ����ϴ� ���)
--2) �����ϰ� �����ϴ� ����� �� ��(�ݼ�)
--3) ���� �Ͼ ��(����)
--4) �ǰ��� ��(����)
--5) �׻� ȣ����� ���� ��(���, ����)