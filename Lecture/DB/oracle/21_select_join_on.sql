--on 절을 이용한 조인
--select table1.column, ..., table2.column, ...
--from table 1 
--join table2 on JoinCondition
--where SearchCondition;
--a) 모든 형태의 조인을 표현할 수 있다.

--1) 각 사원의 근무 부서를 검색한다
select eno 사번, ename 이름, d.dno 부서번호, dname 부서명
from emp e
join dept d on e.dno=d.dno;

--2) 지원 업무를 담당하는 사원의 급여 등급
select eno 사번, ename 이름, dname 부서명, grade "급여 등급"
from emp
join salgrade on sal between losal and hisal
where job = '지원';

--3) 직원의 부서명과 급여 등급을 검색한다
select eno 사번, ename 이름, dname 부서명, grade "급여 등급"
from emp e
join dept d on e.dno=d.dno
join salgrade on sal between losal and hisal;

--<left/right outer join>
--+ 기회를 이용하는 외부 조인의 다른 표현법
--이전의 외부조인은 한쪽에만 +를 붙이는데 
--여기에서는 모두 +를 추가한 것과 동일한 표현이 가능하다
--select table.column, ... table2.column, ...
--from table
--[left|right|full] [outer] join table2 [on condition | using (join column)]
--where SearchCondition;
--a) left : '테이블1'을 왼쪽 테이블이라 부르고 왼쪽 테이블에 조인조건과 일치하지 않은 행도 검색헤 포함한다.
--b) right : '테이블2'를 오른쪽 테이블이라 부르고 오른쪽 테이블에 조인조건고 일치하지 않은 행도 검색에 포함한다.
--c) full : 양쪽 테이블 모두에서 조인조건에 일치하지 않은 행을 검색에 포함한다. 이전 (+) 기호를 이용한 외부조인으로는 불가능한 표현이다.
--d) on 절이나 using 절을 모두 사용할 수 있다.

--4) 사원의 이름과 소속 부서를 검색하라
SELECT eno 사번, ename 이름, dno 부서번호, dname 부서명
FROM emp
RIGHT JOIN dept USING(dno);

SELECT eno 사번, ename 이름, dno 부서번호, dname 부서명
FROM emp
RIGHT OUTER JOIN dept USING(dno);

SELECT eno 사번, ename 이름, dno 부서번호, dname 부서명
FROM emp
LEFT JOIN dept USING(dno);

SELECT eno 사번, ename 이름, dno 부서번호, dname 부서명
FROM emp
FULL JOIN dept USING(dno);
