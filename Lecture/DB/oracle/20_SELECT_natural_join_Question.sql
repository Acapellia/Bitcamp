--1) 송강 교수가 강의하는 과목을 검색한다
select * from professor natural join course where pname='송강';

--2) 화학 관련 과목을 강의하는 교수의 명단을 검색한다
select pno 교수번호, pname 교수이름, cname 과목 from professor natural join course where cname like '%화학%';

--3) 학점이 2학점인 과목과 이를 강의하는 교수를 검색한다
select pno 교수번호, pname 교수이름, cname 과목 from professor natural join course where st_num=2;

--4) 화학과 교수가 강의하는 과목을 검색한다
select pno 교수번호, pname 교수이름, cname 과목 from professor natural join course where section = '화학';

--5) 화학과 1학년 학생의 기말고사 성적을 검색한다
select sno 학번, sname 이름, result 성적 from student natural join score where major='화학' and syear = 1 order by result desc;

--6) 일반화학 과목의 기말고사 점수를 검색한다
select sno 학번, sname 이름, result 성적 from student natural join score natural join course where cname = '일반화학';

--7) 화학과 1학년 학생의 일반화학 기말고사 점수를 검색한다
select sno 학번, sname 이름, result 성적 from student natural join score natural join course where cname = '일반화학' and major = '화학' and syear = 1;

--8) 화학과 1학년 학생이 수강하는 과목을 검색한다
select distinct cname 과목 from student natural join score natural join course where major = '화학' and syear = 1;