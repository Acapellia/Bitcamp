--1) dept 테이블의 모든 데이터를 삭제한 다음 rollback과 commit을 수행하고 결과를 확인하세요
select * from dept; 
delete from dept;
select * from dept; 
rollback;
select * from dept; 

--2) emp와 dept 테이블의 모든 데이터를 삭제 완료하세요
select * from emp;
select * from dept;
delete from emp;
delete from dept;
select * from emp;
select * from dept;
commit;

--3) emp 테이블에 값들을 입력하세요
insert into emp(eno,ename,job,mgr,hdate,sal,comm,dno)
values ('1001','김연아','개발',NULL,'1991-02-01',4500,520,10);
select * from emp;
rollback;
select * from emp;

--4) emp 테이블에 데이터를 입력하되 입사일에 날짜와 시간도 입력하세요
select sysdate from dual;
--date는 날짜 형식이 일치해야 입력된다.
--insert into emp(eno,ename,hdate)
--values ('5001','홍길동','199-01-03:07:15:25');

alter session set nls_date_format = 'YYYY-MM-DD:HH24:MT:SS';
insert into emp(eno,ename,hdate)
values ('5001','홍길동','199-01-03:07:15:25');

--5) 날짜 형식을 확인하고 to_date()를 사용해서 입력하라
alter session set nls_date_format = 'YYYY-MM-DD';
select sysdate from dual;
alter session set nls_date_format = 'YY-MM-DD';
select sysdate from dual;
alter session set nls_date_format = 'YY/MM/DD';
select sysdate from dual;

insert into emp(eno, ename, hdate)
values ('5002','장나라',to_date('1992-02-03:07:07:07','YYYY-MM-DD:HH24:MT:SS'));
select * from emp;
select eno, ename, to_char(hdate,'YYYY-MM-DD:HH24:MT:SS') from emp;

--6) 날짜에 적용되는 디폴트 값을 확인한다.
alter session set nls_date_format='YYYY-MM-DD:HH24:MT::SS';
insert into emp(ebi,hdate) values ('1',to_date('2000','YYYY'));
insert into emp(ebi,hdate) values ('3',to_date('99','YY'));
insert into emp(ebi,hdate) values ('4',to_date('99','RR')); -- 가까운 년도
commit;
select * from emp;

--7) 김연아의 부서번호를 10번으로 수정하고 급여를 10퍼 인상하세요
select * from emp;
update emp set dno='10', sal = sal*1.1 where ename='김연아';
select * from emp where ename='김연아';
commit;


























