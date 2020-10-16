--테이블 명 : 고객
--컬럼 : 고객관리번호, 고객명, 주소, 전화

drop table client;

create table client(
  cnum number,
  cname varchar2(50),
  addr varchar2(200),
  tel varchar2(20)
);