--[데드락(Dead Lock)을 발생하고 결과를 확인한다 - Session 0]
--
--1) '관우' 학생 행에 독점 잠금이 발생
select sno, sname, major
from student
where sname in ('관우','장각');

update student 
set major = '경제'
where sname = '관우'; 

--3) Session 1에 의해 '장각' 학생 행이 독점 잠금에 걸려있는데 
--   현재 '관우' 학생 행도 Session 0에 의해 독점 잠금 상태이므로 wait 상태가 되고 Dead Lock 상태가 된다.
update student 
set major = '사회'
where sname = '장각'; 

--4)
--Session 0과 Session 1은 모두 wait 상태로 진입했으므로 그냥 두면 무한 wait 상태가 된다.
--즉 이것을 Dead Lock이라고 한다.
--오라클은 Dead Lock 상태를 감지하게 되면 Dead Lock을 발생시킨 Session의 마지막 명령을 보존하고
--(Session 0의 마지막 명령 - '장각'의 major를 '사회'로 변경 시도)
--Dead Lock을 유발하 상대 Session(Session 1)의 마지막 명령(Session 1의 마지막 명령 - '관우'의 major를 '경제'로 변경 시도)을 Rollback한다.