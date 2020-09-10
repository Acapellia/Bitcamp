--관계 연산자
--and, or, not

--1) 20번 부서 사원중에 급여가 2000 이상인 사원을 검색하라
select * from emp where dno='20' and sal >= 2000; 

--2) 20번 부서 사원중에 급여가 2000이상이고 모델링 업무를 담당하는 사원을 검색하라
select * from emp where dno='30' and job='개발' and sal >= 2000;

--3) 
select * from emp where dno='10' or (sal>1600 and comm>600);

select * from emp where (dno='10' or sal>1600) and comm>600;

--LIKE 연산자
--SELECT 컬럼, 컬럼, ...
--FROM 테이블
--WHERE 컬럼 LIKE '비교 문자열'
--ORDER BY 컬럼, 컬럼, ...;
--a) WHERE 절에 사용되는 문자 전용의 비교연산자이다
--b) 문자열의 일부만으로 검색하는 경우 사용된다
--c) 문자열에서 패턴을 찾아주는 연산자이다
--d) 두 개의 와일드 문자를 이용한다
--   '_' : 반드시 한 개의 문자를 대체한다
--   '%' : 문자열을 대체한다(문자가 없는 경우도 포함한다)
--e) 와일드 문자 자체를 검색하는 경우 ESCAPE 절을 이용한다
--
--예)
--'경%' - '경'으로 시작하는 모든 문자열
--        경, 경제, 경범죄, 경영학과, ...
--'%과' - '과'로 끝나는 모든 문자열
--        과, 다과, 화학과, 물리학과, ...
--'%김%' - '김'이라는 글자가 들어간 모든 문자열 
--        김, 김씨, 돌김, 되새김질, ...
--'화_' - '화'로 시작하는 두글자 단어
--        화학, 화약, 화상, ...
--'__화' - '화'로 끝나는 세글자 단어
--        무궁화, 해당화, 운동화, ...
--'_동_' - '동'이 가운데 들어간 세글자 단어
--        원동기, 전동차, ...
--'%이#%%' - ESCAPE '#'으로 지정한 경우, '이%'가 포함된 문자열
--'_#%_' - ESCAPE '#'으로 지정한 경우, '%'가 포함된 세글자 단어

--4) 김씨성을 가진 사원
SELECT *
FROM emp
WHERE ename LIKE '김%';

--5) 이름이 '하늘'인 사원
SELECT *
FROM emp
WHERE ename LIKE '%하늘';

--6) 성과 이름이 각각 한 글자인 사원
SELECT *
FROM emp
WHERE ename LIKE '__';


--7) 자주 실수하는 것
SELECT *
FROM emp
WHERE ename = '김%';

8) 이름에 '%'문자가 포함된 사원을 검색
SELECT eno, ename
FROM emp
WHERE ename LIKE '%#%%' ESCAPE '#';

























