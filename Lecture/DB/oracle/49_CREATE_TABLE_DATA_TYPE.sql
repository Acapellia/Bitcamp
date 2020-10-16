--[테이블 생성과 데이터 타입의 이해]
--; 테이블은 행(row), 열(column)으로 이루어진 자료구조이다.
--이것은 RDBMS이전부터 업무를 정리할 때 사용하던 양식이다.
--
--CREATE TABLE 테이블명(
--  컬럼 데이터타입 [DEFAULT default값] [컬럼 레벨 제약조건],
--  컬럼 데이터타입 [DEFAULT default값] [컬럼 레벨 제약조건],
--  ...
--  [테이블 레벨 제약조건],
--  ...
--);
--a) 데이터타입
-- - 컬럼에 입력될 데이터의 종류와 크기를 결정한다(자료형)
--b) DEFAULT
-- - 입력이 누락되었을 때 기본 입력 값을 정의한다
-- - 값을 지정하지 않으면 null 값이 저장된다
--c) 컬럼 레벨 제약 조건
-- - PK, FK, UK, CHECK, NOT NULL 등을 지정한다
--d) 테이블 레벨 제약 조건
-- - PK, FK, UK, CHECK 만 지정한다
-- - NOT NULL 은 정의할 수 없다.
-- 
-- 
--DROP TABLE 테이블명
-- [CASCADE CONSTRAINT];
--a) 테이블을 삭제한다
--b) CASCADE CONSTRAINT : 테이블이 다른 테이블로부터 참조되는 경우
--      해당 제약 조건을 먼저 삭제한 후 테이블을 삭제한다.
--      조심해야 한다. 이렇게 하다가 DB가 망가질 때가 많다.
--      잘 안쓰는 사람이 많다.
--      
--<데이터 타입>
--99% 사용하는 타입 3가지
--VARCHAR2 : 문자열 (80%이상)
--NUMBER   : 숫자
--DATE     : 날짜
-------------------------------------------------------
--VARCHAR2(n) : 가변 길이 문자열 (1 < n < 4000 byte)
--  VARCHAR2(1000) : "abcde" 5byte의 공간만 차지
--CHAR(n) : 고정 길이 문자열 (1 < n < 2000 byte)
--  CHAR(1000) : "abcde"를 저장해도 1000byte공간 차지
--NUMBER(n, p) : 숫자 타입, n은 전체 자리수이고 p는 소수점 이하 자리수
--              전체 자리수를 초과할 경우 입력 거부된다.
--              소수점 이하 자리수가 초과되면 반올림된다.
--              소수점 이하의 값이 없는 경우는 길이를 지정하지 않는 것이
--              좋다.
--DATE : 날짜 타입, 출력이나 입력 형식과 무관하게 YYYY/MM/DD:HH25:MI:SS
--       형태로 저장된다(기원전 4712년 1월 1일 ~ 서기 9999년 12월 31일)
--LONG : 2GB 까지 저장 가능한 가변길이 문자 타입, 단 조건 검색할 수 없다.
--       테이블에는 하나의 LONG 컬럼만 정의할 수 있다.
--CLOB : LONG를 개선한 타입, 최대 4G까지 저장하고, 한 테이블에 여러 컬럼을
--       정의할 수 있다. LONG 보다는 CLOB 를 사용한다
--BLOB : 4G 까지 저장 가능한 가변길이 이진 타입(파일 저장가능)
--ROW(n) : 가변길이 이진 타입 (n < 2000)
--BFILE : 외부 파일 저장을 하기 위한 이진 타입. 4G 이내 파일을 저장한다
--ROWID : ROWID 를 저장하기 위한 데이터 타입, 주로 PL-SQL 프로그래밍에서
--       사용되며 각 문자는 64진수로 encoding 되어 있다.
--       
--       
--1) 테이블을 생성해보자
--테이블 명 : board
--컬럼 구성 : no(게시물번호), name(작성자), sub(제목),
--           content(내용), hdate(입력일시)
           
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

--2) NUMBER 속성을 이해해 보자
CREATE TABLE t1(
  no NUMBER(4,2)
);

INSERT INTO t1 VALUES (12.12);
INSERT INTO t1 VALUES (1.789);
SELECT * FROM t1;
INSERT INTO t1 VALUES (123.1);

--3) VARCHAR2 에 대해 이해해보자

CREATE TABLE t2(
  name VARCHAR2(3)
);

INSERT INTO t2 VALUES ('AAA');
INSERT INTO t2 VALUES ('낙동강');
INSERT INTO t2 VALUES ('강');
SELECT * FROM t2;


--4) CHAR 와 VARCHAR2 의 차이를 이해해보자

CREATE TABLE comp(
  co1 CHAR(4),
  co2 VARCHAR2(4)
);

INSERT INTO comp VALUES('AA', 'AA');
INSERT INTO comp VALUES('AAAA', 'AAAA');
SELECT * FROM comp;

--일반적인 literal 상수 비교 검색은 문제가 없다
--그러나 컬럼간의 비교는 차이를 가져온다
SELECT * FROM comp WHERE co1='AA';
SELECT * FROM comp WHERE co2='AA';
SELECT * FROM comp WHERE co1=co2;

--5) Date 타입의 이해

create table hd(
  no number,
  hdate date
);

insert into hd values(1,sysdate);
select * from hd;
select * from hd where hdate = '2020/09/21';

select no, to_char(hdate,'YYYY-MM-DD:HH24:MM:SS') from hd;

--a) 구간 검색
select * from hd
where hdate between '2020/09/21' and '2020/09/22';

--b) date에서 like 문자열 연산은 date->문자열로 자동 변환하므로 데이터 테이블에서 검색 성능이 저하될 수 있다.
select * from hd
where to_char(hdate,'YYYY/MM/DD') like '2020/09/21%';

--c) date 형이 아니라 varchar2로 정의하는 것 - 한국

--d) date 입력 시 trunc(sysdate)를 사용하는 것
--시분초 00:00:00으로 결정된다. - 외국



































 
 
 
 
 
 
 
 
 
 