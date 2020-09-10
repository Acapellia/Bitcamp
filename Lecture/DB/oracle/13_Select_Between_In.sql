--Between And Operator
--select column, column, ...
--from table
--where column between value1 and value2;
--해당 column이 value1 value2 사이(value 포함)에 있는지 판단

--1) 급여가 1000에서 2000사이에 있는 사원 
select * from emp where sal between 1000 and 2000;

--2) 10번, 20번 부서 사원
select * from emp where dno between 10 and 20;

--3) 1992년에서 1996년 사이에 입사한 사원
select * from emp where hdate between '1992/01/01' and '1996/12/31' order by hdate;
-- alter session set nls_date_format="YYYY/MM/DD:HH24/MI:SS";
--select * from emp where hdate between '1992/01/01:00:00:00' and '1996/12/31:23:59:59' order by hdate;

--4) 급여가 2000에서 1000사이의 사원
select * from emp where sal between 2000 and 1000;
-- 작은게 항상 먼저 와야 한다

--in operator
--select column, column, ...
--from table
--where column in (value1, value2, ...)
--order by column;
--지정된 값 중에 일치하는 값이 하나라도 있으면 검색된다.

--5) 개발이나 관리 업무를 담당하는 사원
select * from emp where job in ('개발', '회계') order by job;

--6) 10번, 20번 부서사원
select * from emp where dno in ('10', '20');
--select * from emp where dno = '10' or dno = '20';




























