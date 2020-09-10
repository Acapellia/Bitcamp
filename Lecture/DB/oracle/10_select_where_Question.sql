--1) 화학과 학생을 검색하라
select * from student where major = '화학';
--2) 평점이 2.0 미만인 학생을 검색하라
select * from student where avr<2.0;
--3) 관우 학생의 평점을 검색하라
select sname 이름, avr 평점 from student where sname = '관우';
--4) 정교수 명단을 검색하라
select pname 교수이름 from professor where orders='정교수';
--5) 화학과 소속 교수의 명단을 검색하라
select pname 교수이름 from professor where section = '화학';
--6) 송강 교수의 정보를 검색하라
select * from professor where pname = '송강';
--7) 학년별로 화학과 학생의 성적을 검색하라
select syear 학년, sname 이름, major 학과, avr 성적 from student where major='화학'; 
--8) 2000년 이전에 부임한 교수의 정보를 부임일순으로 검색하라
select * from professor where hiredate<'20/12/31' order by hiredate ;
--9) 담당 교수가 없는 과목의 정보를 검색하라
select * from course where pno is null;