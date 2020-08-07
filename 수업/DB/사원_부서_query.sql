--select * from emp

--select * from emp, dept where emp.dno=dept.dno;

--select * from emp join dept on emp.dno=dept.dno;

--select ename from emp join dept on emp.dno=dept.dno and loc='부산';

-- 회계부서 사원을 검색
select ename from emp, dept where emp.dno=dept.dno and dept.dname='회계';

-- 업무가 '모델링'인 사원과 부서 정보를 검색
select ename, dept.* from emp join dept on emp.dno=dept.dno and job='모델링';