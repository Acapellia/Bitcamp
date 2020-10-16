--1) 일반 화학 과목을 수강하는 학생의 성적을 4.5만점 기준으로 수정하세요
update student
set avr = avr*4.5/4.0
where sno in (select st.sno from student st, score sr, course c where st.sno = sr.sno and sr.cno = c.cno and cname='일반화학');

select sno, sname, avr from student;
rollback;
select sno, sname, avr from student;

--2) 화학과 교수의 과목 중에 학점이 3학점 미만인 과목을 모두 3학점으로
--   수정한 다음 이를 확인하세요
select * from course;

update course
set st_num = 3
where cno in (select cno from course c natural join professor p where p.section = '화학');

select * from course;
rollback;

--3) 학생의 기말고사 성적을 모두 st_score 테이블에 저장하세요.
--  st_score테이블 구조는 직접 파악해 보세요
desc st_score;
insert /*+ append*/ into st_score nologging(sno,sname,major,syear,cno,cname,result)
select sno,sname,major,syear,cno,cname,result
from student s natural join score natural join course;
commit;
select * from st_score;
rollback;












