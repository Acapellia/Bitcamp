<�׷��Լ��� Having ��>
; �׷��Լ��� ������ ������ WHERE ���� ����� �� ����
  �׷��� HAVING ���� ����ؾ� �Ѵ�
  �Ϲ� �÷��� WHERE ���� ����Ѵ�

1) ���̺��� sal ���� ������ WHERE sal >= 3000�� ���� �����Ѵ�
 WHERE�� -> sal ����
SELECT sal
FROM emp
WHERE sal >= 3000;

--2) �μ��� ���
--GROUP BY -> ROUND(AVG(sal)) -> ROUND(AVG(sal)) >= 3000
SELECT ROUND(AVG(sal))
FROM emp
GROUP BY dno;

--3) ������ ���
SELECT ROUND(AVG(sal))
FROM emp
GROUP BY job;

--4) �μ��� �޿� ����� 3õ �̸��� �μ��� �μ���ȣ�� ��� �޿��� �˻��϶�
SELECT dno, ROUND(AVG(sal))
FROM emp
GROUP BY dno
HAVING AVG(sal) < 3000;

5) �μ��� �ο����� ����ϼ���(��, ������ ������ �ƴ� �ο���)
--select dno, count(*)
--from emp
--group by dno
--having job!='����';

select dno, count(*)
from emp
where job!='����'
group by dno;

6) �׷� ��� �÷��� �˻�
select dno, job, count(*) �ο���
from emp
group by dno, job
having job != '����';

