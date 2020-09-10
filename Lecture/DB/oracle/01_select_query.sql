/* Select 문을 이용한 테이블 검색
 select [column, column | *] 
 from tabel
 where condition;
 */
 
 -- 1) 테이블 구조 검색
 desc emp;
 
 -- 2) 현재 schema(user)의 모든 table 검색
 select * from tab;
 
 -- 3) emp table의 구조 검색
 desc emp;
 
 -- 4) emp table의 모든 내용 검색
 select * from emp;
 
 -- 5) dept table의 구조 검색
 desc dept;
 
 -- 6) dept table의 모든 내용 검색
 select * from dept;
 
 -- 7) 사원의 사번, 이름, 업무 검색
 select eno, ename, job from emp;
 
 -- 8) 사원의 사번, 이름, 급여 검색
 select eno, ename, sal from emp;
 
 -- 9) 2+3 계산
 select 2+3 from dual;

 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 