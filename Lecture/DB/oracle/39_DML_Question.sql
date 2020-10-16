--1) 모든 학생의 성적을 4.5만점 기준으로 수정하세요
select sname, avr from student;
update student set avr=avr*4.5/4.0;
select sname, avr from student;
rollback;
select sname, avr from student;
--2) 모든 교수의 부임일자를 100일 앞으로 수정하세요
select pname, hiredate from professor;
update professor set hiredate = hiredate - 100;
select pname, hiredate from professor;
rollback;
--3) 화학과 2학년 학생의 정보를 삭제하세요
delete from student where major='화학' and syear = 2 ;
select * from student;
rollback;
--4) 조교수의 정보를 삭제하세요
delete from professor where orders='조교수';
select * from professor;
rollback;