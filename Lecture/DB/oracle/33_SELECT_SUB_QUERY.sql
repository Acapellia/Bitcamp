<���� ���� - ���� �� ���� ����>
a) ���� ������ ����
  a-1) ���� �� ��������
    ���� ������ �ϳ��� �÷����� �ϳ��� ���� �˻��Ѵ�.
  a-2) ���� �� ��������
    ���� ������ �ϳ��� �÷����� ���� ���� ���� �˻��Ѵ�.
  a-3) ���� �� ��������
    ���� ������ ���� ���� �÷��� �˻��Ѵ�.
    
--1) �迬�ƺ��� �޿��� ���� �޴� ����� �˻��ϼ���
select eno, ename
from emp
where sal > (select sal 
            from emp 
            where ename = '�迬��');

--2) '����'�� ������ ������ �л��� ������ �˻��ϼ���
select * 
from student 
where avr in (select avr
             from student
             where sname = '����');
            
3) �迬�ƿ� �μ��� �ٸ��� ������ ������ �ϴ� ����� ������ �˻��ϼ���
select *
from emp
where dno != (select dno
              from emp
              where ename = '�迬��')
and job = (select job 
           from emp
           where ename = '�迬��');
           
--4) �μ� �߿��� ���� �޿��� ���� �޴� �μ��� �˻��ϼ���
select dno, round(avg(sal)) 
from emp
group by dno
having avg(sal) = (select max(avg(sal))
                   from emp
                   group by dno);


--5) �μ� �� ���� �޿��� ���� �޴� �μ��� �˻��ϼ���
SELECT e.dno "�޿�MIN�μ�", dname, ROUND(AVG(sal))
FROM emp e, dept d
WHERE e.dno=d.dno
GROUP BY e.dno, dname
HAVING AVG(sal) = (SELECT MIN(AVG(sal))
                   FROM emp
                   GROUP BY dno);
                   
--6) �λ꿡�� �ٹ��ϴ� ����� ������ �˻��ϼ���

select *
from emp
where dno = (select dno from dept where loc='�λ�'); 