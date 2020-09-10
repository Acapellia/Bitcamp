 
 --1)student 테이블 구조를 검색해라(김근동)
desc student;

-- 2)course 테이블 구조를 검색해라
desc course;

-- 3)professor 테이블 구조를 검색해라
desc PROFESSOR;

-- 4)score 테이블 구조를 검색해라
desc SCORE;

-- 5) 모든 학생의 정보를 검색해라
select * from student;

-- 7) 모든 과목의 정보를 검색해라
select * from course;

-- 8) 기말고사 시험점수를 검색해라
select * from st_score;

-- 9) 학생들의 학과와 학년을 검색해라
select sno, sname, major, syear from student;

-- 10) 각 과목의 이름과 학점을 검색해라
select cname, st_num from course;

-- 11) 모든 교수의 직위를 검색해라
select pno, pname, orders from professor;
 
 