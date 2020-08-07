--select * from human
--INSERT INTO Human values('5','제니','010-7777-8888','서울 강북구')
--INSERT INTO Human values('6','수지','010-5656-8787','서울 강북구')
--INSERT INTO Human values('7','설현','010-1952-7686','서울 성북구')
--INSERT INTO Human values('8','쯔위','010-6776-3758','서울 강남구')
--INSERT INTO Human values('9','정현','010-6876-3578','부산 서면')
--INSERT INTO Human values('10','아이유','010-9327-3931','부산 해운대')
--select * from human where name='제니'

--update human set Name='종혁' where name='정현'
--select * from human

create table address(
	cnum varchar(50) primary key,
	name varchar(50),
	phone varchar(50),
	addr varchar(50),
	post varchar(50)
)
drop table address