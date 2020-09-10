-- 1) 각 학생의 평점을 검색하라(별명을 사용)
select sname 이름, avr 평점 from student;
-- 2) 각 과목의 학점수를 검색하라(별명을 사용)
select cname 과목, st_num 학점 from course;
-- 3) 각 교수의 지위를 검색하라(별명을 사용)
select pname 교수이름, orders 지위 from professor;
-- 4) 급여를 10%인상했을 때 연간 지급되는 급여를 검색하라(별명을 사용)
select ename 이름, (sal+sal*0.1)*12 + nvl(comm,0) "연간 급여" from emp;
-- 5) 현재 학생의 평균 평점은 4.0만점이다. 이를 4.5만점으로 환산해서 검색하라(별명을 사용)
-- ? = val * 4.5 / 4.0
select sname 이름, avr "평점(4.0)", avr * 4.5 / 4.0 "평점(4.5)" from student;