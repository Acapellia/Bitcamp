--1) 성적순으로 학생의 이름을 검색하라
select sname 이름, avr 성적 from student order by avr desc;
--2) 학과별 성적순으로 학생의 정보를 검색하라
select major 학과, sno 학번, sname 이름, avr 학점  from student order by major, avr desc;
--3) 학년별 성적순으로 학생의 정보를 검색하라
select syear 학년, sno 학번, sname 이름, major 학과, avr 학점  from student order by syear, avr desc;
--4) 학과별 학년별로 학생의 정보를 성적순으로 검색하라
select major 학과, syear 학년, sno 학번, sname 이름, avr 학점  from student order by major, syear, avr desc;
--5) 학점순으로 과목 이름을 검색하라
select cname 과목, st_num 학점 from course order by st_num desc;
--6) 각 학과별로 교수의 정보를 검색하라
select section 학과, pname 교수이름 from professor order by section;
--7) 지위별로 교수의 정보를 검색하라
select orders 지위, pname 교수이름, section 학과 from professor order by orders;
--8) 각 학과별로 교수의 정보를 부임일자 순으로 검색하라
select section 학과, pname 교수이름 ,orders 지위, hiredate "부임일자" from professor order by section, HIREDATE;