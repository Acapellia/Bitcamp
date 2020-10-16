--[�����(Dead Lock)�� �߻��ϰ� ����� Ȯ���Ѵ� - Session 0]
--
--1) '����' �л� �࿡ ���� ����� �߻�
select sno, sname, major
from student
where sname in ('����','�尢');

update student 
set major = '����'
where sname = '����'; 

--3) Session 1�� ���� '�尢' �л� ���� ���� ��ݿ� �ɷ��ִµ� 
--   ���� '����' �л� �൵ Session 0�� ���� ���� ��� �����̹Ƿ� wait ���°� �ǰ� Dead Lock ���°� �ȴ�.
update student 
set major = '��ȸ'
where sname = '�尢'; 

--4)
--Session 0�� Session 1�� ��� wait ���·� ���������Ƿ� �׳� �θ� ���� wait ���°� �ȴ�.
--�� �̰��� Dead Lock�̶�� �Ѵ�.
--����Ŭ�� Dead Lock ���¸� �����ϰ� �Ǹ� Dead Lock�� �߻���Ų Session�� ������ ����� �����ϰ�
--(Session 0�� ������ ��� - '�尢'�� major�� '��ȸ'�� ���� �õ�)
--Dead Lock�� ������ ��� Session(Session 1)�� ������ ���(Session 1�� ������ ��� - '����'�� major�� '����'�� ���� �õ�)�� Rollback�Ѵ�.