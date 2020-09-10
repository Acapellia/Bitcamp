--natural join
--select column, column, ...
--from table1
--natural join table2
--where condition;
--a) 동일한 이름/타입의 컬럼이 존재할 때 조인조건을 명시하지 않아도 자동으로 찾아서 조인을 해준다.
--b) 공통 컬럼은 반드시 하나만 존재해야 한다.
  -- 둘 이상인 경우는 사용할 수 없고 using 절을 사용해야 한다.

--1) 자연 조인으로 각 사원의 근무 부서를 검색하라
select ename 이름, dname 부서 from emp natural join dept;

select e.eno 사번, ename 이름, d.dno 부서번호, dname 부서명
from emp e, dept d
where e.dno = d.dno;

--2) '광주'에서 근무하는 직원의 명단을 검색하라(부서번호와 부서명도 검색)
SELECT loc 근무처, dno 부서번호, dname 부서명, eno 사번, ename 이름
FROM emp
NATURAL JOIN dept
WHERE loc='광주';

SELECT loc 근무처, dno 부서번호, dname 부서명, eno 사번, ename 이름
FROM dept
NATURAL JOIN emp
WHERE loc='광주';
   
   
--<USING 절>
--SELECT 컬럼, 컬럼, ...
--FROM 테이블1
--JOIN 테이블2 USING (조인 컬럼)
--WHERE 검색조건;

--3) USING절을 사용한 JOIN으로 각 사원의 근무 부서를 검색하라
select eno 사번, ename 이름, dno 부서번호, dname 부서명 from emp join dept using(dno);   

--4) '서울'에서 근무하는 직원의 명단을 검색하라(부서번호와 부서명도 검색)   
select loc 근무처, dno 부서번호, dname 부서명, eno 사번, ename 이름 from dept join emp using(dno) where loc = '서울'; 

--5) 화학과 1학년 학생들의 '유기화학' 점수를 검색하라
select *
from student join score using (sno) join course using (cno)
where major = '화학' and syear = 1 and cname = '유기화학'
order by result desc;

select *
from student natural join score natural join course
where major = '화학' and syear = 1 and cname = '유기화학'
order by result desc;



