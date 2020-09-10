--정렬된 데이터 검색
--select [distinct | all] column, column, ...
--from table
--order by column [asc/desc], ...;

--1) 사원의 이름을 급여 순으로 검색
select eno 사번, ename 이름, sal 급여 from emp order by sal desc;

--2) 사원의 사번과 이름을 연봉 순으로 검색
select eno 사번, ename 이름 from emp order by sal*12+nvl(comm,0) desc;

select eno 사번, ename 이름, sal*12+nvl(comm,0) 연봉 from emp order by 연봉 desc;

select eno 사번, ename 이름, sal*12+nvl(comm,0) 연봉 from emp order by 3 desc;
-- column은 1부터 시작

--정렬을 이용한 묶음 검색

--3) 업무별로 사원의 연봉을 검색
select job 업무, eno 사번, ename 이름, sal 급여 from emp order by 업무;

--4) 각 부서별로 사원의 급여를 검색 / 급여를 많이 받는 사람부터 검색
select dno 부서번호, eno 사번, ename 이름, sal 급여 from emp order by 부서번호 asc, 급여 desc ;


