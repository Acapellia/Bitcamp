<그룹함수와 Having 절>
; 그룹함수를 포함한 조건은 WHERE 절을 사용할 수 없다
  그래서 HAVING 절을 사용해야 한다
  일반 컬럼은 WHERE 절을 사용한다

1) 테이블의 sal 접근 이전에 WHERE sal >= 3000을 먼저 연산한다
 WHERE절 -> sal 접근
SELECT sal
FROM emp
WHERE sal >= 3000;

--2) 부서별 평균
--GROUP BY -> ROUND(AVG(sal)) -> ROUND(AVG(sal)) >= 3000
SELECT ROUND(AVG(sal))
FROM emp
GROUP BY dno;

--3) 업무별 평균
SELECT ROUND(AVG(sal))
FROM emp
GROUP BY job;

--4) 부서별 급여 평균이 3천 미만인 부서의 부서번호와 평균 급여를 검색하라
SELECT dno, ROUND(AVG(sal))
FROM emp
GROUP BY dno
HAVING AVG(sal) < 3000;

5) 부서별 인원수를 출력하세요(단, 업무가 개발이 아닌 인원만)
--select dno, count(*)
--from emp
--group by dno
--having job!='개발';

select dno, count(*)
from emp
where job!='개발'
group by dno;

6) 그룹 대상 컬럼과 검색
select dno, job, count(*) 인원수
from emp
group by dno, job
having job != '개발';

