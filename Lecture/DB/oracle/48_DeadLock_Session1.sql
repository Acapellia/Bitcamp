--[�����(Dead Lock)�� �߻��ϰ� ����� Ȯ���Ѵ� - Session 1]

--2) '�尢' �л� �࿡ ���� ��� �߻�
--   '����' �л��� ������ �õ������� Session 0�� ���������� ���� wait ���·� �����ϰ� �ȴ�.

select sno, sname, major
from student
where sname in ('����','�尢');

update student
set major = '����'
where sname = '�尢';

update student
set major = '����'
where sname = '����';

