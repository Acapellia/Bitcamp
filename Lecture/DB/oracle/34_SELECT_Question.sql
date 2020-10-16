--<서브 쿼리를 사용하세요>
--1) 관우보다 평점이 우수한 학생의 학번과 이름을 검색하세요
select sno 학번, sname 이름 from student
where avr > (select avr from student where sname = '관우');

--2) 관우와 동일한 학년 학생 중에 평점이 사마감과 동일한 학생을 검색하세요
select * from student
where syear = (select syear from student where sname = '관우')
and avr = (select avr from student where sname = '사마감');

--3) 관우보다 일반 화학과목의 학점이 더 낮은 학생의 명단을 학점과 검색하세요
select sname , avr, result 
from (select sname, avr, result from student natural join course natural join score where cname='일반화학')
where result < (select result from student natural join course natural join score where sname='관우' and cname='일반화학')
order by sname;

--(select result from student natural join course natural join score where sname='관우' and cname='일반화학');
--(select * from student natural join course natural join score where cname='일반화학');

--4) 인원수가 가장 많은 학과를 검색하세요
select major 학과, count(sno) 인원수
from student
group by major
having count(sno) = (select max(count(sno)) from student group by major);

--5) 학생 중 기말고사 성적이 가장 낮은 학생의 정보를 검색하세요
select *
from student
where avr = (select min(avr) from student);







