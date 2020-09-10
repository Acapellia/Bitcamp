--1) 각 과목의 과목명과 담당 교수의 교수명을 검색하라
select cname 과목, pname 담당교수 from professor p join course c on p.pno = c.pno;

--2) 화학과 학생의 기말고사 성적을 모두 검색하라
select sname 학생이름, cname 과목, result 성적 from student st join score sr on st.sno = sr.sno join course c on c.cno=sr.cno 
where major = '화학'; 

--3) 유기화학과목 수강생의 기말고사 시험점수를 검색하라
--4) 화학과 학생이 수강하는 과목을 담당하는 교수의 명단을 검색하라
--5) 모든 교수의 명단과 담당 과목을 검색한다
--6) 모든 교수의 명단과 담당 과목을 검색한다(단 모든 과목도 같이 검색한다)