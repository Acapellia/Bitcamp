--자기참조조인(self join)
--자신의 테이블의 컬럼끼리 조인하는 것

--1) 각 사원을 관리하는 관리자의 이름을 검새갛라
select e1.eno 사번, e1.ename 이름, e1.mgr 관리자사번, e2.eno "관리자 사번", e2.ename "관리자 이름"
from emp e1, emp e2
where e1.mgr = e2.eno;

--2) 각 부서별로 사원을 검색한다
-- 일반 조인
select d.dno 부서번호, dname 부서명, ename 사원명
from dept d, emp e
where d.dno=e.dno
order by 1;

-- 외부조인
select d.dno 부서번호, dname 부서명, ename 사원명
from dept d, emp e
where d.dno=e.dno(+)
order by 1;
