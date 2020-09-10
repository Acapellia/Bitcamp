--연결연산자의 사용
--select column || literal || ...
--from table


-- 1) 사원의 이름을 급여 또는 업무와 함께 검색
select ename ||' '|| sal "이름_급여" from emp;

select ename || '의 업무는' || job || '입니다.' 담당업무 from emp;

-- 2) 주의해야 할 연결연산자 -> 우선순위 생각
select ename || ' ' || (sal+100) "이름_급여+100" from emp;

--중복제거
--select [distinct | all] column, column, ... from tabel

--3) 업무 종류 검색
select  job 업무 from emp;
select distinct job 업무 from emp;

