--select * from human
--INSERT INTO Human values('5','����','010-7777-8888','���� ���ϱ�')
--INSERT INTO Human values('6','����','010-5656-8787','���� ���ϱ�')
--INSERT INTO Human values('7','����','010-1952-7686','���� ���ϱ�')
--INSERT INTO Human values('8','����','010-6776-3758','���� ������')
--INSERT INTO Human values('9','����','010-6876-3578','�λ� ����')
--INSERT INTO Human values('10','������','010-9327-3931','�λ� �ؿ��')
--select * from human where name='����'

--update human set Name='����' where name='����'
--select * from human

create table address(
	cnum varchar(50) primary key,
	name varchar(50),
	phone varchar(50),
	addr varchar(50),
	post varchar(50)
)
drop table address