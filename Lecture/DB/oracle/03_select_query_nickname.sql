/*
별명을 이용한 검색
select column as "별명"
from table;
*/

-- 1) 각 사원의 이름과 담당업무를 검색하라(공백 포함은 반드시 "")
select eno as "사번", ename as 이름, job 업무 from emp;

-- 2) 각 사원의 급여와 1년간 수급하는 급여를 검색하라
select eno 사번, ename 이름, sal*12 "년간 급여" from emp;

-- 3) 각 사원으 연봉을 검색하라(12개월 급여 + 보너스(comm))
select eno 사번, ename 이름, sal 급여, comm 보너스, sal*12+comm 연봉 from emp;