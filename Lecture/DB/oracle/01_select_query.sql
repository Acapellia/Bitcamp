/* Select ���� �̿��� ���̺� �˻�
 select [column, column | *] 
 from tabel
 where condition;
 */
 
 -- 1) ���̺� ���� �˻�
 desc emp;
 
 -- 2) ���� schema(user)�� ��� table �˻�
 select * from tab;
 
 -- 3) emp table�� ���� �˻�
 desc emp;
 
 -- 4) emp table�� ��� ���� �˻�
 select * from emp;
 
 -- 5) dept table�� ���� �˻�
 desc dept;
 
 -- 6) dept table�� ��� ���� �˻�
 select * from dept;
 
 -- 7) ����� ���, �̸�, ���� �˻�
 select eno, ename, job from emp;
 
 -- 8) ����� ���, �̸�, �޿� �˻�
 select eno, ename, sal from emp;
 
 -- 9) 2+3 ���
 select 2+3 from dual;

 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 