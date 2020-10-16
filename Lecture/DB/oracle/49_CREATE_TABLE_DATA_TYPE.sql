--[���̺� ������ ������ Ÿ���� ����]
--; ���̺��� ��(row), ��(column)���� �̷���� �ڷᱸ���̴�.
--�̰��� RDBMS�������� ������ ������ �� ����ϴ� ����̴�.
--
--CREATE TABLE ���̺��(
--  �÷� ������Ÿ�� [DEFAULT default��] [�÷� ���� ��������],
--  �÷� ������Ÿ�� [DEFAULT default��] [�÷� ���� ��������],
--  ...
--  [���̺� ���� ��������],
--  ...
--);
--a) ������Ÿ��
-- - �÷��� �Էµ� �������� ������ ũ�⸦ �����Ѵ�(�ڷ���)
--b) DEFAULT
-- - �Է��� �����Ǿ��� �� �⺻ �Է� ���� �����Ѵ�
-- - ���� �������� ������ null ���� ����ȴ�
--c) �÷� ���� ���� ����
-- - PK, FK, UK, CHECK, NOT NULL ���� �����Ѵ�
--d) ���̺� ���� ���� ����
-- - PK, FK, UK, CHECK �� �����Ѵ�
-- - NOT NULL �� ������ �� ����.
-- 
-- 
--DROP TABLE ���̺��
-- [CASCADE CONSTRAINT];
--a) ���̺��� �����Ѵ�
--b) CASCADE CONSTRAINT : ���̺��� �ٸ� ���̺�κ��� �����Ǵ� ���
--      �ش� ���� ������ ���� ������ �� ���̺��� �����Ѵ�.
--      �����ؾ� �Ѵ�. �̷��� �ϴٰ� DB�� ������ ���� ����.
--      �� �Ⱦ��� ����� ����.
--      
--<������ Ÿ��>
--99% ����ϴ� Ÿ�� 3����
--VARCHAR2 : ���ڿ� (80%�̻�)
--NUMBER   : ����
--DATE     : ��¥
-------------------------------------------------------
--VARCHAR2(n) : ���� ���� ���ڿ� (1 < n < 4000 byte)
--  VARCHAR2(1000) : "abcde" 5byte�� ������ ����
--CHAR(n) : ���� ���� ���ڿ� (1 < n < 2000 byte)
--  CHAR(1000) : "abcde"�� �����ص� 1000byte���� ����
--NUMBER(n, p) : ���� Ÿ��, n�� ��ü �ڸ����̰� p�� �Ҽ��� ���� �ڸ���
--              ��ü �ڸ����� �ʰ��� ��� �Է� �źεȴ�.
--              �Ҽ��� ���� �ڸ����� �ʰ��Ǹ� �ݿø��ȴ�.
--              �Ҽ��� ������ ���� ���� ���� ���̸� �������� �ʴ� ����
--              ����.
--DATE : ��¥ Ÿ��, ����̳� �Է� ���İ� �����ϰ� YYYY/MM/DD:HH25:MI:SS
--       ���·� ����ȴ�(����� 4712�� 1�� 1�� ~ ���� 9999�� 12�� 31��)
--LONG : 2GB ���� ���� ������ �������� ���� Ÿ��, �� ���� �˻��� �� ����.
--       ���̺��� �ϳ��� LONG �÷��� ������ �� �ִ�.
--CLOB : LONG�� ������ Ÿ��, �ִ� 4G���� �����ϰ�, �� ���̺� ���� �÷���
--       ������ �� �ִ�. LONG ���ٴ� CLOB �� ����Ѵ�
--BLOB : 4G ���� ���� ������ �������� ���� Ÿ��(���� ���尡��)
--ROW(n) : �������� ���� Ÿ�� (n < 2000)
--BFILE : �ܺ� ���� ������ �ϱ� ���� ���� Ÿ��. 4G �̳� ������ �����Ѵ�
--ROWID : ROWID �� �����ϱ� ���� ������ Ÿ��, �ַ� PL-SQL ���α׷��ֿ���
--       ���Ǹ� �� ���ڴ� 64������ encoding �Ǿ� �ִ�.
--       
--       
--1) ���̺��� �����غ���
--���̺� �� : board
--�÷� ���� : no(�Խù���ȣ), name(�ۼ���), sub(����),
--           content(����), hdate(�Է��Ͻ�)
           
CREATE TABLE board(
  no NUMBER,
  name VARCHAR2(50),
  sub VARCHAR2(100),
  content VARCHAR2(4000),
  hdate DATE DEFAULT sysdate
);

DESC board;

INSERT INTO board (no) VALUES (1);

SELECT * FROM board;

--2) NUMBER �Ӽ��� ������ ����
CREATE TABLE t1(
  no NUMBER(4,2)
);

INSERT INTO t1 VALUES (12.12);
INSERT INTO t1 VALUES (1.789);
SELECT * FROM t1;
INSERT INTO t1 VALUES (123.1);

--3) VARCHAR2 �� ���� �����غ���

CREATE TABLE t2(
  name VARCHAR2(3)
);

INSERT INTO t2 VALUES ('AAA');
INSERT INTO t2 VALUES ('������');
INSERT INTO t2 VALUES ('��');
SELECT * FROM t2;


--4) CHAR �� VARCHAR2 �� ���̸� �����غ���

CREATE TABLE comp(
  co1 CHAR(4),
  co2 VARCHAR2(4)
);

INSERT INTO comp VALUES('AA', 'AA');
INSERT INTO comp VALUES('AAAA', 'AAAA');
SELECT * FROM comp;

--�Ϲ����� literal ��� �� �˻��� ������ ����
--�׷��� �÷����� �񱳴� ���̸� �����´�
SELECT * FROM comp WHERE co1='AA';
SELECT * FROM comp WHERE co2='AA';
SELECT * FROM comp WHERE co1=co2;

--5) Date Ÿ���� ����

create table hd(
  no number,
  hdate date
);

insert into hd values(1,sysdate);
select * from hd;
select * from hd where hdate = '2020/09/21';

select no, to_char(hdate,'YYYY-MM-DD:HH24:MM:SS') from hd;

--a) ���� �˻�
select * from hd
where hdate between '2020/09/21' and '2020/09/22';

--b) date���� like ���ڿ� ������ date->���ڿ��� �ڵ� ��ȯ�ϹǷ� ������ ���̺��� �˻� ������ ���ϵ� �� �ִ�.
select * from hd
where to_char(hdate,'YYYY/MM/DD') like '2020/09/21%';

--c) date ���� �ƴ϶� varchar2�� �����ϴ� �� - �ѱ�

--d) date �Է� �� trunc(sysdate)�� ����ϴ� ��
--�ú��� 00:00:00���� �����ȴ�. - �ܱ�



































 
 
 
 
 
 
 
 
 
 