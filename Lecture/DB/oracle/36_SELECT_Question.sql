--1) 화학과 학생과 평점이 동일한 학생들을 검색하세요
select *
from student 
where avr in (select distinct avr from student where major = '화학') and major != '화학';

--2) 화학과 교수와 부임일이 같은 직원을 검색하세요
select *
from emp
where hdate in (select distinct hiredate from professor where section = '화학');

--3) 화학과 학생과 같은 학년에서 평점이 동일한 학생들을 검색하세요
select *
from student 
where syear in (select syear from student where major = '화학')
and avr in (select avr from student where major = '화학');