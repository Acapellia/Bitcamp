--1) 송강 교수가 강의하는 과목을 검색한다
select cname from course c, professor p where c.pno = p.pno and pname='송강'; 

--2) 화학 관련 과목을 강의하는 교수의 명단을 검색한다
select pname 교수, cname 과목 from course c, professor p where c.pno = p.pno and cname like '%화학%';

--3) 학점이 2학점인 과목과 이를 강의하는 교수를 검색한다
select cname 과목, pname 교수 from course c, professor p where c.pno = p.pno and st_num = 2;

--4) 화학과 교수가 강의하는 과목을 검색한다
select cname 과목, pname 교수 from course c, professor p where c.pno = p.pno and section = '화학';

--5) 화학과 1학년 학생의 기말고사 성적을 검색한다
select sname 이름, syear 학년, major 학과, cname 과목, result 성적 
from student st, score sc, course c 
where (st.sno = sc.sno and sc.cno = c.cno) and major='화학' and syear=1;

--6) 일반화학 과목의 기말고사 점수를 검색한다
select sname 이름, syear 학년, major 학과, cname 과목, result 성적 
from student st, score sc, course c 
where (st.sno = sc.sno and sc.cno = c.cno) and cname = '일반화학';

--7) 화학과 1학년 학생의 일반화학 기말고사 점수를 검색한다
select sname 이름, syear 학년, major 학과, cname 과목, result 성적 
from student st, score sc, course c 
where (st.sno = sc.sno and sc.cno = c.cno) and (cname = '일반화학' and major = '화학' and syear = 1);

--8) 화학과 1학년 학생이 수강하는 과목을 검색한다
select distinct cname 과목 from course c, student st, score sc where (st.sno = sc.sno and sc.cno = c.cno) and (major = '화학' and syear = 1); 

--9) 유기화학 과목의 평가점수가 F인 학생의 명단을 검색한다
select sname 
from (select sname, result, cname from course c, student st, score sc where st.sno = sc.sno and sc.cno = c.cno) temp 
where (temp.result < 40) and cname = '유기화학'; 


select sno 학번, sname 이름, cname 과목, result from student natural join course natural join score natural join scgrade 
where result between loscore and hiscore and grade = 'F' and cname = '유기화학' order by result desc;





