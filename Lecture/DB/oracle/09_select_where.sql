-- order by column
--1) 사원중에 급여가 4000 이상인 사원을 검색하라
select eno 사번, ename 이름, sal 급여 from emp where sal>=4000;

--2) 이름이 '김연아'인 사원의 정보를 검색하라
select * from emp where ename = '김연아';

--3) 10번 부서를 제외한 사원의 명단을 검색하라
select ename 이름, dno 부서 from emp where dno != 10;
--dno는 varchar2 타입이므로 '10'으로 검색하지 않으면 대기업의 대용량 테이블의 경우 1행마다 형변환이 실행되므로 검색속도의 차이가 크게 난다.

--4) 연봉이 30,000 이상인 사원의 이름을 검색하라
select eno 사번, ename 이름,  sal*12+nvl(comm,0) 연봉 from emp where sal*12+nvl(comm,0) >= 30000;

--5) 보너스가 200 이하인 사원을 검색하라
select eno 사번, ename 이름, comm 보너스 from emp where comm<=200;

select eno 사번, ename 이름, comm 보너스 from emp where nvl(comm,0)<=200;

--6) 입사일이 1996년 이후인 사원의 정보를 검색하라
select * from emp where hdate > '1995/12/31';

-- alter session set nls_date_format='YYYY/MM/DD';
-- 날짜 포맷 변경

--7) 보너스 컬럼이 널 값인 사원을 검색하라
select * from emp where comm is null;

--8) 보너스 컬럼이 널이 아닌 사원을 검색하라
select * from emp where comm is not null;

