--1) 화학과를 제외하고 학생들의 평점 평균을 검색하세요
select major 학과, trunc(avg(avr),2) 평균
from student
--where major != '화학'
group by major
having major != '화학';

--2) 화학과를 제외한 각 학과별 평균 평점 중에 평점이 2.0 이상인 정보를 검색하세요
select major 학과, trunc(avg(avr),2) 평균
from student
--where major != '화학'
group by major
having major != '화학' and trunc(avg(avr),2) >= 2.0;

--3) 기말고사 평균이 60점 이상인 학생의 정보를 검색하세요(학번과 기말고사 평균)
select sno 학번, trunc(avg(result),2) 평균
from score
group by sno
having trunc(avg(result),2) >= 60;

--4) 강의 학점수가 3학점 이상인 교수의 정보를 검색하세요(교수번호, 이름과 담당 학점수)
select pno 교수, pname 교수이름,  cname 과목, sum(st_num) 담당학점
from professor natural join course
group by pno, pname, cname
having sum(st_num) >= 3;

--<부자의 조건>
--1) 항상 유쾌하도록 노력할 것(미소짓기 연습)
--   미소는 면접시 매우 유리함
--   (현재 상황에서 장점을 찾으려고 노력하는 모습)
--2) 개선하고 점검하는 사람이 될 것(반성)
--3) 일찍 일어날 것(성실)
--4) 건강할 것(관리)
--5) 항상 호기심을 가질 것(노력, 도전)