--[데드락(Dead Lock)을 발생하고 결과를 확인한다 - Session 1]

--2) '장각' 학생 행에 독점 잠금 발생
--   '관우' 학생의 수정을 시도했으나 Session 0의 독점잠음에 의해 wait 상태로 진입하게 된다.

select sno, sname, major
from student
where sname in ('관우','장각');

update student
set major = '경제'
where sname = '장각';

update student
set major = '경제'
where sname = '관우';

