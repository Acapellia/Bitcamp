--1) ��� �л��� ������ 4.5���� �������� �����ϼ���
UPDATE student SET avr=avr*4.5/4.0;

--2) ��� ������ �������ڸ� 100�� ������ �����ϼ���
UPDATE professor SET hiredate=hiredate-100;

--3) ȭ�а� 2�г� �л��� ������ �����ϼ���
DELETE FROM student
WHERE major='ȭ��' AND syear=2;

--4) �������� ������ �����ϼ���
DELETE FROM professor
WHERE orders='������';

