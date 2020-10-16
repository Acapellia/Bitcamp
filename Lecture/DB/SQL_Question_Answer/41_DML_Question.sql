--1) 일반 화학 과목을 수강하는 학생의 성적을 4.5만점 기준으로 수정하세요
UPDATE student
 SET avr=avr*4.5/4.0
 WHERE sno IN (SELECT s.sno
               FROM student s, course c, score r
               WHERE s.sno=r.sno AND c.cno=r.cno
               AND cname='일반화학');

--2) 화학과 교수의 과목 중에 학점이 3학점 미만인 과목을 모두 3학점으로
--   수정한 다음 이를 확인하세요
UPDATE course
 SET st_num=3
 WHERE cno IN (SELECT cno
               FROM professor p, course c
               WHERE p.pno=c.pno
               AND section='화학')
 AND st_num < 3;
 
SELECT section, cname, st_num
FROM professor p, course c
WHERE p.pno=c.pno
AND section='화학';

--3) 학생의 기말고사 성적을 모두 st_score 테이블에 저장하세요.
--  st_score테이블 구조는 직접 파악해 보세요
INSERT /*+ APPEND */ INTO st_score NOLOGGING (sno, sname, major, syear, cno, cname, result)
 SELECT s.sno, sname, major, syear, c.cno, cname, result
 FROM student s, course c, score r
 WHERE s.sno=r.sno AND c.cno=r.cno;
 
COMMIT;













