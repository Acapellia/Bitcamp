--1) �Ϲ� ȭ�� ������ �����ϴ� �л��� ������ 4.5���� �������� �����ϼ���
UPDATE student
 SET avr=avr*4.5/4.0
 WHERE sno IN (SELECT s.sno
               FROM student s, course c, score r
               WHERE s.sno=r.sno AND c.cno=r.cno
               AND cname='�Ϲ�ȭ��');

--2) ȭ�а� ������ ���� �߿� ������ 3���� �̸��� ������ ��� 3��������
--   ������ ���� �̸� Ȯ���ϼ���
UPDATE course
 SET st_num=3
 WHERE cno IN (SELECT cno
               FROM professor p, course c
               WHERE p.pno=c.pno
               AND section='ȭ��')
 AND st_num < 3;
 
SELECT section, cname, st_num
FROM professor p, course c
WHERE p.pno=c.pno
AND section='ȭ��';

--3) �л��� �⸻��� ������ ��� st_score ���̺� �����ϼ���.
--  st_score���̺� ������ ���� �ľ��� ������
INSERT /*+ APPEND */ INTO st_score NOLOGGING (sno, sname, major, syear, cno, cname, result)
 SELECT s.sno, sname, major, syear, c.cno, cname, result
 FROM student s, course c, score r
 WHERE s.sno=r.sno AND c.cno=r.cno;
 
COMMIT;













