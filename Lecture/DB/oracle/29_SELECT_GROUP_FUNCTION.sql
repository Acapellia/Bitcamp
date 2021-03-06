--<그룹 함수>
--; 통계정보 계산시 자주 사용되는 함수
--보통 여러 개의 행에서 계산되거나 추출하는 값을 제공하는 함수
--a) 
--MAX : 값들 중에 최대 값을 반환한다
--      MAX(컬럼)
--MIN : 값들 중에 최소 값을 반환한다
--      MIN(컬럼)
--AVG : 평균 값을 계산한다
--      AVG(컬럼)
--COUNT : 반환된 행의 수를 계산한다
--       COUNT(컬럼|*)
--SUM  : 합계를 계산한다
--       SUM(컬럼)
--STDDEV : 표준편차를 계산한다
--       STDDEV(컬럼)
--VARIANCE : 분산을 계산한다
--       VARIANCE(컬럼)
--       
--b) null 값은 무시된다
--   반드시 단 하나의 값만을 반환한다
--   GROUP BY 설정 없이 일반 컬럼과 기술될 수 없다.
   
   
--1) 사원의 급여 평균을 검색한다.
SELECT AVG(sal) 평균급여, ROUND(AVG(sal)) 평균급여
FROM emp;

--2) 사원들에게 지급된 보너스 총합과 보너스 평균을 검색하세요
SELECT SUM(comm) 총액,
       ROUND(AVG(comm)) 평균,
       COUNT(comm) 수령인원,
       ROUND(AVG(NVL(comm,0))) 환산평균,
       COUNT(*) 전체인원
FROM emp;

SELECT COUNT(*)
FROM emp
WHERE comm IS NOT NULL;

SELECT COUNT(*)
FROM emp
WHERE comm IS NULL;

SELECT COUNT(*)
FROM emp;

--<그룹 함수와 GROUP BY 절>

--3) 평균 급여와 평균 연봉을 검색하세요
SELECT ROUND(AVG(sal)) 평균급여, 
       ROUND(AVG(sal*12+NVL(comm,0))) 평균연봉
FROM emp;

--4) 부서별 평균 급여와 평균 연봉을 검색하세요
SELECT dno, ROUND(AVG(sal)) 평균급여, 
       ROUND(AVG(sal*12+NVL(comm,0))) 평균연봉
FROM emp;

--카디널리티가 차이가 있어서 오류가 발생한다
--카디널리티(Cadinality) : 결과 행의 개수
--
--14개의 결과가 나온다
SELECT dno
FROM emp;

--1개의 결과가 나온다
SELECT ROUND(AVG(sal)) 평균급여, 
       ROUND(AVG(sal*12+NVL(comm,0))) 평균연봉
FROM emp;


--5) 부서별 평균 급여와 평균 연봉을 검색하세요
--부서별 : GROUP BY dno
--그룹함수와 함께 사용되는 일반 컬럼은
--반드시 GROUP BY 절에 사용되어야 한다
SELECT dno, ROUND(AVG(sal)) 평균급여, 
       ROUND(AVG(sal*12+NVL(comm,0))) 평균연봉
FROM emp
GROUP BY dno;

--6) 업무별 평균 급여와 평균 연봉을 검색하세요
--SELECT job 업무, ROUND(AVG(sal)) 평균급여, 
--       ROUND(AVG(sal*12+NVL(comm,0))) 평균연봉
--FROM emp;

SELECT job 업무, ROUND(AVG(sal)) 평균급여, 
       ROUND(AVG(sal*12+NVL(comm,0))) 평균연봉
FROM emp
GROUP BY job;

--7) 부서별 평균연봉을 구하세요(부서번호와 부서명까지 출력하세요)
select d.dno, dname, round(avg(sal*12*nvl(comm,0))) 평균연봉
from dept d, emp e
where d.dno=e.dno
group by d.dno, dname;

--8) 부서별로 급여 평균의 최대값과 최소값을 검색하세요
--select dno, max(avg(sal)) 최대평균, min(avg(sal)) 최소평균
--from emp
--group by dno; (카디널리티가 다르므로 오류)
   
select max(평균) 최대평균, min(평균) 최소평균 
from
  (select dno, avg(sal) 평균
  from emp
  group by dno);  
   
   
   