--1) dept ���̺��� ��� �����͸� ������ ���� rollback�� commit�� �����ϰ� ����� Ȯ���ϼ���
select * from dept; 
delete from dept;
select * from dept; 
rollback;
select * from dept; 

--2) emp�� dept ���̺��� ��� �����͸� ���� �Ϸ��ϼ���
select * from emp;
select * from dept;
delete from emp;
delete from dept;
select * from emp;
select * from dept;
commit;

--3) emp ���̺� ������ �Է��ϼ���
insert into emp(eno,ename,job,mgr,hdate,sal,comm,dno)
values ('1001','�迬��','����',NULL,'1991-02-01',4500,520,10);
select * from emp;
rollback;
select * from emp;

--4) emp ���̺� �����͸� �Է��ϵ� �Ի��Ͽ� ��¥�� �ð��� �Է��ϼ���
select sysdate from dual;
--date�� ��¥ ������ ��ġ�ؾ� �Էµȴ�.
--insert into emp(eno,ename,hdate)
--values ('5001','ȫ�浿','199-01-03:07:15:25');

alter session set nls_date_format = 'YYYY-MM-DD:HH24:MT:SS';
insert into emp(eno,ename,hdate)
values ('5001','ȫ�浿','199-01-03:07:15:25');

--5) ��¥ ������ Ȯ���ϰ� to_date()�� ����ؼ� �Է��϶�
alter session set nls_date_format = 'YYYY-MM-DD';
select sysdate from dual;
alter session set nls_date_format = 'YY-MM-DD';
select sysdate from dual;
alter session set nls_date_format = 'YY/MM/DD';
select sysdate from dual;

insert into emp(eno, ename, hdate)
values ('5002','�峪��',to_date('1992-02-03:07:07:07','YYYY-MM-DD:HH24:MT:SS'));
select * from emp;
select eno, ename, to_char(hdate,'YYYY-MM-DD:HH24:MT:SS') from emp;

--6) ��¥�� ����Ǵ� ����Ʈ ���� Ȯ���Ѵ�.
alter session set nls_date_format='YYYY-MM-DD:HH24:MT::SS';
insert into emp(ebi,hdate) values ('1',to_date('2000','YYYY'));
insert into emp(ebi,hdate) values ('3',to_date('99','YY'));
insert into emp(ebi,hdate) values ('4',to_date('99','RR')); -- ����� �⵵
commit;
select * from emp;

--7) �迬���� �μ���ȣ�� 10������ �����ϰ� �޿��� 10�� �λ��ϼ���
select * from emp;
update emp set dno='10', sal = sal*1.1 where ename='�迬��';
select * from emp where ename='�迬��';
commit;


























