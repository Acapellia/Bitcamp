--<등가조인과 비등가조인>
--SELECT 테이블1.컬럼, ... 테이블2.컬럼, ...
--FROM 테이블1, 테이블2, ...
--WHERE 조인조건
--AND 일반조건;
--a) 조인조건에 '='를 사용하는 것을 등가조인
--   부등호를 사용하는 것을 비등가조인이라 한다

--1) 각 사원의 근무 부서를 검색한다
select ename, dname from emp, dept where emp.dno = dept.dno;  

--2) 부산에서 근무하는 직원의 명단(부서번호와 부서명도 검색)
select loc 근무처, dept.dno 부서번호, dname 부서명, eno 사번, ename 이름 
from dept, emp
where dept.dno = emp.dno and loc='부산';

select loc 근무처, d.dno 부서번호, dname 부서명, eno 사번, ename 이름 
from dept d, emp e
where d.dno = e.dno and loc='부산';

--3) 각 직원의 급여 등급을 검색
select ename 이름, grade "급여 등급" from emp e ,salgrade sg where e.sal between sg.losal and sg.hisal; 
select ename 이름, grade "급여 등급" from emp e ,salgrade sg where e.sal >= sg.losal and  e.sal <= sg.hisal;

--4) 각 직원의 급여를 10% 인상한 경우 급여 등급을 검색
select ename 이름, sal 급여, (sal+sal*0.1) "인상한 급여", grade "급여 등급" from emp e ,salgrade sg where (e.sal + e.sal*0.1) between sg.losal and sg.hisal;

--5) 잘못된 조인 문장
select d.dno, dname, e.dno, ename from dept d, emp e;
-- join 조건이 없으면 모든 행이 1:1 대응된 Catersian Product을 얻게 된다.
-- cross join은 일반적으로 잘못된 결과이다.


















