--1) 3학년 학생의 학과별 평점 평균과 분산 및 편차를 검색하세요
select major 학과, avg(avr) 평균, trunc(stddev(avr),3) 편차, trunc(variance(avr),3) 분산
from student
where syear=3
group by major;

--2) 화학과 학년별 평균 평점을 검색하세요
select syear 학년, avg(avr) 평균
from student
where major = '화학'
group by syear;

--3) 각 학생별 기말고사 평균을 검색하세요
select st.sno 학번, sname 이름, avg(result) 평균
from student st, score sr
where st.sno = sr.sno
group by st.sname, st.sno;

--4) 각 학과별 학생 수를 검색하세요
select major 학과, count(sno)
from student
group by major;

--5) 화학과와 생물학과 학생 4.5 환산 평점의 평균을 각각 검색하세요
select major 학과, trunc(avg(avr*4.5/4.0),3) 평균
from student
where major = '화학' or major = '생물'
group by major;

--6) 부임일이 10년 이상 된 직급별(정교수, 조교수, 부교수) 교수의 수를 검색하세요
select orders 직위, count(pno)
from professor
where trunc(sysdate - hiredate)>=3650
group by orders;

--7) 과목명에 화학이 포함된 과목의 학점수 총합을 검색하세요
select sum(st_num) 학점총합
from course
where cname like '%화학%';


--8) 화학과 학생들의 기말고사 성적을 성적순으로 검색하세요
select sno 학번, sname 이름, avr 성적
from student
where major = '화학'
order by avr;

--9) 학과별 기말고사 평균을 성적순으로 검색하세요
select major 학과, trunc(avg(avr),2)
from student
group by major
order by avg(avr);

